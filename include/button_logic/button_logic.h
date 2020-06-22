#ifndef GROUP_D_GOMOKU_BUTTON_LOGIC_H
#define GROUP_D_GOMOKU_BUTTON_LOGIC_H

#include <gtk/gtk.h>

/* Quit the game and close the window */
void close_window(GtkWindow *window, cairo_surface_t *surface);

/* Start player vs player game */
void button_start_player();

/* The current player surrender*/
void button_surrender();

/* Pause the game */
void button_pause();

#endif //GROUP_D_GOMOKU_BUTTON_LOGIC_H
