#include "../../include/button_logic/button_logic.h"
#include "../../include/graphic/graphic.h"

/* @Description: Quit the game and close the window */
void close_window(GtkWindow *window, cairo_surface_t *surface) {
    if (surface)
        cairo_surface_destroy(surface);

    gtk_window_close(window);
}

/*
 * @Description: When clicked, start the player vs player game,
 * player 1 (black) first,
 * meanwhile, this button will be locked.
 */
void button_start_player(void) {
    start_player_game = 1;
}

/*
 * @Description: When clicked, the current player will lose,
 * then display another player is winner message.
 */
void button_surrender() {
    ;
}

/*
 * @Description: When clicked, the game will be paused,
 * no player can put the stone,
 * and the pause button will change to resume button.
 */
void button_pause() {
    ;
}