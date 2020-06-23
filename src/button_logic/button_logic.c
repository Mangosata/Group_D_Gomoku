#include "../../include/button_logic/button_logic.h"
#include "../../include/graphic/graphic.h"


extern int BOARD_ARRAY[ROW][COL];

/* @Description: Quit the game and close the window. */
void close_window(GtkWindow *window, cairo_surface_t *surface) {
    if (surface)
        cairo_surface_destroy(surface);

    gtk_window_close(window);
}

/* @Description: Clear the board and reset all the global variables to initial value. */
void reset(void) {
    extern cairo_surface_t *SURFACE;
    cairo_t *cr;
    cr = cairo_create(SURFACE);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);
    cairo_destroy(cr);

    if (WINNER_FLAG == 1 && START_PLAYER_GAME == -1) {
        START_PLAYER_GAME = 1;
        WINNER_FLAG = 0;
        PLAYER = 1;
        memset(BOARD_ARRAY, 0, sizeof(BOARD_ARRAY));
    }
}

/*
 * @Description: When clicked, start the player vs player game,
 *               player 1 (black) first,
 *               meanwhile, this button will be locked.
 */
void button_start_player(GtkWidget *widget, GtkLabel *label) {
    gtk_label_set_label(label, "Started Game!");
    if (START_PLAYER_GAME == 0) {
        START_PLAYER_GAME = 1;
    } else if (START_PLAYER_GAME == -1) {
        reset();
        gtk_widget_queue_draw(widget);
    }
}

/*
 * @Description: When clicked, the current player will lose,
 *               then display another player is winner message.
 */
void button_surrender(GtkWidget *window, GtkWidget *box,
                      GtkWidget *label1, GtkWidget *frame1, int argc, char *argv[]) {
    if (START_PLAYER_GAME == 1) {
        gtk_init(&argc, &argv);
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        g_signal_connect(G_OBJECT(window), "delete_event",
                         G_CALLBACK(gtk_main_quit), NULL);
        gtk_window_set_title(GTK_WINDOW(window), "Congratulations");
        gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
        gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
        gtk_container_set_border_width(GTK_CONTAINER(window), 50);

        box = gtk_vbox_new(FALSE, 0);
        gtk_container_add(GTK_CONTAINER(window), box);

        frame1 = gtk_frame_new("");
        if (PLAYER == 1) {
            label1 = gtk_label_new("Player 1 surrendered!\n Player 2 is winner!\n "
                                   "Click PvP button to play again!");
            START_PLAYER_GAME = -1;
            WINNER_FLAG = 1;
        } else {
            label1 = gtk_label_new("Player 2 surrendered!\n Player 1 is winner!\n "
                                   "Click PvP button to play again!");
            START_PLAYER_GAME = -1;
            WINNER_FLAG = 1;
        }

        gtk_container_add(GTK_CONTAINER(frame1), label1);

        gtk_label_set_justify(GTK_LABEL(label1), GTK_JUSTIFY_LEFT);
        gtk_box_pack_start(GTK_BOX(box), frame1, FALSE, FALSE, 5);

        gtk_widget_show_all(window);
        gtk_main();
    }
}

/*
 * @Description: When clicked, the game will be paused,
 *               no player can put the stone any more,
 *               and the pause button will change to resume button.
 */
void button_pause(GtkWidget *pause) {
    PAUSE_GAME = !PAUSE_GAME;
    if (PAUSE_GAME) {
        gtk_button_set_label(GTK_BUTTON(pause), "Resume");
    } else {
        gtk_button_set_label(GTK_BUTTON(pause), "Pause");
    }
}
