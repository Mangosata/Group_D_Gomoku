#ifndef GROUP_D_GOMOKU_GRAPHIC_H
#define GROUP_D_GOMOKU_GRAPHIC_H

#include <gtk/gtk.h>
#include <math.h>

/* Initialize the surface to white */
static void clear_surface(void);

/* Create a new surface of the appropriate size to store our stones */
static gboolean configure_event_cb(GtkWidget *widget, GdkEventConfigure *event,
                                   gpointer data);

/* Draw the board with background color */
static gboolean draw_board(GtkWidget *widget, cairo_t *cr,
                           cairo_t *cr1, cairo_t *cr2, cairo_t *cr3, gpointer user_data);

/* Draw the black stone and blue stone */
static void draw_stone(GtkWidget *widget, gdouble x, gdouble y);

/* Handle button press events by clicking mouse */
static gboolean button_press_event_cb(GtkWidget *widget, GdkEventButton *event,
                                      gpointer data);


/* Generate the graphic window */
void activate(GtkApplication *app, gpointer user_data);

#endif //GROUP_D_GOMOKU_GRAPHIC_H
