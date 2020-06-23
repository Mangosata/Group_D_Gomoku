#ifndef GROUP_D_GOMOKU_GRAPHIC_H
#define GROUP_D_GOMOKU_GRAPHIC_H

#include <gtk/gtk.h>
#include <math.h>

/* the board size is 19 * 19. */
#define ROW 19
#define COL 19

/*
 * Use some global variables to control game status.
 * START_PLAYER_GAME: Initialize the status of start,
 *                    0 means not start yet, -1 means one of players surrendered, 1 means game started.
 * PLAYER: Initialize the player, it should be player 1 (black) first.
 * PAUSE_GAME: Initialize the status of pause, 0 means not pause.
 * WINNER_FLAG: Initialize the winner status, 0 means no winner yet.
 * BOARD_ARRAY: Initialize the board array, 0 means no stone, 1 means player 1's stone, 2 means player 2's stone.
 */
extern int START_PLAYER_GAME;
extern int PLAYER;
extern int PAUSE_GAME;
extern int WINNER_FLAG;
extern int BOARD_ARRAY[ROW][COL];

/* Create a new surface of the appropriate size to store our stones. */
static gboolean configure_event_cb(GtkWidget *widget, GdkEventConfigure *event,
                                   gpointer data);

/* Draw the board with background color. */
static gboolean draw_board(GtkWidget *widget, cairo_t *cr,
                           cairo_t *cr1);

/* Draw the black stone and blue stone. */
static void draw_stone(GtkWidget *widget, gdouble x, gdouble y);

/* Handle button press events by clicking mouse. */
static gboolean button_press_event_cb(GtkWidget *widget, GdkEventButton *event,
                                      gpointer label);


/* Generate the graphic window. */
void activate(GtkApplication *app);

#endif //GROUP_D_GOMOKU_GRAPHIC_H
