#include "game.h"

double random_number (double min, double max) {
    return (double) rand() / (double)RAND_MAX * (max - min) + min;
}

Mix_Music *initialize_music(char *music_filename) {
    if (Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf (stderr, "Failed to open audio: %s\n", Mix_GetError());
    }

    Mix_Music *music = Mix_LoadMUS(music_filename);

    if (!music) {
        fprintf (stderr, "Failed to load music: %s\n", Mix_GetError());
        Mix_CloseAudio ();
        Mix_Quit ();
    }

    if (Mix_PlayMusic (music, -1) < 0) {
        fprintf (stderr, "Failed to play music: %s\n", Mix_GetError ());
    }

    return music;
}

void draw_static_pies(SDL_Renderer *renderer) {

    // Immutable pies
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2),
                      700, 0, 60, 240, 240, 240, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2),
                      700, 60, 120, 255, 255, 255, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2),
                      700, 120, 180, 240, 240, 240, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2),
                      700, 180, 240, 255, 255, 255, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2),
                      700, 240, 300, 240, 240, 240, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2),
                      700, 300, 360, 255, 255, 255, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
}

void draw_moving_pies_right_down (SDL_Renderer *renderer, double position) {
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position, 0, 60, 255, 0, 0, 255)) {
            fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError());
    }
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position - CIRCLE_WIDTH, 0, 60, 240, 240, 240, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError());
    }
}

void draw_moving_pies_middle_down (SDL_Renderer *renderer, double position) {
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position, 60, 120, 255, 0, 0, 255)) {
            fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError());
    }
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position - CIRCLE_WIDTH, 60, 120, 255, 255, 255, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError());
    }
}

void draw_moving_pies_left_down (SDL_Renderer *renderer, double position) {
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position, 120, 180, 255, 0, 0, 255)) {
            fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position - CIRCLE_WIDTH, 120, 180, 240, 240, 240, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
}

void draw_moving_pies_left_up (SDL_Renderer *renderer, double position) {
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position, 180, 240, 255, 0, 0, 255)) {
            fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
    if (filledPieRGBA(renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position - CIRCLE_WIDTH, 180, 240, 255, 255, 255, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError());
    }
}

void draw_moving_pies_middle_up (SDL_Renderer *renderer, double position) {
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position, 240, 300, 255, 0, 0, 255)) {
            fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError());
    }
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position - CIRCLE_WIDTH, 240, 300, 240, 240, 240, 255)) {
        fprintf(stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
}

void draw_moving_pies_right_up (SDL_Renderer *renderer, double position) {
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position, 300, 360, 255, 0, 0, 255)) {
            fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
    if (filledPieRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2), position - CIRCLE_WIDTH, 300, 360, 255, 255, 255, 255)) {
        fprintf (stderr, "Failed to draw pie: %s\n", SDL_GetError ());
    }
}

void draw_middle_circle(SDL_Renderer *renderer) {
    if (filledCircleRGBA (renderer, (SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 2),
                         40, 170, 170, 170, 255)) {
        fprintf (stderr, "Failed to draw circle: %s\n", SDL_GetError ());
    }
}

void draw_player (SDL_Renderer *renderer, int rotX1, int rotY1, int rotX2, int rotY2, int rotX3, int rotY3) {
    if (filledTrigonRGBA (renderer, rotX1, rotY1, rotX2, rotY2, rotX3, rotY3, 0, 0, 255, 255)) printf ("Error: %s", SDL_GetError ());
}

void clear_screen(SDL_Renderer *renderer) {
    if (SDL_RenderClear (renderer)) {
        fprintf(stderr, "Failed to clear renderer: %s\n", SDL_GetError ());
    }
}

void display_timer (SDL_Renderer *renderer, int minute_left_number, int minute_right_number, int seconds) {
    struct spritesheet *timer = spritesheet_create (TIMER_FILENAME, 1, 11, 1, renderer);
    spritesheet_render (timer, MINUTES_LEFT_DIGIT_POSITION_X, MINUTES_LEFT_DIGIT_POSITION_Y, 255, minute_left_number);
    spritesheet_render (timer, MINUTES_RIGHT_DIGIT_POSITION_X, MINUTES_RIGHT_DIGIT_POSITION_Y, 255, minute_right_number);
    spritesheet_render (timer, POINT_POSITION_X, POINT_POSITION_Y, 255, 10);
    spritesheet_render (timer, SECONDS_DIGIT_POSITION_X, SECONDS_DIGIT_POSITION_Y, 255, seconds);
}

unsigned long long getCurrentTimeMillis(void) {
    struct timespec currentTime;
    clock_gettime (1, &currentTime);
    unsigned long long millis = currentTime.tv_sec * 1000 + currentTime.tv_nsec / 1000000;
    return millis;
}

void process_time (SDL_Renderer *renderer, unsigned long long elapsedTimeInMillis) {
    if ((int) floor (elapsedTimeInMillis / 1000) < 10) {
        display_timer (renderer, 0, (int) floor (elapsedTimeInMillis / 1000), ((int) ((elapsedTimeInMillis / 1000.0) * 10)) % 10);
    }
    else if ((int) floor (elapsedTimeInMillis / 1000) >= 10 && (int)floor (elapsedTimeInMillis / 1000) < 100) {
        display_timer (renderer, (int) floor (elapsedTimeInMillis / 1000) / 10, (int) floor (elapsedTimeInMillis / 1000) % 10, ((int) ((elapsedTimeInMillis / 1000.0) * 10)) % 10);
    }
}

void make_pies_appear_and_disappear (double *position_pie1, double *position_pie2, double *position_pie3, double *position_pie4, double *position_pie5, double *position_pie6, double *velocity_pie1, double *velocity_pie2, double *velocity_pie3, double *velocity_pie4, double *velocity_pie5, double *velocity_pie6, double *position_until_reach_the_circle, int *velocity_min, int *velocity_max) {
    // If the pie must desapear, it will reapear at the different position and a velocity
    if (*position_pie1 <= CIRCLE_WIDTH) {
        *position_pie1 = random_number (*position_until_reach_the_circle, 700);
        *velocity_pie1 = random_number (*velocity_min, *velocity_max);
    } if (*position_pie2 <= CIRCLE_WIDTH) {
        *position_pie2 = random_number (*position_until_reach_the_circle, 700);
        *velocity_pie2 = random_number (*velocity_min, *velocity_max);
    } if (*position_pie3 <= CIRCLE_WIDTH) {
        *position_pie3 = random_number (*position_until_reach_the_circle, 700);
        *velocity_pie3 = random_number (*velocity_min, *velocity_max);
    } if (*position_pie4 <= CIRCLE_WIDTH) {
        *position_pie4 = random_number (*position_until_reach_the_circle, 700);
        *velocity_pie4 = random_number (*velocity_min, *velocity_max);
    } if (*position_pie5 <= CIRCLE_WIDTH) {
        *position_pie5 = random_number (*position_until_reach_the_circle, 700);
        *velocity_pie5 = random_number (*velocity_min, *velocity_max);
    } if (*position_pie6 <= CIRCLE_WIDTH) {
        *position_pie6 = random_number (*position_until_reach_the_circle, 700);
        *velocity_pie6 = random_number (*velocity_min, *velocity_max);
    }
}

void make_circles_move (double *position_pie1, double *position_pie2, double *position_pie3, double *position_pie4, double *position_pie5, double *position_pie6, double velocity_pie1, double velocity_pie2, double velocity_pie3, double velocity_pie4, double velocity_pie5, double velocity_pie6) {
    // The circles move
    // Decrease the position of the circles by the velocity
    *position_pie1 -= velocity_pie1;
    *position_pie2 -= velocity_pie2;
    *position_pie3 -= velocity_pie3;
    *position_pie4 -= velocity_pie4;
    *position_pie5 -= velocity_pie5;
    *position_pie6 -= velocity_pie6;
}

void animate_circles (SDL_Renderer *renderer, double position_pie1, double position_pie2, double position_pie3, double position_pie4, double position_pie5, double position_pie6) {
    // Draw the pies
    draw_moving_pies_right_down  (renderer, position_pie1);
    draw_moving_pies_middle_down (renderer, position_pie2);
    draw_moving_pies_left_down   (renderer, position_pie3);
    draw_moving_pies_left_up     (renderer, position_pie4);
    draw_moving_pies_middle_up   (renderer, position_pie5);
    draw_moving_pies_right_up    (renderer, position_pie6);
}

void initialize_difficulty (int *difficulty_choice, double *position_until_reach_the_circle, int *velocity_min, int *velocity_max) {
    // Here are the hard coded values for the different levels
    if (*difficulty_choice == EASY) {
        *position_until_reach_the_circle = 500;
        *velocity_min = 2;
        *velocity_max = 3;
    } else if (*difficulty_choice == MEDIUM) {
        *position_until_reach_the_circle = 400;
        *velocity_min = 3;
        *velocity_max = 5;
    } else if (*difficulty_choice == HARD) {
        *position_until_reach_the_circle = random_number (250, 400);
        *velocity_min = 5;
        *velocity_max = 6;
    }
}

void display_pause (SDL_Renderer *renderer) {
    struct spritesheet *resume = spritesheet_create (PLAY_FILENAME, 1, 1, 1, renderer);
    spritesheet_render (resume, SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 100, 255, 0);
}

void game_paused (SDL_Renderer *renderer, Mix_Music *music) {
    bool paused = true;
    while (paused) {
        SDL_Event event;
        while (SDL_PollEvent (&event)) {
            if (event.type == SDL_QUIT) {
                paused = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        paused = false;
                        break;
                    case SDLK_p:
                        paused = false;
                        break;
                    case SDLK_SPACE:
                        paused = false;
                        break;
                    case SDLK_RETURN:
                        paused = false;
                        break;
                }
            }
        }

        Mix_PlayMusic (music, 0);
        if (SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255) < 0) {
            fprintf (stderr, "Could not set render draw color: %s", SDL_GetError ());
        }
        clear_screen (renderer);
        display_pause (renderer);
        SDL_RenderPresent (renderer);
    }
}

void display_game_over (SDL_Renderer *renderer) {
    struct spritesheet *game_over = spritesheet_create (GAME_OVER_FILENAME, 1, 1, 1, renderer);
    spritesheet_render (game_over, GAME_OVER_X, GAME_OVER_Y, 255, 0);
}

void game_over (SDL_Renderer *renderer) {
    bool music_is_read = false;
    bool game_over = true;
    Mix_Music *game_over_music = initialize_music (GAME_OVER_MUSIC_FILENAME);
    while (game_over) {
        SDL_Event event;
        while (SDL_PollEvent (&event)) {
            if (event.type == SDL_QUIT) {
                game_over = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        game_over = false;
                        break;
                    case SDLK_SPACE:
                        game_over = false;
                        break;
                    case SDLK_RETURN:
                        game_over = false;
                        break;
                }
            }
        }
        if (!music_is_read) {
            if (Mix_PlayMusic (game_over_music, 0)) {
                fprintf (stderr, "Failed to play music: %s\n", Mix_GetError ());
            }
            music_is_read = true;
        }
        if (SDL_SetRenderDrawColor (renderer, 255, 255, 255, 255) < 0)
            fprintf (stderr, "Could not set render draw color: %s", SDL_GetError ());
        clear_screen (renderer);
        display_game_over (renderer);
        SDL_RenderPresent (renderer);
        SDL_Delay (1000);
    }
}

void track_player (double *rotation) {
    // Set the rotation of the player to 0 after 2 PI
    if (*rotation >= 6.3) *rotation = 0.0;
    if (*rotation <= -6.3) *rotation = 0.0;
}

int collision_detection (double *rotation, Mix_Music *music, double *position_pie1, double *position_pie2, double *position_pie3, double *position_pie4, double *position_pie5, double *position_pie6) {
    if ((*rotation >= -1.575 && *rotation <= -0.525 && *position_pie1 <= RADIUS + CIRCLE_WIDTH && *position_pie1 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= -0.525 && *rotation <= 0.525 && *position_pie2 <= RADIUS + CIRCLE_WIDTH && *position_pie2 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= 0.525 && *rotation <= 1.575 && *position_pie3 <= RADIUS + CIRCLE_WIDTH && *position_pie3 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= 1.575 && *rotation <= 2.625 && *position_pie4 <= RADIUS + CIRCLE_WIDTH && *position_pie4 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= 2.625 && *rotation <= 3.675 && *position_pie5 <= RADIUS + CIRCLE_WIDTH && *position_pie5 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= 3.675 && *rotation <= 4.725 && *position_pie6 <= RADIUS + CIRCLE_WIDTH && *position_pie6 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= 4.725 && *rotation <= 5.775 && *position_pie1 <= RADIUS + CIRCLE_WIDTH && *position_pie1 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= 5.775 && *rotation <= 6.3 && *position_pie2 <= RADIUS + CIRCLE_WIDTH && *position_pie2 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= -6.3  && *rotation <= -5.775 && *position_pie2 <= RADIUS + CIRCLE_WIDTH && *position_pie2 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= -5.775 && *rotation <= -4.725 && *position_pie3 <= RADIUS + CIRCLE_WIDTH && *position_pie3 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= -4.725 && *rotation <= -3.675 && *position_pie4 <= RADIUS + CIRCLE_WIDTH && *position_pie4 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= -3.675 && *rotation <= -2.625 && *position_pie5 <= RADIUS + CIRCLE_WIDTH && *position_pie5 >= RADIUS - CIRCLE_WIDTH) || (*rotation >= -2.625 && *rotation <= -1.575 && *position_pie6 <= RADIUS + CIRCLE_WIDTH && *position_pie6 >= RADIUS - CIRCLE_WIDTH)) {
        SDL_Delay(1000);
        Mix_FreeMusic(music);
        Mix_CloseAudio();
        Mix_Quit();
        return 1;
    }
    return 0;
}

void set_starting_position_and_velocity (double *position_pie1, double *position_pie2, double *position_pie3, double *position_pie4, double *position_pie5, double *position_pie6, double *velocity_pie1, double *velocity_pie2, double *velocity_pie3, double *velocity_pie4, double *velocity_pie5, double *velocity_pie6, int velocity_min, int velocity_max, double position_until_reach_the_circle) {
    *velocity_pie1 = random_number (velocity_min, velocity_max);
    *position_pie1 = random_number (position_until_reach_the_circle, 800);

    *velocity_pie2 = random_number (velocity_min, velocity_max);
    *position_pie2 = random_number (position_until_reach_the_circle, 800);

    *velocity_pie3 = random_number (velocity_min, velocity_max);
    *position_pie3 = random_number (position_until_reach_the_circle, 800);

    *velocity_pie4 = random_number (velocity_min, velocity_max);
    *position_pie4 = random_number (position_until_reach_the_circle, 800);

    *velocity_pie5 = random_number (velocity_min, velocity_max);
    *position_pie5 = random_number (position_until_reach_the_circle, 800);

    *velocity_pie6 = random_number (velocity_min, velocity_max);
    *position_pie6 = random_number (position_until_reach_the_circle, 800);
}

void player_rotation (int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int *rotX1, int *rotY1, int *rotX2, int *rotY2, int *rotX3, int *rotY3, double *rotation, int *cx, int *cy) {
        // Calculate the position of the main character
        *x1 = *cx + RADIUS * cos (ANGLE);
        *y1 = *cy + RADIUS * sin (ANGLE);
        *x2 = *x1 + 10;
        *y2 = *y1 - 20;
        *x3 = *x1 - 10;
        *y3 = *y1 - 20;

        // Calculate the rotated coordinates around the triangle's center
        *rotX1 = *cx + (*x1 - *cx) * cos(*rotation) - (*y1 - *cy) * sin(*rotation);
        *rotY1 = *cy + (*x1 - *cx) * sin(*rotation) + (*y1 - *cy) * cos(*rotation);
        *rotX2 = *cx + (*x2 - *cx) * cos(*rotation) - (*y2 - *cy) * sin(*rotation);
        *rotY2 = *cy + (*x2 - *cx) * sin(*rotation) + (*y2 - *cy) * cos(*rotation);
        *rotX3 = *cx + (*x3 - *cx) * cos(*rotation) - (*y3 - *cy) * sin(*rotation);
        *rotY3 = *cy + (*x3 - *cx) * sin(*rotation) + (*y3 - *cy) * cos(*rotation);
}

void frame_limits (unsigned int limit) {
    unsigned int ticks = SDL_GetTicks ();

    if (limit < ticks)
        return ;
    else if (limit > ticks + FRAME_TIME) {
        SDL_Delay (FRAME_TIME);
    } else {
        SDL_Delay (limit - ticks);
    }
}

void game_run(SDL_Renderer *renderer, int difficulty_choice) {

    // Initialize the music
    Mix_Music *music = initialize_music (GAME_PLAY_MUSIC_FILENAME);

    // Get the current time in milliseconds at the start of the game
    unsigned long long startTimeMillis = getCurrentTimeMillis ();

    // Initialize the frame limit
    unsigned int fps = 0;
    fps = SDL_GetTicks () + FRAME_TIME;

    // Initialize variables to move player position circularly
    int cx = SCREEN_WIDTH / 2, cy = SCREEN_HEIGHT / 2;
    double rotation = ROTATION;
    double speed = 0;

    // The set of possible position and velocity based on the chosen level
    int velocity_min, velocity_max;
    double position_until_reach_the_circle;

    // The set of position and velocity of the circles generated randomly
    double position_pie1, position_pie2, position_pie3, position_pie4, position_pie5, position_pie6;
    double velocity_pie1, velocity_pie2, velocity_pie3, velocity_pie4, velocity_pie5, velocity_pie6;

    // Calculate the position of the main character
    int x1, y1, x2, y2, x3, y3;

    // Calculate the rotated coordinates around the triangle's center
    int rotX1, rotY1, rotX2, rotY2, rotX3, rotY3;

    // Initialize the position and velocity based on the chosen level
    initialize_difficulty (&difficulty_choice, &position_until_reach_the_circle, &velocity_min, &velocity_max);

    // This is the starting position and velocity of the circles generated randomly
    set_starting_position_and_velocity (&position_pie1, &position_pie2, &position_pie3, &position_pie4, &position_pie5, &position_pie6, &velocity_pie1, &velocity_pie2, &velocity_pie3, &velocity_pie4, &velocity_pie5, &velocity_pie6, velocity_min, velocity_max, position_until_reach_the_circle);

    SDL_Event event;

    SDL_bool is_game_over = SDL_FALSE;

    while (!is_game_over) {
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            game_paused (renderer, music);
                            break;
                        case SDLK_p:
                            game_paused (renderer, music);
                            break;
                        case SDLK_LEFT:
                            speed = -PLAYER_SPEED;
                            break;
                        case SDLK_RIGHT:
                            speed = +PLAYER_SPEED;
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_LEFT:
                            speed = 0;
                            break;
                        case SDLK_RIGHT:
                            speed = 0;
                            break;
                    }
                    break;
            }
        }

        rotation += speed;

        // Draw the background
        draw_static_pies (renderer);

        // Move the circles
        make_circles_move (&position_pie1, &position_pie2, &position_pie3, &position_pie4, &position_pie5, &position_pie6, velocity_pie1, velocity_pie2, velocity_pie3, velocity_pie4, velocity_pie5, velocity_pie6);

        // Tracking player rotation
        track_player (&rotation);

        // Manage the appearition frequency
        make_pies_appear_and_disappear (&position_pie1, &position_pie2, &position_pie3, &position_pie4, &position_pie5, &position_pie6, &velocity_pie1, &velocity_pie2, &velocity_pie3, &velocity_pie4, &velocity_pie5, &velocity_pie6, &position_until_reach_the_circle, &velocity_min, &velocity_max);

        // Move the circles toward the center
        animate_circles (renderer, position_pie1, position_pie2, position_pie3, position_pie4, position_pie5, position_pie6);

        // The middel circle
        draw_middle_circle (renderer);

        // Calculate the position of the main character
        player_rotation (&x1, &y1, &x2, &y2, &x3, &y3, &rotX1, &rotY1, &rotX2, &rotY2, &rotX3, &rotY3, &rotation, &cx, &cy);

        // Represents the main character (the blue triangle)
        draw_player (renderer, rotX1, rotY1, rotX2, rotY2, rotX3, rotY3);

        // Check if the player has collided with a circle
        if (collision_detection (&rotation, music, &position_pie1, &position_pie2, &position_pie3, &position_pie4, &position_pie5, &position_pie6) == 1) is_game_over = SDL_TRUE;

        // Time management
        process_time (renderer, getCurrentTimeMillis () - startTimeMillis);

        // Frame limit (60 fps)
        frame_limits (fps);

        // Set the next frame limit
        fps = SDL_GetTicks () + FRAME_TIME;

        // Update the screen
        SDL_RenderPresent (renderer);
    }

    // game over screen
    game_over (renderer);
}
