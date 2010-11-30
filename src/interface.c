/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window1 (void)
{

  tooltips = gtk_tooltips_new ();

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1), _("Read ELF GUI"));

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (window1), vbox1);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox1, TRUE, TRUE, 0);

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (hbox1), fixed1);

  hseparator1 = gtk_hseparator_new ();
  gtk_widget_show (hseparator1);
  gtk_fixed_put (GTK_FIXED (fixed1), hseparator1, 0, 116);
  gtk_widget_set_size_request (hseparator1, 818, 5);

/*******************Symobl1**************************/
  hbox2 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox2, TRUE, TRUE, 0);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow1);
  gtk_container_add (GTK_CONTAINER (hbox2), scrolledwindow1);
  gtk_widget_set_size_request (scrolledwindow1, 800, 175);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  treeview1 = gtk_tree_view_new();
  gtk_container_add( GTK_CONTAINER( scrolledwindow1 ), treeview1 );

  hbox3 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox3, TRUE, TRUE, 0);

  statusbar1 = gtk_statusbar_new();
  gtk_container_add (GTK_CONTAINER (hbox3), statusbar1);
  gtk_widget_show (statusbar1);
  context_id1 = gtk_statusbar_get_context_id(
                          GTK_STATUSBAR (statusbar1), "Statusbar example");

  /* Create model for treeview1 and ppulate it */
    store1 = gtk_list_store_new( 8, G_TYPE_INT,    /* 0: Num */
                                   G_TYPE_STRING,    /* 1: value - string */
                                   G_TYPE_INT,    /* 2: size - double */
                                   G_TYPE_STRING,    /* 3: type - string */
                                   G_TYPE_STRING,    /* 4: bind - double */
                                   G_TYPE_STRING,    /* 5: vis - string */
                                   G_TYPE_STRING,     /* 6: Ndx - double */
                                   G_TYPE_STRING );    /* 7: Name - double */

    gtk_tree_view_set_model( GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL(store1));
    /* Populate treeview1 with columns */
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
                "Num", renderer,
                "text", 0,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview1 ), column );

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
                "Value", renderer,
                "text", 1,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview1 ), column );

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
                "Size", renderer,
                "text", 2,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview1 ), column );

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
                "Type", renderer,
                "text", 3,
                NULL );
   gtk_tree_view_append_column( GTK_TREE_VIEW( treeview1 ), column );

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
                "Bind", renderer,
                "text", 4,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview1 ), column );

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
                "Vis", renderer,
                "text", 5,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview1 ), column );

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
                "Ndx", renderer,
                "text", 6,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview1 ), column );

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
                "Name", renderer,
                "text", 7,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview1 ), column );
    gtk_tree_view_column_set_sort_column_id( column,7);
    gtk_tree_view_column_set_sort_indicator( column,TRUE);
    gtk_widget_show_all( treeview1 );    

/*******************Symobl2**************************/
  hbox4 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox4, TRUE, TRUE, 0);

  scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow2);
  gtk_container_add (GTK_CONTAINER (hbox4), scrolledwindow2);
  gtk_widget_set_size_request (scrolledwindow2, 800, 175);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow2), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  treeview2 = gtk_tree_view_new();
  gtk_container_add( GTK_CONTAINER( scrolledwindow2 ), treeview2 );

  hbox5 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox5, TRUE, TRUE, 0);

  statusbar2 = gtk_statusbar_new();
  gtk_container_add (GTK_CONTAINER (hbox5), statusbar2);
  gtk_widget_show (statusbar2);
  context_id2 = gtk_statusbar_get_context_id(
                          GTK_STATUSBAR (statusbar2), "Statusbar example");

 /* Create model for treeview2 and ppulate it */
    store2 = gtk_list_store_new( 8, G_TYPE_INT,    /* 0: Num */
                                   G_TYPE_STRING,    /* 1: value - string */
                                   G_TYPE_INT,    /* 2: size - double */
                                   G_TYPE_STRING,    /* 3: type - string */
                                   G_TYPE_STRING,    /* 4: bind - double */
                                   G_TYPE_STRING,    /* 5: vis - string */
                                   G_TYPE_STRING,     /* 6: Ndx - double */
                                   G_TYPE_STRING );    /* 7: Name - double */

    gtk_tree_view_set_model( GTK_TREE_VIEW(treeview2),GTK_TREE_MODEL(store2));
    /* Populate treeview2 with columns */
    renderer2 = gtk_cell_renderer_text_new();
    column2 = gtk_tree_view_column_new_with_attributes(
                "Num", renderer2,
                "text", 0,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview2 ), column2 );

    renderer2 = gtk_cell_renderer_text_new();
    column2 = gtk_tree_view_column_new_with_attributes(
                "Value", renderer2,
                "text", 1,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview2 ), column2 );

    renderer2 = gtk_cell_renderer_text_new();
    column2 = gtk_tree_view_column_new_with_attributes(
                "Size", renderer2,
                "text", 2,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview2 ), column2 );

    renderer2 = gtk_cell_renderer_text_new();
    column2 = gtk_tree_view_column_new_with_attributes(
                "Type", renderer2,
                "text", 3,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview2 ), column2 );

    renderer2 = gtk_cell_renderer_text_new();
    column2 = gtk_tree_view_column_new_with_attributes(
                "Bind", renderer2,
                "text", 4,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview2 ), column2 );

    renderer2 = gtk_cell_renderer_text_new();
    column2 = gtk_tree_view_column_new_with_attributes(
                "Vis", renderer2,
                "text", 5,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview2 ), column2 );

    renderer2 = gtk_cell_renderer_text_new();
    column2 = gtk_tree_view_column_new_with_attributes(
                "Ndx", renderer2,
                "text", 6,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview2 ), column2 );

    renderer2 = gtk_cell_renderer_text_new();
    column2 = gtk_tree_view_column_new_with_attributes(
                "Name", renderer2,
                "text", 7,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview2 ), column2 );
    gtk_tree_view_column_set_sort_column_id( column2,7);
    gtk_tree_view_column_set_sort_indicator( column2,TRUE);
    gtk_widget_show_all( treeview2 );

/*******************Section**************************/
  hbox6 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox6, TRUE, TRUE, 0);

  scrolledwindow3 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow3);
  gtk_container_add (GTK_CONTAINER (hbox6), scrolledwindow3);
  gtk_widget_set_size_request (scrolledwindow3, 800, 175);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow3), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  treeview3 = gtk_tree_view_new();
  gtk_container_add( GTK_CONTAINER( scrolledwindow3 ), treeview3 );

  hbox7 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox7, TRUE, TRUE, 0);

  statusbar3 = gtk_statusbar_new();
  gtk_container_add (GTK_CONTAINER (hbox7), statusbar3);
  gtk_widget_show (statusbar3);
  context_id3 = gtk_statusbar_get_context_id(
                          GTK_STATUSBAR (statusbar3), "Statusbar example");

 /* Create model for treeview2 and ppulate it */
    store3 = gtk_list_store_new( 11, G_TYPE_STRING,    /* 0: [Nr] */
                                   G_TYPE_STRING,    /* 1: name - string */
                                   G_TYPE_STRING,    /* 2: type - string */
                                   G_TYPE_STRING,    /* 3: addr - string */
                                   G_TYPE_STRING,    /* 4: off - string */
                                   G_TYPE_STRING,    /* 5: size - string */
                                   G_TYPE_INT,     /* 6: Es - int */
                                   G_TYPE_STRING,    /* 7: flags - string */
                                   G_TYPE_INT,     /* 8: lk - int */
                                   G_TYPE_INT,     /* 9: inf - int */
                                   G_TYPE_INT);     /* 10: al - int */

    gtk_tree_view_set_model( GTK_TREE_VIEW(treeview3),GTK_TREE_MODEL(store3));
    /* Populate treeview3 with columns */
    renderer3 = gtk_cell_renderer_text_new();
    column3 = gtk_tree_view_column_new_with_attributes(
                "Nr", renderer3,
                "text", 0,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), column3 );

    renderer3 = gtk_cell_renderer_text_new();
    columnid3 = gtk_tree_view_column_new_with_attributes(
                "Name", renderer3,
                "text", 1,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), columnid3 );

    renderer3 = gtk_cell_renderer_text_new();
    column3 = gtk_tree_view_column_new_with_attributes(
                "Type", renderer3,
                "text", 2,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), column3 );

    renderer3 = gtk_cell_renderer_text_new();
    column3 = gtk_tree_view_column_new_with_attributes(
                "Addr", renderer3,
                "text", 3,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), column3 );

    renderer3 = gtk_cell_renderer_text_new();
    column3 = gtk_tree_view_column_new_with_attributes(
                "Off", renderer3,
                "text", 4,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), column3 );

    renderer3 = gtk_cell_renderer_text_new();
    column3 = gtk_tree_view_column_new_with_attributes(
                "Size", renderer3,
                "text", 5,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), column3 );

    renderer3 = gtk_cell_renderer_text_new();
    column3 = gtk_tree_view_column_new_with_attributes(
                "ES", renderer3,
                "text", 6,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), column3 );

    renderer3 = gtk_cell_renderer_text_new();
    column3 = gtk_tree_view_column_new_with_attributes(
                "Flags", renderer3,
                "text", 7,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), column3 );

    renderer3 = gtk_cell_renderer_text_new();
    column3 = gtk_tree_view_column_new_with_attributes(
                "Lk", renderer3,
                "text", 8,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), column3 );

    renderer3 = gtk_cell_renderer_text_new();
    column3 = gtk_tree_view_column_new_with_attributes(
                "Inf", renderer3,
                "text", 9,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), column3 );

    renderer3 = gtk_cell_renderer_text_new();
    column3 = gtk_tree_view_column_new_with_attributes(
                "Al", renderer3,
                "text", 10,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview3 ), column3 );

    gtk_tree_view_column_set_sort_column_id( columnid3,1);
    gtk_tree_view_column_set_sort_indicator( columnid3,TRUE);
    gtk_widget_show_all( treeview3 );

/*******************Symbol1+elfinfo**************************/
  hbox8 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox8, TRUE, TRUE, 0);

  scrolledwindow4 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow4);
  gtk_container_add (GTK_CONTAINER (hbox8), scrolledwindow4);
  gtk_widget_set_size_request (scrolledwindow4, 800, 175);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow4), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  treeview4 = gtk_tree_view_new();
  gtk_container_add( GTK_CONTAINER( scrolledwindow4 ), treeview4 );

  hbox9 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox9, TRUE, TRUE, 0);

  statusbar4 = gtk_statusbar_new();
  gtk_container_add (GTK_CONTAINER (hbox9), statusbar4);
  gtk_widget_show (statusbar4);
  context_id4 = gtk_statusbar_get_context_id(
                          GTK_STATUSBAR (statusbar4), "Statusbar example");

  /* Create model for treeview4 and ppulate it */
    store4 = gtk_list_store_new( 5, G_TYPE_STRING,    /* 0: Num */
                                   G_TYPE_STRING,    /* 1: Name - string */
                                   G_TYPE_STRING,    /* 2: bind - string */
                                   G_TYPE_STRING,    /* 3: type - string */
                                   G_TYPE_STRING);     /* 4: Ndx - string */

    gtk_tree_view_set_model( GTK_TREE_VIEW( treeview4 ),GTK_TREE_MODEL( store4 ) );
    /* Populate treeview4 with columns */
    renderer4 = gtk_cell_renderer_text_new();
    column4 = gtk_tree_view_column_new_with_attributes(
                "Num", renderer4,
                "text", 0,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview4 ), column4 );

    renderer4 = gtk_cell_renderer_text_new();
    columnid4 = gtk_tree_view_column_new_with_attributes(
                "Name", renderer4,
                "text", 1,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview4 ), columnid4 );

    renderer4 = gtk_cell_renderer_text_new();
    column4 = gtk_tree_view_column_new_with_attributes(
                "Bind", renderer4,
                "text", 2,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview4 ), column4 );

    renderer4 = gtk_cell_renderer_text_new();
    column4 = gtk_tree_view_column_new_with_attributes(
                "Type", renderer4,
                "text", 3,
                NULL );
   gtk_tree_view_append_column( GTK_TREE_VIEW( treeview4 ), column4 );

    renderer4 = gtk_cell_renderer_text_new();
    column4 = gtk_tree_view_column_new_with_attributes(
                "Ndx", renderer4,
                "text", 4,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview4 ), column4 );

    gtk_tree_view_column_set_sort_column_id( columnid4,1);
    gtk_tree_view_column_set_sort_indicator( columnid4,TRUE);
    gtk_widget_show_all( treeview4 );    

/*******************Symobl2+elfinfo**************************/
  hbox10 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox10, TRUE, TRUE, 0);

  scrolledwindow5 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow5);
  gtk_container_add (GTK_CONTAINER (hbox10), scrolledwindow5);
  gtk_widget_set_size_request (scrolledwindow5, 800, 175);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow5), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  treeview5 = gtk_tree_view_new();
  gtk_container_add( GTK_CONTAINER( scrolledwindow5 ), treeview5 );

  hbox11 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox11, TRUE, TRUE, 0);

  statusbar5 = gtk_statusbar_new();
  gtk_container_add (GTK_CONTAINER (hbox11), statusbar5);
  gtk_widget_show (statusbar5);
  context_id5 = gtk_statusbar_get_context_id(
                          GTK_STATUSBAR (statusbar5), "Statusbar example");

 /* Create model for treeview5 and ppulate it */
    store5 = gtk_list_store_new( 5, G_TYPE_STRING,    /* 0: Num */
                                   G_TYPE_STRING,    /* 1: Name - string */
                                   G_TYPE_STRING,    /* 2: bind - string */
                                   G_TYPE_STRING,    /* 3: type - string */
                                   G_TYPE_STRING);     /* 4: Ndx - string */

    gtk_tree_view_set_model( GTK_TREE_VIEW( treeview5 ),
                             GTK_TREE_MODEL( store5 ) );
    /* Populate treeview5 with columns */
    renderer5 = gtk_cell_renderer_text_new();
    column5 = gtk_tree_view_column_new_with_attributes(
                "Num", renderer5,
                "text", 0,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview5 ), column5 );

    renderer5 = gtk_cell_renderer_text_new();
    columnid5 = gtk_tree_view_column_new_with_attributes(
                "Name", renderer5,
                "text", 1,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview5 ), columnid5 );

    renderer5 = gtk_cell_renderer_text_new();
    column5 = gtk_tree_view_column_new_with_attributes(
                "Bind", renderer5,
                "text", 2,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview5 ), column5 );

    renderer5 = gtk_cell_renderer_text_new();
    column5 = gtk_tree_view_column_new_with_attributes(
                "Type", renderer5,
                "text", 3,
                NULL );
   gtk_tree_view_append_column( GTK_TREE_VIEW( treeview5 ), column5 );

    renderer5 = gtk_cell_renderer_text_new();
    column5 = gtk_tree_view_column_new_with_attributes(
                "Ndx", renderer5,
                "text", 4,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview5 ), column5 );

    gtk_tree_view_column_set_sort_column_id( columnid5,1);
    gtk_tree_view_column_set_sort_indicator( columnid5,TRUE);
    gtk_widget_show_all( treeview5 );

/*******************Section+elfinfo**************************/
  hbox12 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox12, TRUE, TRUE, 0);

  scrolledwindow6 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow6);
  gtk_container_add (GTK_CONTAINER (hbox12), scrolledwindow6);
  gtk_widget_set_size_request (scrolledwindow6, 800, 175);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow6), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  treeview6 = gtk_tree_view_new();
  gtk_container_add( GTK_CONTAINER( scrolledwindow6 ), treeview6 );

 hbox13 = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox13, TRUE, TRUE, 0);

  statusbar6 = gtk_statusbar_new();
  gtk_container_add (GTK_CONTAINER (hbox13), statusbar6);
  gtk_widget_show (statusbar6);
  context_id6 = gtk_statusbar_get_context_id(
                          GTK_STATUSBAR (statusbar6), "Statusbar example");

 /* Create model for treeview2 and ppulate it */
    store6 = gtk_list_store_new( 5, G_TYPE_STRING,    /* 0: [Nr] */
                                   G_TYPE_STRING,    /* 1: name - string */
                                   G_TYPE_STRING,    /* 2: flags - string */
                                   G_TYPE_STRING,    /* 3: type - string */
                                   G_TYPE_STRING);    /* 4: lk - int */

    gtk_tree_view_set_model( GTK_TREE_VIEW( treeview6 ),
                             GTK_TREE_MODEL( store6 ) );
    /* Populate treeview6 with columns */
    renderer6 = gtk_cell_renderer_text_new();
    column6 = gtk_tree_view_column_new_with_attributes(
                "Nr", renderer6,
                "text", 0,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview6 ), column6 );

    renderer6 = gtk_cell_renderer_text_new();
    columnid6 = gtk_tree_view_column_new_with_attributes(
                "Name", renderer6,
                "text", 1,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview6 ), columnid6 );

    renderer6 = gtk_cell_renderer_text_new();
    column6 = gtk_tree_view_column_new_with_attributes(
                "Flags", renderer6,
                "text", 2,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview6 ), column6 );

    renderer6 = gtk_cell_renderer_text_new();
    column6 = gtk_tree_view_column_new_with_attributes(
                "Type", renderer6,
                "text", 3,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview6 ), column6 );
   
    renderer6 = gtk_cell_renderer_text_new();
    column6 = gtk_tree_view_column_new_with_attributes(
                "Lk", renderer6,
                "text", 4,
                NULL );
    gtk_tree_view_append_column( GTK_TREE_VIEW( treeview6 ), column6 );

    gtk_tree_view_column_set_sort_column_id( columnid6,1);
    gtk_tree_view_column_set_sort_indicator( columnid6,TRUE);
    gtk_widget_show_all( treeview6 );

  section = gtk_check_button_new_with_mnemonic (_("Section"));
  gtk_widget_show (section);
  gtk_fixed_put (GTK_FIXED (fixed1), section, 9, 72);
  gtk_widget_set_size_request (section, 136, 30);
  gtk_tooltips_set_tip (tooltips, section, _("select to display section"), NULL);

  symbol = gtk_check_button_new_with_mnemonic (_("Symbol"));
  gtk_widget_show (symbol);
  gtk_fixed_put (GTK_FIXED (fixed1), symbol, 144, 72);
  gtk_widget_set_size_request (symbol, 95, 30);
  gtk_tooltips_set_tip (tooltips, symbol, _("select to display symbols"), NULL);

  readELF = gtk_check_button_new_with_mnemonic (_("eu-readelf"));
  gtk_widget_show (readELF);
  gtk_fixed_put (GTK_FIXED (fixed1), readELF, 272, 75);
  gtk_widget_set_size_request (readELF, 120, 24);
  gtk_tooltips_set_tip (tooltips, readELF, _("select to use eu-readelf"), NULL);

  start = gtk_button_new_with_mnemonic (_("Start"));
  gtk_widget_show (start);
  gtk_fixed_put (GTK_FIXED (fixed1), start, 592, 72);
  gtk_widget_set_size_request (start, 100, 33);
  gtk_tooltips_set_tip (tooltips, start, _("click to start processing"), NULL);

  quit = gtk_button_new_with_mnemonic (_("Quit"));
  gtk_widget_show (quit);
  gtk_fixed_put (GTK_FIXED (fixed1), quit, 696, 72);
  gtk_widget_set_size_request (quit, 100, 32);
  gtk_tooltips_set_tip (tooltips, quit, _("Quit"), NULL);

  filechooserbutton1 = gtk_file_chooser_button_new (_("Select A File"), GTK_FILE_CHOOSER_ACTION_OPEN);
  gtk_widget_show (filechooserbutton1);
  gtk_fixed_put (GTK_FIXED (fixed1), filechooserbutton1, 8, 32);
  gtk_widget_set_size_request (filechooserbutton1, 370, 34);

  param = gtk_entry_new ();
  gtk_widget_show (param);
  gtk_fixed_put (GTK_FIXED (fixed1), param, 504, 32);
  gtk_widget_set_size_request (param, 296, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (param), 8226);

  parameters = gtk_label_new (_("Parameters"));
  gtk_widget_show (parameters);
  gtk_fixed_put (GTK_FIXED (fixed1), parameters, 392, 40);
  gtk_widget_set_size_request (parameters, 112, 24);

  g_signal_connect ((gpointer) window1, "delete_event",
                    G_CALLBACK (on_window1_delete_event),
                    NULL);
  g_signal_connect ((gpointer) section, "toggled",
                    G_CALLBACK (on_section_toggled),
                    NULL);
  g_signal_connect ((gpointer) symbol, "toggled",
                    G_CALLBACK (on_symbol_toggled),
                    NULL);
  g_signal_connect ((gpointer) readELF, "toggled",
                    G_CALLBACK (on_readELF_toggled),
                    NULL);
  g_signal_connect ((gpointer) start, "clicked",
                    G_CALLBACK (on_start_clicked),
                    NULL);
  g_signal_connect ((gpointer) quit, "clicked",
                    G_CALLBACK (on_quit_clicked),
                    NULL);
  g_signal_connect ((gpointer) filechooserbutton1, "selection_changed",
                    G_CALLBACK (on_filechooserbutton1_selection_changed),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (window1, hseparator1, "hseparator1");
  GLADE_HOOKUP_OBJECT (window1, scrolledwindow1, "scrolledwindow1");
  GLADE_HOOKUP_OBJECT (window1, textview1, "textview1");
  GLADE_HOOKUP_OBJECT (window1, section, "section");
  GLADE_HOOKUP_OBJECT (window1, symbol, "symbol");
  GLADE_HOOKUP_OBJECT (window1, readELF, "readELF");
  GLADE_HOOKUP_OBJECT (window1, start, "start");
  GLADE_HOOKUP_OBJECT (window1, quit, "quit");
  GLADE_HOOKUP_OBJECT (window1, filechooserbutton1, "filechooserbutton1");
  GLADE_HOOKUP_OBJECT (window1, param, "param");
  GLADE_HOOKUP_OBJECT (window1, parameters, "parameters");
  GLADE_HOOKUP_OBJECT_NO_REF (window1, tooltips, "tooltips");

  return window1;
}
