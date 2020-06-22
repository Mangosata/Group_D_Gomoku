#include "../../include/graphic/graphic.h"

static cairo_surface_t *surface = NULL;

/* Initialize the status of start, 0 means not start yet */
START_PLAYER_GAME = 0;
extern int BOARD_ARRAY[ROW][COL];
int winner_flag = 0;

/* Initialize the player, at the beginning, it should be player 1 (black). */
int player = 0;

/* @Description: Initialize the surface to white */
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


/*
 * @Description: Draw the board with background color.
 * The board has a 18 * 18 size and background color is off-white.
 */
static gboolean draw_board(GtkWidget *widget, cairo_t *cr,
                           cairo_t *cr1, cairo_t *cr2, cairo_t *cr3,
                           gpointer user_data) {
    cairo_set_source_surface(cr, surface, 0, 0);
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
 * player 1 is black,
 * player 2 is blue.
 */
static void draw_stone(GtkWidget *widget,
                       gdouble x,
                       gdouble y) {

    cairo_t *cr;

    /*
     * When player = 0 means it is player 1's turn,
     * When player = 1 means it is player 2's turn.
     */
    if (player == 0) {
        cr = cairo_create(surface);

        cairo_set_source_rgb(cr, 0, 0, 0);
        cairo_arc(cr, x, y, 10, 0, 2 * G_PI);
        cairo_fill(cr);
        cairo_destroy(cr);

        /* Now invalidate the affected region of the drawing area. */
        gtk_widget_queue_draw(widget);
        player = 1;
    } else {
        cr = cairo_create(surface);

        cairo_set_source_rgb(cr, 0, 0, 1);
        cairo_arc(cr, x, y, 10, 0, 2 * G_PI);
        cairo_fill(cr);
        cairo_destroy(cr);

        gtk_widget_queue_draw(widget);
        player = 0;
    }
}

/*
 * @Description: Handle button press events by putting a stone,
 * depending which player is playing now.
 * The button-press signal handler receives
 * a GdkEventButton struct which contains this information.
 * If mouse clicks near the intersection,
 * and only when xflag and yflag both satisfy the requirements,
 * put the stone on the board.
 */
static gboolean button_press_event_cb(GtkWidget *widget,
                                      GdkEventButton *event,
                                      gpointer data) {
    int xflag = 0, yflag = 0;

    /* paranoia check, in case we haven't gotten a configure event */
    if (surface == NULL)
        return FALSE;

    /*
     * If there is a winner, game over and output winner info,
     * meanwhile, reset the BOARD_ARRAY and winner_flag.
     */
    if (winner_flag == 1) {
        START_PLAYER_GAME = 0;
        winner_flag = 0;
        player = 0;
        memset(BOARD_ARRAY, 0, sizeof(BOARD_ARRAY));
        clear_surface();
        printf("reset:\n");
        for (int i = 0; i < ROW; ++i) {
            printf("\n");
            for (int j = 0; j < COL; ++j) {
                printf("%d", BOARD_ARRAY[i][j]);
            }
        }
    }

    if (START_PLAYER_GAME == 1 && winner_flag == 0) {
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
            if (put_stone_logic(event->x, event->y, player) != 0) {
                int row = event->x, col = event->y;
                draw_stone(widget, (int) (event->x / 25 + 0.5) * 25,
                           (int) (event->y / 25 + 0.5) * 25);
                for (int i = 0; i < ROW; ++i) {
                    printf("\n");
                    for (int j = 0; j < COL; ++j) {
                        printf("%d", BOARD_ARRAY[i][j]);
                    }
                }
                printf("\n");
                printf("%d\n", check_winner(BOARD_ARRAY, player));
                winner_flag = check_winner(BOARD_ARRAY, player);
            }
        }
    }

    return TRUE;
}


static void create_button(GtkWidget *button_box) {
    GtkWidget *player_button;
    GtkWidget *quit_button;
    GtkWidget *surrender;
    GtkWidget *pause;

    player_button = gtk_button_new_with_label("Player vs Player");
    surrender = gtk_button_new_with_label("Surrender");
    pause = gtk_button_new_with_label("Pause");
    quit_button = gtk_button_new_with_label("Quit");
    gtk_box_pack_start(button_box, player_button, FALSE, FALSE, 0);
    gtk_box_pack_start(button_box, surrender, FALSE, FALSE, 0);
    gtk_box_pack_start(button_box, pause, FALSE, FALSE, 0);
    gtk_box_pack_start(button_box, quit_button, FALSE, FALSE, 0);
    g_signal_connect(player_button, "clicked", G_CALLBACK(button_start_player), NULL);
    g_signal_connect(surrender, "clicked", G_CALLBACK(button_surrender), NULL);
    g_signal_connect(pause, "clicked", G_CALLBACK(button_pause), NULL);
    g_signal_connect(quit_button, "clicked", G_CALLBACK(close_window), NULL);
}

/*
 * @Description: Generate the graphic window.
 * This function is the principle of GTK 3.0,
 * it will be called in main.c
 */
void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *frame;
    GtkWidget *drawing_area;
    GtkWidget *box;
    GtkWidget *button_box;


    box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    button_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW (window), "Gomoku");
    g_signal_connect (window, "destroy", G_CALLBACK(close_window), NULL);

    gtk_container_set_border_width(GTK_CONTAINER (window), 50);
    gtk_container_add(GTK_CONTAINER (window), box);

    frame = gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME (frame), GTK_SHADOW_IN);
    gtk_box_pack_start(box, frame, TRUE, TRUE, 0);
    gtk_box_pack_start(box, button_box, TRUE, TRUE, 0);

    create_button(button_box);

    drawing_area = gtk_drawing_area_new();
    /* set a minimum size */
    gtk_widget_set_size_request(drawing_area, 700, 700);

    gtk_container_add(GTK_CONTAINER (frame), drawing_area);



    /* Signals used to handle the backing surface */
    g_signal_connect (drawing_area, "draw",
                      G_CALLBACK(draw_board), NULL);
    g_signal_connect (drawing_area, "configure-event",
                      G_CALLBACK(configure_event_cb), NULL);

    /* Event signals */
    g_signal_connect (drawing_area, "button-press-event",
                      G_CALLBACK(button_press_event_cb), NULL);

    gtk_widget_set_events(drawing_area, gtk_widget_get_events(drawing_area)
                                        | GDK_BUTTON_PRESS_MASK);

    gtk_widget_show_all(window);
}
