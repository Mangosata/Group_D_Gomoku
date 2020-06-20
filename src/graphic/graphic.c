#include "../../include/graphic/graphic.h"

static cairo_surface_t *surface = NULL;
int flag = 0;

static void clear_surface(void) {
    cairo_t *cr;
    cr = cairo_create(surface);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);
    cairo_destroy(cr);
}

/* Create a new surface of the appropriate size to store our scribbles */
static gboolean configure_event_cb(GtkWidget *widget,
                                   GdkEventConfigure *event,
                                   gpointer data) {
    if (surface) {
        cairo_surface_destroy(surface);
    }
    surface = gdk_window_create_similar_surface(gtk_widget_get_window(widget),
                                                CAIRO_CONTENT_COLOR,
                                                gtk_widget_get_allocated_width(widget),
                                                gtk_widget_get_allocated_height(widget));
    /* Initialize the surface to white */
    clear_surface();

    /* We've handled the configure event, no need for further processing. */
    return TRUE;
}

static gboolean draw_board(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    cr = gdk_cairo_create(gtk_widget_get_window(widget));

    cairo_set_source_rgb(cr, 0, 0, 0);

    int i, j;
    for (i = 0; i < 18; i++) {
        for (j = 0; j < 18; j++) {
            cairo_rectangle(cr, 100 + i * 25, 100 + j * 25, 25, 25);
        }
    }

    cairo_stroke_preserve(cr);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_destroy(cr);
    return FALSE;
}

/* Redraw the screen from the surface. Note that the ::draw
 * signal receives a ready-to-be-used cairo_t that is already
 * clipped to only draw the exposed areas of the widget
 */
static gboolean draw_cb(GtkWidget *widget,
                        cairo_t *cr,
                        gpointer data) {
    cairo_set_source_surface(cr, surface, 0, 0);
    cairo_paint(cr);

    return FALSE;
}

/* Draw a rectangle on the surface at the given position */
static void draw_stone(GtkWidget *widget,
                       gdouble x,
                       gdouble y) {

    cairo_t *cr;
    if (flag == 0) {
        cr = cairo_create(surface);

        cairo_set_source_rgb(cr, 0, 0, 0);
//    cairo_rectangle (cr, x - 3, y - 3, 6, 6);
        cairo_arc(cr, x - 3, y - 3, 10, 0, 2 * G_PI);
        cairo_fill(cr);

        cairo_destroy(cr);

        /* Now invalidate the affected region of the drawing area. */
        gtk_widget_queue_draw(widget);
        flag = 1;
    } else {
        cr = cairo_create(surface);

        cairo_set_source_rgb(cr, 1, 0, 0);
        cairo_arc(cr, x - 3, y - 3, 10, 0, 2 * G_PI);
        cairo_fill(cr);

        cairo_destroy(cr);

        gtk_widget_queue_draw(widget);
        flag = 0;
    }
}

/* Handle button press events by either drawing a rectangle
 * or clearing the surface, depending on which button was pressed.
 * The ::button-press signal handler receives a GdkEventButton
 * struct which contains this information.
 */
static gboolean button_press_event_cb(GtkWidget *widget,
                                      GdkEventButton *event,
                                      gpointer data) {
    int xflag = 0, yflag = 0;
//    printf("come into press\n");

    /* paranoia check, in case we haven't gotten a configure event */
    if (surface == NULL)
        return FALSE;
    if (event->x >= 90 && event->x <= 560 &&
        (fmod(event->x, 25) <= 10 || fmod(event->x, 25) >= 20)) {
        xflag = 1;
    }
    if (event->y >= 90 && event->y <= 560 &&
        (fmod(event->y, 25) <= 10 || fmod(event->y, 25) >= 20)) {
        yflag = 1;
    }

    if (event->button == GDK_BUTTON_PRIMARY && xflag == 1 && yflag == 1) {
        draw_stone(widget, (int) (event->x / 25 + 0.5) * 25, (int) (event->y / 25 + 0.5) * 25);
    } else if (event->button == GDK_BUTTON_SECONDARY) {
        clear_surface();
        gtk_widget_queue_draw(widget);
    }

    /* We've handled the event, stop processing */
    return TRUE;
}


static void close_window(void) {
    if (surface)
        cairo_surface_destroy(surface);

    gtk_main_quit();
}

void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *frame;
    GtkWidget *drawing_area;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Gomoku");

    g_signal_connect (window, "destroy", G_CALLBACK(close_window), NULL);

    gtk_container_set_border_width(GTK_CONTAINER (window), 50);

    frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME (frame), GTK_SHADOW_IN);
    gtk_container_add(GTK_CONTAINER (window), frame);

    drawing_area = gtk_drawing_area_new();
    /* set a minimum size */
    gtk_widget_set_size_request(drawing_area, 700, 700);

    gtk_container_add(GTK_CONTAINER (frame), drawing_area);

    /* Signals used to handle the backing surface */
    g_signal_connect (drawing_area, "draw",
                      G_CALLBACK(draw_cb), NULL);
    g_signal_connect (drawing_area, "draw",
                      G_CALLBACK(draw_board), NULL);
    g_signal_connect (drawing_area, "configure-event",
                      G_CALLBACK(configure_event_cb), NULL);

    /* Event signals */
    g_signal_connect (drawing_area, "button-press-event",
                      G_CALLBACK(button_press_event_cb), NULL);

    /* Ask to receive events the drawing area doesn't normally
     * subscribe to. In particular, we need to ask for the
     * button press and motion notify events that want to handle.
     */
    gtk_widget_set_events(drawing_area, gtk_widget_get_events(drawing_area)
                                        | GDK_BUTTON_PRESS_MASK);

    gtk_widget_show_all(window);
}