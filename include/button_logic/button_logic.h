#ifndef GROUP_D_GOMOKU_BUTTON_LOGIC_H
#define GROUP_D_GOMOKU_BUTTON_LOGIC_H

#include <gtk/gtk.h>

/* Quit the game and close the window. */
void close_window(GtkWindow *window, cairo_surface_t *surface);

/* Start player vs player game. */
void button_start_player(GtkWidget *widget, GtkLabel *label);

/* The current player surrender. */
void button_surrender(GtkWidget *window, GtkWidget *box,
                      GtkWidget *label1, GtkWidget *frame1, int argc, char *argv[]);

/* Pause the game */
void button_pause(GtkWidget *pause);

/* Reset all global variables and clean board. */
void reset(void);

#endif //GROUP_D_GOMOKU_BUTTON_LOGIC_H
