#ifndef GROUP_D_GOMOKU_GRAPHIC_H
#define GROUP_D_GOMOKU_GRAPHIC_H

#include <gtk/gtk.h>
#include <math.h>

static void clear_surface(void);

static gboolean configure_event_cb(GtkWidget *widget, GdkEventConfigure *event,
                                   gpointer data);

static gboolean draw_board(GtkWidget *widget, cairo_t *cr, gpointer user_data);

static gboolean draw_cb(GtkWidget *widget, cairo_t *cr, gpointer data);

static void draw_stone(GtkWidget *widget, gdouble x, gdouble y);

static gboolean button_press_event_cb(GtkWidget *widget, GdkEventButton *event,
                                      gpointer data);

static void close_window(void);

void activate(GtkApplication *app, gpointer user_data);


#endif //GROUP_D_GOMOKU_GRAPHIC_H
