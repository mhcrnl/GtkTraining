#include <gtk/gtk.h>

int main( int argc, char * argv[] ) {
    GtkWidget * window;
    GtkWidget * table;

    GtkWidget * label1;
    GtkWidget * label2;
    GtkWidget * label3;

    GtkWidget * entry1;
    GtkWidget * entry2;
    GtkWidget * entry3;

    gtk_init( &argc, &argv );

    window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
    gtk_window_set_position( GTK_WINDOW(window), GTK_WIN_POS_CENTER );
    gtk_window_set_title( GTK_WINDOW(window), "GtkEntry" );
    gtk_container_set_border_width( GTK_CONTAINER(window), 10 );

    table = gtk_grid_new();
    gtk_container_add( GTK_CONTAINER(window), table );
    gtk_grid_set_row_spacing( GTK_GRID(table), 10 );
    gtk_grid_set_column_spacing( GTK_GRID(table), 10 );

    label1 = gtk_label_new( "Name" );
    label2 = gtk_label_new( "Age" );
    label3 = gtk_label_new( "Occupation" );

    // gtk_label_set_justify has no effect on labels containing only a single line.
    // gtk_label_set_justify( GTK_LABEL(label1), GTK_JUSTIFY_LEFT );

    gtk_misc_set_alignment( GTK_MISC(label1), 0, 0 );
    gtk_misc_set_alignment( GTK_MISC(label2), 0, 0 );
    gtk_misc_set_alignment( GTK_MISC(label3), 0, 0 );

    gtk_grid_attach( GTK_GRID(table), label1, 0, 0, 1, 1 );
    gtk_grid_attach( GTK_GRID(table), label2, 0, 1, 1, 1 );
    gtk_grid_attach( GTK_GRID(table), label3, 0, 2, 1, 1 );

    entry1 = gtk_entry_new();
    entry2 = gtk_entry_new();
    entry3 = gtk_entry_new();

    gtk_grid_attach( GTK_GRID(table), entry1, 1, 0, 1, 1 );
    gtk_grid_attach( GTK_GRID(table), entry2, 1, 1, 1, 1 );
    gtk_grid_attach( GTK_GRID(table), entry3, 1, 2, 1, 1 );

    gtk_widget_show( table );

    gtk_widget_show( label1 );
    gtk_widget_show( label2 );
    gtk_widget_show( label3 );

    gtk_widget_show( entry1 );
    gtk_widget_show( entry2 );
    gtk_widget_show( entry3 );

    gtk_widget_show( window );

    g_signal_connect( window, "destroy",
        G_CALLBACK(gtk_main_quit), NULL );

    gtk_main();
    return 0;

}