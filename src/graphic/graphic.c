#include "../../include/graphic/graphic.h"
#include "../../include/button_logic/button_logic.h"
#include "../../include/game_logic/game_logic.h"

cairo_surface_t *SURFACE = NULL;

/*
 * Initialize the status of start, 0 means not start yet,
 * -1 means game over, 1 means game started.
 */
START_PLAYER_GAME = 0;

/* Initialize the status of pause, 0 means not pause. */
PAUSE_GAME = FALSE;

/* Initialize the winner status, 0 means no winner yet. */
WINNER_FLAG = 0;

/*
 * Initialize the board array, 0 means no stone,
 * 1 means player 1's stone, 2 means player 2's stone.
 */
BOARD_ARRAY[ROW][COL] = {0};

/* Initialize the player, it should be player 1 (black) first. */
PLAYER = 1;


/* Create a new surface of the appropriate size to store our scribbles. */
static gboolean configure_event_cb(GtkWidget *widget,
                                   GdkEventConfigure *event,
                                   gpointer data) {
    if (WINNER_FLAG == 0) {
        if (SURFACE) {
            cairo_surface_destroy(SURFACE);
        }
        SURFACE = gdk_window_create_similar_surface(gtk_widget_get_window(widget),
                                                    CAIRO_CONTENT_COLOR,
                                                    gtk_widget_get_allocated_width(widget),
                                                    gtk_widget_get_allocated_height(widget));
        reset();
    }
    return FALSE;
}


/*
 * @Description: Draw the board with background color.
 *               The board has a 18 * 18 size and background color is off-white.
 */
static gboolean draw_board(GtkWidget *widget, cairo_t *cr,
                           cairo_t *cr1) {

    cairo_set_source_surface(cr, SURFACE, 0, 0);
    cairo_paint(cr);

    cr = gdk_cairo_create(gtk_widget_get_window(widget));
    cr1 = gdk_cairo_create(gtk_widget_get_window(widget));
    cairo_set_source_rgba(cr1, 1, 0.9, 0.7, 0.3);
    cairo_rectangle(cr1, 0, 0, 900, 700);
    cairo_fill(cr1);

    cairo_set_source_rgb(cr, 0, 0, 0);

    int i, j;
    for (i = 0; i < 18; i++) {
        for (j = 0; j < 18; j++) {
            cairo_rectangle(cr, 100 + i * 25, 100 + j * 25, 25, 25);
        }
    }

    cairo_stroke_preserve(cr);
    cairo_destroy(cr);
    cairo_destroy(cr1);

    return FALSE;
}


/*
 * @Description: Draw the black stone and blue stone,
 *               player 1 is black, player 2 is blue.
 *               When finishing draw stone, exchange the value of PLAYER.
 *               For example, if the current player is 1,
 *               after drawing, change it to value 2.
 */
static void draw_stone(GtkWidget *widget,
                       gdouble x,
                       gdouble y) {

    cairo_t *cr;

    /*
     * When PLAYER = 1 means it is player 1's turn,
     * When PLAYER = 2 means it is player 2's turn.
     */
    if (PLAYER == 1) {
        cr = cairo_create(SURFACE);

        cairo_set_source_rgb(cr, 0, 0, 0);
        cairo_arc(cr, x, y, 10, 0, 2 * G_PI);
        cairo_fill(cr);
        cairo_destroy(cr);

        /* Now invalidate the affected region of the drawing area. */
        gtk_widget_queue_draw(widget);
        PLAYER = 2;
    } else if (PLAYER == 2) {
        cr = cairo_create(SURFACE);

        cairo_set_source_rgb(cr, 0, 0, 1);
        cairo_arc(cr, x, y, 10, 0, 2 * G_PI);
        cairo_fill(cr);
        cairo_destroy(cr);

        gtk_widget_queue_draw(widget);
        PLAYER = 1;
    }
}

/*
 * @Description: Handle button press (click on board) events by putting a stone,
 *               depending which player is playing now.
 *               If mouse clicks near the intersection,
 *               only when xflag and yflag both satisfy the requirements,
 *               put the stone on the board.
 */
static gboolean button_press_event_cb(GtkWidget *widget,
                                      GdkEventButton *event,
                                      gpointer label) {
    int xflag = 0, yflag = 0;

    /* paranoia check, in case we haven't gotten a configure event. */
    if (SURFACE == NULL)
        return FALSE;

    /* Make sure the game is start and no winner for now. */
    if (START_PLAYER_GAME == 1 && WINNER_FLAG == 0 && !PAUSE_GAME) {
        if (event->x >= 90 && event->x <= 560 &&
            (fmod(event->x, 25) <= 10 || fmod(event->x, 25) >= 15)) {
            xflag = 1;
        }
        if (event->y >= 90 && event->y <= 560 &&
            (fmod(event->y, 25) <= 10 || fmod(event->y, 25) >= 15)) {
            yflag = 1;
        }

        if (event->button == GDK_BUTTON_PRIMARY && xflag == 1 && yflag == 1) {
            /* Check if the stone is overlay */
            if (put_stone_logic(event->x, event->y, PLAYER) != 0) {
                draw_stone(widget, (int) (event->x / 25 + 0.5) * 25,
                           (int) (event->y / 25 + 0.5) * 25);

                /* Check if there is winner, if has a winner WINNER_FLAG will be 1. */
                WINNER_FLAG = check_winner(BOARD_ARRAY);
                if (WINNER_FLAG == 1) {
                    char *winner_info;
                    /* Outputs who is the winner. */
                    if (PLAYER == 1) {
                        winner_info = " Winner is Player 2\n Click PvP to play again!";
                        gtk_label_set_text(label, winner_info);
                    } else if (PLAYER == 2) {
                        winner_info = " Winner is Player 1\n Click PvP to play again!";
                        gtk_label_set_text(label, winner_info);
                    }
                    START_PLAYER_GAME = -1;
                }
            }
        }
    }

    return FALSE;
}

/*
 * @Description: Create a series of buttons,
 *               included Player vs Player, Surrender, Pause and Quit button.
 */
static GtkWidget *create_button(GtkWidget *button_box) {
    GtkWidget *player_button;
    GtkWidget *quit_button;
    GtkWidget *surrender;
    GtkWidget *pause;
    GtkWidget *label = gtk_label_new("Click PvP button to start!");

    gtk_box_pack_start(button_box, label, FALSE, FALSE, 0);
    player_button = gtk_button_new_with_label("Player vs Player");
    surrender = gtk_button_new_with_label("Surrender");
    pause = gtk_button_new_with_label("Pause");
    quit_button = gtk_button_new_with_label("Quit");
    gtk_box_pack_start(button_box, player_button, FALSE, FALSE, 0);
    gtk_box_pack_start(button_box, surrender, FALSE, FALSE, 0);
    gtk_box_pack_start(button_box, pause, FALSE, FALSE, 0);
    gtk_box_pack_start(button_box, quit_button, FALSE, FALSE, 0);

    /* Connect to respective function */
    g_signal_connect(player_button, "clicked", G_CALLBACK(button_start_player), (gpointer) label);
    g_signal_connect(surrender, "clicked", G_CALLBACK(button_surrender), (gpointer) label);
    g_signal_connect(pause, "clicked", G_CALLBACK(button_pause), NULL);
    g_signal_connect(quit_button, "clicked", G_CALLBACK(close_window), NULL);

    return label;
}


/*
 * @Description: Generate the graphic window.
 *               This function is the principle of GTK 3.0,
 *               it will be called in main.c.
 */
void activate(GtkApplication *app) {
    GtkWidget *window;
    GtkWidget *frame;
    GtkWidget *drawing_area;
    GtkWidget *box;
    GtkWidget *button_box;
    GtkWidget *label;

    /* Create two boxes for storing widgets in the window. */
    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    button_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Gomoku");
    g_signal_connect (window, "destroy", G_CALLBACK(close_window), NULL);

    gtk_container_set_border_width(GTK_CONTAINER (window), 50);
    gtk_container_add(GTK_CONTAINER (window), box);

    /* Board box. */
    frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME (frame), GTK_SHADOW_IN);
    gtk_box_pack_start(box, frame, TRUE, TRUE, 0);

    /* Button box. */
    gtk_box_pack_start(box, button_box, TRUE, TRUE, 0);
    label = create_button(button_box);
    drawing_area = gtk_drawing_area_new();

    /* Set a minimum size of board. */
    gtk_widget_set_size_request(drawing_area, 700, 700);
    gtk_container_add(GTK_CONTAINER (frame), drawing_area);

    /* Signals used to handle the backing surface. */
    g_signal_connect (drawing_area, "draw",
                      G_CALLBACK(draw_board), NULL);
    g_signal_connect (drawing_area, "configure-event",
                      G_CALLBACK(configure_event_cb), NULL);

    /* Event signals. */
    g_signal_connect (drawing_area, "button-press-event",
                      G_CALLBACK(button_press_event_cb), (gpointer) label);
    gtk_widget_set_events(drawing_area, gtk_widget_get_events(drawing_area)
                                        | GDK_BUTTON_PRESS_MASK);

    gtk_widget_show_all(window);
}
