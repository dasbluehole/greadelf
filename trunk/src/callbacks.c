#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gprintf.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
gboolean disp_section = FALSE;
gboolean disp_symbol = FALSE;
gboolean eu_readelf = FALSE;

gint pass = 0, nextpass = 0, nextpass1 = 0, nextpass2 = 0;

void
on_readELF_toggled(GtkToggleButton *togglebutton,
		   gpointer user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
		eu_readelf = TRUE;
	else
		eu_readelf = FALSE;
}

void
on_section_toggled(GtkToggleButton *togglebutton,
		   gpointer user_data)
{
// The section should be displayed
	if (gtk_toggle_button_get_active(togglebutton))
		disp_section = TRUE;
	else
		disp_section = FALSE;
}


void
on_symbol_toggled(GtkToggleButton *togglebutton,
		  gpointer user_data)
{
//the symbols should be displayed
	if (gtk_toggle_button_get_active(togglebutton))
		disp_symbol = TRUE;
	else
		disp_symbol = FALSE;
}


void
on_start_clicked(GtkButton       *button,
		 gpointer user_data)
{
	//call the ELF file parser and send output to textview1
	GIOChannel *my_channel, *pass_channel;
	GIOStatus stat, statp;
	gsize length;
	int fd, fds, skipcnt = 0;
	FILE *fp, *fps;
	gchar *filename;
	gchar my_command[1024], pass_command[1024];
	gchar *my_params = NULL;

	gtk_widget_hide(hbox2);
	gtk_widget_hide(hbox3);
	gtk_widget_hide(hbox4);
	gtk_widget_hide(hbox5);
	gtk_widget_hide(hbox6);
	gtk_widget_hide(hbox7);
	gtk_widget_hide(hbox8);
	gtk_widget_hide(hbox9);
	gtk_widget_hide(hbox10);
	gtk_widget_hide(hbox11);
	gtk_widget_hide(hbox12);
	gtk_widget_hide(hbox13);

	filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooserbutton1));
	//Check for filename selected?
	if (filename == NULL)
	{
		GtkWidget *mdialog;
		mdialog = gtk_message_dialog_new(GTK_WINDOW(window1),
						 GTK_DIALOG_DESTROY_WITH_PARENT,
						 GTK_MESSAGE_ERROR,
						 GTK_BUTTONS_CLOSE,
						 NULL);
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(mdialog),
					      "Choose ELF file first.");
		gtk_dialog_run(GTK_DIALOG(mdialog));
		gtk_widget_destroy(mdialog);
		exit(0);
	}

	strcpy(pass_command, "file ");
	strcat(pass_command, filename);

	gchar *pass_out = (gchar *)malloc(sizeof(gchar) * 1024);
	fps = popen(pass_command, "r");
	if (fps == NULL)
	{
		printf("Error: Unable to spawn process\n");
		return;
	}

	//Check for options selection
	if (disp_symbol == FALSE && disp_section == FALSE && eu_readelf == FALSE )
	{
		GtkWidget *mdialog;
		mdialog = gtk_message_dialog_new(GTK_WINDOW(window1),
						 GTK_DIALOG_DESTROY_WITH_PARENT,
						 GTK_MESSAGE_ERROR,
						 GTK_BUTTONS_CLOSE,
						 NULL);
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(mdialog),
					      "Select either section or symbol or both from the checkboxes given on left side");
		gtk_dialog_run(GTK_DIALOG(mdialog));
		gtk_widget_destroy(mdialog);

	}
	if (disp_symbol == TRUE )
	{
		fds = fileno(fps);
		if (fds == -1) return;
		pass_channel = g_io_channel_unix_new(fds); //stdout
		if (pass_channel == NULL)
		{
			printf("Error: Unable to open IO channel\n");
			return;
		}

		while ((statp = g_io_channel_read_line(pass_channel, &pass_out, &length, NULL, NULL)) == G_IO_STATUS_NORMAL)
		{
			g_io_channel_shutdown(pass_channel, TRUE, NULL);
			g_io_channel_unref( pass_channel);
		}

		//In case user input .o file
		if (strstr(pass_out, "shared") == NULL)
			pass = 1;
		else
			pass = 2;
	}

	//Construct command
	if (eu_readelf == TRUE)
	{
		strcpy(my_command, "eu-readelf ");
		if (disp_section == TRUE)
			strcat(my_command, "-S ");
		if (disp_symbol == TRUE)
			strcat(my_command, "-s ");
		my_params = (gchar *)gtk_entry_get_text(GTK_ENTRY(param));
		if (my_params != NULL)
			strcat(my_command, my_params);
		strcat(my_command, "  ");
		strcat(my_command, filename);
	}
	else
	{
		//use my elf parser ;)
		//for the timebeing it is hard coded
		strcpy(my_command, "elfinfo ");
		strcat(my_command, filename);
		if (disp_section == TRUE)
			strcat(my_command, " section ");
		if ( disp_symbol == TRUE)
			strcat(my_command, " symbol ");
	}


	gchar *my_line = (gchar *)malloc(sizeof(gchar) * 1024);
	fp = popen(my_command, "r");
	if (fp == NULL)
	{
		printf("Error: Unable to spawn process\n");
		return;
	}

	fd = fileno(fp);
	if (fd == -1) return;
	my_channel = g_io_channel_unix_new(fd); //stdout
	if (my_channel == NULL)
	{
		printf("Error: Unable to open IO channel\n");
		return;
	}

	if (eu_readelf == TRUE)
	{
		if (disp_symbol == TRUE && pass <= 2)
		{
			gtk_widget_show(hbox2);
			gtk_widget_show(hbox3);
		}
		if (disp_symbol == TRUE && pass == 2)
		{
			gtk_widget_show(hbox4);
			gtk_widget_show(hbox5);
		}
		if (disp_section == TRUE)
		{
			gtk_widget_show(hbox6);
			gtk_widget_show(hbox7);
		}
	}
	else if (eu_readelf == FALSE)
	{
		if (disp_symbol == TRUE && pass <= 2)
		{
			gtk_widget_show(hbox8);
			gtk_widget_show(hbox9);
		}
		if (disp_symbol == TRUE && pass == 2)
		{
			gtk_widget_show(hbox10);
			gtk_widget_show(hbox11);
		}
		if (disp_section == TRUE)
		{
			gtk_widget_show(hbox12);
			gtk_widget_show(hbox13);
		}
	}
	while ((stat = g_io_channel_read_line(my_channel, &my_line, &length, NULL, NULL)) == G_IO_STATUS_NORMAL)
	{
		char *str1, *stre, *token, saveptr1[6][80], saveptr3[7][80], saveptr4[5][80], saveptr5[5][80], saveptr6[5][80];
		int saveptr12[2], saveptr13[4], flag = 0;

		//eu-readelf and disp_section
		if (disp_section == TRUE && eu_readelf == TRUE)
		{
			if (skipcnt == 0)
			{
				char *strs, *tokens, tokcnt = 1;
				my_line[strlen(my_line) - 2] = '\0';
				gtk_statusbar_push(GTK_STATUSBAR(statusbar3),  context_id3, my_line);
				strs = my_line;
				tokens = strtok(strs, " ");
				if (tokens == NULL)
					break;
				while (tokens != NULL)
				{
					tokens = strtok(NULL, " ");
					if (tokens == NULL)
						break;

					if (tokcnt == 2)
						nextpass = atoi(tokens);
					tokcnt++;
				}
				//     g_printf("section contains %d symbols\n",nextpass);
			}

			if (skipcnt >= 4 && skipcnt  < nextpass + 4)
			{
				str1 = my_line;
				token = strtok(str1, " ]["); //Nr
				strcpy(saveptr3[0], token);

				{
					token = strtok(NULL, " "); //Name
					if (strchr(token, '.') == NULL)
					{
						strcpy(saveptr3[1], " ");
						strcpy(saveptr3[2], token);
					}
					else
					{
						strcpy(saveptr3[1], token);
						token = strtok(NULL, " "); //Type
						strcpy(saveptr3[2], token);
					}

					token = strtok(NULL, " ");      //Addr
					strcpy(saveptr3[3], token);
					token = strtok(NULL, " ");      //Off
					strcpy(saveptr3[4], token);
					token = strtok(NULL, " ");      //Size
					strcpy(saveptr3[5], token);
					token = strtok(NULL, " ");      //ES
					saveptr13[0] = atoi(token);
					token = strtok(NULL, " ");      //Flags
					strcpy(saveptr3[6], token);

					if (sscanf(token, "%d", &flag) != 0) //It's an int.
					{
						strcpy(saveptr3[6], " ");
						saveptr13[1] = flag; //Lk
					}
					else
					{
						token = strtok(NULL, " "); //Lk
						saveptr13[1] = atoi(token);
					}

					token = strtok(NULL, " ");      //Inf
					saveptr13[2] = atoi(token);
					token = strtok(NULL, " ");      //Al
					saveptr13[3] = atoi(token);
					if (token == NULL)
						break;
				}

				gtk_list_store_append( store3, &iter3 );
				gtk_list_store_set( store3, &iter3, 0, saveptr3[0],
						    1, saveptr3[1],
						    2, saveptr3[2],
						    3, saveptr3[3],
						    4, saveptr3[4],
						    5, saveptr3[5],
						    6, saveptr13[0],
						    7, saveptr3[6],
						    8, saveptr13[1],
						    9, saveptr13[2],
						    10, saveptr13[3],
						    -1 );

			}
		}
		if ( (disp_symbol == TRUE || skipcnt >= nextpass + 6) && eu_readelf == TRUE)
		{
			if (disp_section == TRUE)
			{
				if (skipcnt == nextpass + 6)
				{
					char *strl, *tokenl, tokcnt = 1;
					my_line[strlen(my_line) - 2] = '\0';
					gtk_statusbar_push(GTK_STATUSBAR(statusbar1),  context_id1, my_line);
					strl = my_line;
					tokenl = strtok(strl, " ");
					if (tokenl == NULL)
						break;
					while (tokenl != NULL)
					{
						tokenl = strtok(NULL, " ");
						if (tokenl == NULL)
							break;

						if (tokcnt == 5 && pass == 1)
							nextpass1 = atoi(tokenl);
						if (tokcnt == 6 && pass == 2)
							nextpass1 = atoi(tokenl);
						tokcnt++;
					}
//           g_printf("symbol1 contains %d symbols\n",nextpass1);
				}

				if (skipcnt == nextpass + nextpass1 + 10)
				{
					char *strl, *tokenl, tokcnt = 1;
					my_line[strlen(my_line) - 2] = '\0';
					gtk_statusbar_push(GTK_STATUSBAR(statusbar2),  context_id2, my_line);
					strl = my_line;
					tokenl = strtok(strl, " ");
					if (tokenl == NULL)
						break;
					while (tokenl != NULL)
					{
						tokenl = strtok(NULL, " ");
						if (tokenl == NULL)
							break;

						if (tokcnt == 5)
							nextpass2 = atoi(tokenl);
						tokcnt++;
					}
//           g_printf("symbol2 contains %d symbols\n",nextpass2);
				}
			}
			else if (disp_symbol == TRUE )
			{
				if (skipcnt == 1)
				{
					char *strl, *tokenl, tokcnt = 1;
					my_line[strlen(my_line) - 2] = '\0';
					gtk_statusbar_push(GTK_STATUSBAR(statusbar1),  context_id1, my_line);
					strl = my_line;
					tokenl = strtok(strl, " ");
					if (tokenl == NULL)
						break;
					while (tokenl != NULL)
					{
						tokenl = strtok(NULL, " ");
						if (tokenl == NULL)
							break;

						if (tokcnt == 5 && pass == 1)
							nextpass1 = atoi(tokenl);
						if (tokcnt == 6 && pass == 2)
							nextpass1 = atoi(tokenl);

						tokcnt++;
					}
//           g_printf("symbol1 contains %d symbols\n",nextpass1);
				}

				if (skipcnt == nextpass1 + 5)
				{
					char *strl, *tokenl, tokcnt = 1;
					my_line[strlen(my_line) - 2] = '\0';
					gtk_statusbar_push(GTK_STATUSBAR(statusbar2),  context_id2, my_line);
					strl = my_line;
					tokenl = strtok(strl, " ");
					if (tokenl == NULL)
						break;
					while (tokenl != NULL)
					{
						tokenl = strtok(NULL, " ");
						if (tokenl == NULL)
							break;

						if (tokcnt == 5)
							nextpass2 = atoi(tokenl);
						tokcnt++;
					}
					//         g_printf("symbol2 contains %d symbols\n",nextpass2);
				}
			}

			str1 = my_line;
			token = strtok(str1, " ");
			if (token == NULL)
				break;
			saveptr12[0] = atoi(token);

			while (token != NULL)
			{
				token = strtok(NULL, " ");
				if (token == NULL)
					break;
				strcpy(saveptr1[0], token);
				token = strtok(NULL, " ");
				if (token == NULL)
					break;
				saveptr12[1] = atoi(token);
				token = strtok(NULL, " ");
				if (token == NULL)
					break;
				strcpy(saveptr1[1], token);
				token = strtok(NULL, " ");
				if (token == NULL)
					break;
				strcpy(saveptr1[2], token);
				token = strtok(NULL, " ");
				if (token == NULL)
					break;
				strcpy(saveptr1[3], token);
				token = strtok(NULL, " ");
				if (token == NULL)
					break;
				strcpy(saveptr1[4], token);
				token = strtok(NULL, "");
				if (token == NULL)
					break;
				strcpy(saveptr1[5], token);
			}

			if (disp_section == TRUE)
			{
				if (skipcnt > nextpass + nextpass1 + 12)
				{
					gtk_list_store_append( store2, &iter2 );
					gtk_list_store_set( store2, &iter2, 0, saveptr12[0],
							    1, saveptr1[0],
							    2, saveptr12[1],
							    3, saveptr1[1],
							    4, saveptr1[2],
							    5, saveptr1[3],
							    6, saveptr1[4],
							    7, saveptr1[5],
							    -1 );
				}
				if (skipcnt >= nextpass + 9 && skipcnt < (nextpass + nextpass1 + 9))
				{
					gtk_list_store_append( store1, &iter1 );
					gtk_list_store_set( store1, &iter1, 0, saveptr12[0],
							    1, saveptr1[0],
							    2, saveptr12[1],
							    3, saveptr1[1],
							    4, saveptr1[2],
							    5, saveptr1[3],
							    6, saveptr1[4],
							    7, saveptr1[5],
							    -1 );
				}

			}
			else if (disp_symbol == TRUE)
			{
				if (skipcnt > nextpass1 + 7)
				{
					gtk_list_store_append( store2, &iter2 );
					gtk_list_store_set( store2, &iter2, 0, saveptr12[0],
							    1, saveptr1[0],
							    2, saveptr12[1],
							    3, saveptr1[1],
							    4, saveptr1[2],
							    5, saveptr1[3],
							    6, saveptr1[4],
							    7, saveptr1[5],
							    -1 );
				}
				if (skipcnt > 3 && skipcnt < nextpass1 + 4)
				{
					gtk_list_store_append( store1, &iter1 );
					gtk_list_store_set( store1, &iter1, 0, saveptr12[0],
							    1, saveptr1[0],
							    2, saveptr12[1],
							    3, saveptr1[1],
							    4, saveptr1[2],
							    5, saveptr1[3],
							    6, saveptr1[4],
							    7, saveptr1[5],
							    -1 );
				}
			}
		}

		//elfinfo and disp_section
		if ( disp_section == TRUE && eu_readelf == FALSE )
		{
			if (skipcnt == 0)
			{
				char *strs, *tokens;
				my_line[strlen(my_line) - 2] = '\0';
				gtk_statusbar_push(GTK_STATUSBAR(statusbar6),  context_id6, my_line);
				strs = my_line;
				tokens = strtok(strs, " ");
				if (tokens == NULL)
					break;
				tokens = strtok(NULL, " ");
				if (tokens == NULL)
					break;
				tokens = strtok(NULL, " []");
				nextpass = atoi(tokens);
				if (tokens == NULL)
					break;
				//      g_printf("section contains %d symbols\n",nextpass);
			}
			if (skipcnt >= 1 && skipcnt <= nextpass)
			{
				stre = my_line;

				if (skipcnt == 1)
				{
					strcpy(saveptr6[0], "0");       //Nr
					strcpy(saveptr6[1], "");        //Name
					strcpy(saveptr6[2], "");        //flag
					strcpy(saveptr6[3], "NULL");    //type
					strcpy(saveptr6[4], "0");       //lk
				}
				else
				{
					token = strtok(stre, " []section");
					if (token == NULL)
						break;
					strcpy(saveptr6[0], token); //Nr

					while (token != NULL)
					{
						token = strtok(NULL, " ");
						if (token == NULL)
							break;
						strcpy(saveptr6[1], token);     //Name

						token = strtok(NULL, " ");      //flag
						if (strchr(token, '*') == NULL)
						{
							strcpy(saveptr6[2], " ");
							strcpy(saveptr6[3], token);
						}
						else
						{
							strcpy(saveptr6[2], token);
							token = strtok(NULL, " "); //Type
							strcpy(saveptr6[3], token);
						}

						token = strtok(NULL, " ");
						if (token == NULL)
							break;
						token = strtok(NULL, " ");
						if (token == NULL)
							break;
						token = strtok(NULL, " ");
						if (token == NULL)
							break;
						strcpy(saveptr6[4], token);
						token = strtok(NULL, " ");
						if (token == NULL)
							break;
					}
				}

				gtk_list_store_append( store6, &iter6 );
				gtk_list_store_set( store6, &iter6, 0, saveptr6[0],
						    1, saveptr6[1],
						    2, saveptr6[2],
						    3, saveptr6[3],
						    4, saveptr6[4],
						    -1 );
			}
		}
		if ( disp_symbol == TRUE && eu_readelf == FALSE )
		{
			int tmp1;

			if (disp_section == TRUE )
				tmp1 = 3;
			else
			{
				tmp1 = 1;
				nextpass = 0;
			}

			if (skipcnt == nextpass + tmp1)
			{
				char *strl, *tokenl;
				my_line[strlen(my_line) - 2] = '\0';
				gtk_statusbar_push(GTK_STATUSBAR(statusbar4),  context_id4, my_line);
				strl = my_line;
				tokenl = strtok(strl, " section[]");
				if (tokenl == NULL)
					break;
				tokenl = strtok(NULL, " ");
				if (tokenl == NULL)
					break;
				tokenl = strtok(NULL, " []");
				nextpass1 = atoi(tokenl);
				if (tokenl == NULL)
					break;
				//   g_printf("section contains %d symbols\n",nextpass1);
			}
			if (skipcnt > tmp1 + nextpass && skipcnt <= nextpass + tmp1 + nextpass1)
			{
				stre = my_line;
				if (skipcnt == tmp1 + nextpass + 1 )
				{
					token = strtok(stre, " []");
					if (token == NULL)
						break;
					strcpy(saveptr4[0], token); //Nr
					token = strtok(NULL, " ");
					if (token == NULL)
						break;
					strcpy(saveptr4[1], "");        //Name
					strcpy(saveptr4[2], token);     //Bind
					token = strtok(NULL, " ");
					if (token == NULL)
						break;
					strcpy(saveptr4[3], token); //Type
					token = strtok(NULL, " ");
					if (token == NULL)
						break;
					strcpy(saveptr4[4], token); //Ndx
				}
				else
				{
					token = strtok(stre, " []");
					if (token == NULL)
						break;
					strcpy(saveptr4[0], token); //Nr
					{
						token = strtok(NULL, " ");
						if (token == NULL)
							break;
						strcpy(saveptr4[1], token); //Name
						token = strtok(NULL, " ");
						if (token == NULL)
							break;
						strcpy(saveptr4[2], token); //Bind
						token = strtok(NULL, " ");
						if (token == NULL)
							break;
						strcpy(saveptr4[3], token); //Type
						token = strtok(NULL, " ");
						if (token == NULL)
							break;
						strcpy(saveptr4[4], token); //Ndx
					}
				}
				gtk_list_store_append( store4, &iter4 );
				gtk_list_store_set( store4, &iter4, 0, saveptr4[0],
						    1, saveptr4[1],
						    2, saveptr4[2],
						    3, saveptr4[3],
						    4, saveptr4[4],
						    -1 );

			}
			if (skipcnt == nextpass + tmp1 + nextpass1 + 2)
			{
				char *strl, *tokenl;
				my_line[strlen(my_line) - 2] = '\0';
				gtk_statusbar_push(GTK_STATUSBAR(statusbar5),  context_id5, my_line);
				strl = my_line;
				tokenl = strtok(strl, " section[]");
				if (tokenl == NULL)
					break;
				tokenl = strtok(NULL, " ");
				if (tokenl == NULL)
					break;
				tokenl = strtok(NULL, " []");
				nextpass2 = atoi(tokenl);
				if (tokenl == NULL)
					break;
				//    g_printf("section contains %d symbols\n",nextpass2);
			}

			if (skipcnt > tmp1 + nextpass + nextpass1 + 2 && skipcnt <= nextpass2 + tmp1 + nextpass1 + nextpass + 3)
			{
				stre = my_line;
				if (skipcnt == tmp1 + nextpass + nextpass1 + 3)
				{
					token = strtok(stre, " []");
					if (token == NULL)
						break;
					strcpy(saveptr5[0], token);     //Nr
					strcpy(saveptr5[1], "");        //Name
					token = strtok(NULL, " ");
					if (token == NULL)
						break;
					strcpy(saveptr5[2], token); //Bind
					token = strtok(NULL, " ");
					if (token == NULL)
						break;
					strcpy(saveptr5[3], token); //Type
					token = strtok(NULL, " ");
					if (token == NULL)
						break;
					strcpy(saveptr5[4], token); //Ndx
				}
				else
				{
					token = strtok(stre, " []");
					if (token == NULL)
						break;
					strcpy(saveptr5[0], token); //Nr
					token = strtok(NULL, " ");
					if (token == NULL)
						break;
					strcpy(saveptr5[1], token); //Name
					token = strtok(NULL, " ");
					if (token == NULL)
						break;
					strcpy(saveptr5[2], token); //Bind
					token = strtok(NULL, " ");
					if (token == NULL)
						break;
					strcpy(saveptr5[3], token); //Type
					if (strcmp(saveptr5[1], "LOCAL") == 0 && strcmp(saveptr5[2], "SECTION") == 0)
					{
						strcpy(saveptr5[4], "");                //Ndx
						strcpy(saveptr5[3], saveptr5[2]);       //Bind
						strcpy(saveptr5[2], saveptr5[1]);       //Type
						strcpy(saveptr5[1], "");                //Name
					}
					else
					{
						token = strtok(NULL, " ");
						if (token == NULL)
							break;
						strcpy(saveptr5[4], token); //Ndx
					}
				}

				gtk_list_store_append( store5, &iter5 );
				gtk_list_store_set( store5, &iter5, 0, saveptr5[0],
						    1, saveptr5[1],
						    2, saveptr5[2],
						    3, saveptr5[3],
						    4, saveptr5[4],
						    -1 );

			}
		}
		skipcnt++;
	}
	g_io_channel_shutdown(my_channel, TRUE, NULL);
	g_io_channel_unref( my_channel);
}


gboolean
on_window1_delete_event(GtkWidget       *widget,
			GdkEvent        *event,
			gpointer user_data)
{
	printf("Good Bye...!\n");
	gtk_main_quit();
	return FALSE;
}

void
on_quit_clicked(GtkButton       *button,
		gpointer user_data)
{
	gtk_main_quit();
}

void
on_filechooserbutton1_selection_changed
(GtkFileChooser  *filechooser,
 gpointer user_data)
{
	char *filename;

	filename = malloc(sizeof(char) * strlen(gtk_file_chooser_get_filename(filechooser) + 1));
	filename = gtk_file_chooser_get_filename(filechooser);
/*	gtk_text_buffer_set_text((GtkTextBuffer *)user_data," \0",-1);
        gtk_text_buffer_insert_at_cursor((GtkTextBuffer*)user_data,filename,-1);
 */
}


