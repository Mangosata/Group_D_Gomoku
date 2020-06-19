#include <stdio.h>
#include <gtk/gtk.h>

static void print_hello() {
    printf("hello");
}

/*
 * Callback function for drawing background
 */
static GdkPixbuf *background;
static gint draw_cb (GtkWidget *widget, cairo_t *cr, gpointer data) {
    gdk_cairo_set_source_pixbuf(cr, background, 0, 0);
    cairo_paint(cr);

    return TRUE;
}

static void activate (GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *button_player;
    GtkWidget *button_com;
    GtkWidget *button_quit;
    GtkWidget *button_box = gtk_fixed_new();

    /*
     * Create the board picture
     */
    GtkWidget *board_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(board_area, 700, 600);
    gtk_fixed_put(GTK_FIXED(button_box), board_area, 0, 0);
    background = gdk_pixbuf_new_from_file("./board1.JPG", NULL);
    g_signal_connect(board_area, "draw", G_CALLBACK(draw_cb), NULL);


    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Gomoku");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    gtk_container_add(GTK_CONTAINER(window), button_box);

    /*
    * Create stone picture
    */
    GdkPixbuf *stone = gdk_pixbuf_new_from_file("./black.JPG", NULL);
    GdkPixbuf *black_pic = gdk_pixbuf_scale_simple(stone, 20, 20, GDK_INTERP_BILINEAR);
    GtkWidget *black_stone = gtk_image_new_from_pixbuf(black_pic);
    g_object_unref(stone);
    g_object_unref(black_pic);
    gtk_fixed_put(GTK_FIXED(button_box), black_stone, 100, 100);


    button_player = gtk_button_new_with_label("Player Vs Player");
    button_com = gtk_button_new_with_label("Player Vs Com");
    button_quit = gtk_button_new_with_label("Quit");
    g_signal_connect(button_player, "clicked", G_CALLBACK(print_hello), NULL);
    g_signal_connect(button_com, "clicked", G_CALLBACK(print_hello), NULL);
    g_signal_connect_swapped(button_quit, "clicked", G_CALLBACK(gtk_widget_destroy), window);

    gtk_fixed_put(GTK_FIXED(button_box), button_player, 600, 10);
    gtk_fixed_put(GTK_FIXED(button_box), button_com, 600, 50);
    gtk_fixed_put(GTK_FIXED(button_box), button_quit, 600, 90);


    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int app_status;

    app = gtk_application_new("org.gomoku.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    app_status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);
    return app_status;

//    GtkBuilder *builder = gtk_builder_new();
//    if( !gtk_builder_add_from_file(builder, "./start.glade", NULL) ){
//        printf("cannot load file!");
//    }
//
//    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
//    gtk_builder_connect_signals(builder, NULL);
//    gtk_widget_show(window);
}
