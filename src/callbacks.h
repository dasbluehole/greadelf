#include <gtk/gtk.h>

void  on_statusbar_changed(GtkWidget *widget, gpointer statusbar);
void row_activated_cb( GtkTreeView *view, GtkTreePath *path, GtkTreeViewColumn *column );

void
on_start_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

gboolean
on_window1_delete_event               (GtkWidget       *widget,
                                        GdkEvent        *event,
                                        gpointer         user_data);

void
on_section_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_symbol_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_quit_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_filechooserbutton1_file_activated   (GtkFileChooser  *filechooser,
                                        gpointer         user_data);

void
on_filechooserbutton1_selection_changed
                                        (GtkFileChooser  *filechooser,
                                        gpointer         user_data);

void
on_readELF_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
