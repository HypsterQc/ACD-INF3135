#ifndef GAME_H
#define GAME_H

#include "sdl2.h"

#include "constants.h"
#include "game.h"
#include "menu.h"
#include "spritesheet.h"

#include <math.h>
#include <time.h>
#include <stdbool.h>

/**
 * Runs the game
 * 
 * @param renderer The renderer
 * @param difficulty_choice The difficulty chosen by the user
*/
void game_run (SDL_Renderer *renderer, int difficulty_choice);

/**
 * Initializes the music for the game
 * 
 * @param music_filename The music filename
 * @return Mix_Music *pointer
*/
Mix_Music *initialize_music (char *music_filename);

/**
 * Displays the little triangle representing the player
 * 
 * @param renderer The renderer
 * @param rotX1 The first point of the triangle (x)
 * @param rotY1 The first point of the triangle (y)
 * @param rotX2 The second point of the triangle (x)
 * @param rotY2 The second point of the triangle (y)
 * @param rotX3 The third point of the triangle (x)
 * @param rotY3 The third point of the triangle (y)
*/
void draw_player (SDL_Renderer *renderer, int rotX1, int rotY1, int rotX2, int rotY2, int rotX3, int rotY3);

/**
 * Set the starting position and velocity of the circles randomly
 * 
 * @param position_pie1 The position of the first pie
 * @param position_pie2 The position of the second pie
 * @param position_pie3 The position of the third pie
 * @param position_pie4 The position of the fourth pie
 * @param position_pie5 The position of the fifth pie
 * @param position_pie6 The position of the sixth pie
 * 
 * @param velocity_pie1 The velocity of the first pie
 * @param velocity_pie2 The velocity of the second pie
 * @param velocity_pie3 The velocity of the third pie
 * @param velocity_pie4 The velocity of the fourth pie
 * @param velocity_pie5 The velocity of the fifth pie
 * @param velocity_pie6 The velocity of the sixth pie
*/
void set_starting_position_and_velocity (double *position_pie1, double *position_pie2, double *position_pie3, double *position_pie4, double *position_pie5, double *position_pie6, double *velocity_pie1, double *velocity_pie2, double *velocity_pie3, double *velocity_pie4, double *velocity_pie5, double *velocity_pie6, int velocity_min, int velocity_max, double position_until_reach_the_circle);

/**
 * Calculates the new position player
 * 
 * @param x1 The first point of the triangle (x)
 * @param y1 The first point of the triangle (y)
 * @param x2 The second point of the triangle (x)
 * @param y2 The second point of the triangle (y)
 * @param x3 The third point of the triangle (x)
 * @param y3 The third point of the triangle (y)
 * 
 * @param rotX1 The first point of the triangle (x) after rotation
 * @param rotY1 The first point of the triangle (y) after rotation
 * @param rotX2 The second point of the triangle (x) after rotation
 * @param rotY2 The second point of the triangle (y) after rotation
 * @param rotX3 The third point of the triangle (x) after rotation
 * @param rotY3 The third point of the triangle (y) after rotation
 * 
 * @param rotation The rotation of the player
 * 
 * @param cx The center of the circle where the player is (x)
 * @param cy The center of the circle where the player is (y)
*/
void player_rotation (int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int *rotX1, int *rotY1, int *rotX2, int *rotY2, int *rotX3, int *rotY3, double *rotation, int *cx, int *cy);

/**
 * Draws immutables pies on the screen to initialize the scene
 * 
 * @param renderer The renderer
*/
void draw_static_pies (SDL_Renderer *renderer);

/**
 * Draws the middle circle on the screen
 * 
 * @param renderer The renderer
*/
void draw_middle_circle (SDL_Renderer *renderer);

/**
 * Draws moving pies on the screen to represent the circles at the bottom right of the screen
 * 
 * @param renderer The renderer
 * @param position The position of the pies
*/
void draw_moving_pies_right_down (SDL_Renderer *renderer, double position);

/**
 * Draws moving pies on the screen to represent the circles at the bottom of the screen
 * 
 * @param renderer The renderer
 * @param position The position of the pies
*/
void draw_moving_pies_middle_down (SDL_Renderer *renderer, double position);

/**
 * Draws moving pies on the screen to represent the circles at the bottom left of the screen
 * 
 * @param renderer The renderer
 * @param position The position of the pies
*/
void draw_moving_pies_left_down (SDL_Renderer *renderer, double position);

/**
 * Draws moving pies on the screen to represent the circles at the top left of the screen
 * 
 * @param renderer The renderer
 * @param position The position of the pies
*/
void draw_moving_pies_left_up (SDL_Renderer *renderer, double position);

/**
 * Draws moving pies on the screen to represent the circles at the top of the screen
 * 
 * @param renderer The renderer
 * @param position The position of the pies
*/
void draw_moving_pies_middle_up (SDL_Renderer *renderer, double position);

/**
 * Draws moving pies on the screen to represent the circles at the top right of the screen
 * 
 * @param renderer The renderer
 * @param position The position of the pies
*/
void draw_moving_pies_right_up (SDL_Renderer *renderer, double position);

/**
 * Clears the renderer
 * 
 * @param renderer The renderer
 * @param player The player
*/
void clear_screen (SDL_Renderer *renderer);

/**
 * Generates a random number between min and max
 * 
 * @param min The minimum number
 * @param max The maximum number
 * @return    The random number
*/
double random_number (double min, double max);

/**
 * Displays the timer
 * 
 * @param renderer The renderer
*/
void display_timer (SDL_Renderer *renderer, int minute_left_number, int minute_right_number, int seconds);

/**
 * Generates the current time in milliseconds
 * 
 * @return The current time in milliseconds
*/
unsigned long long getCurrentTimeMillis(void);

/**
 * Displays the real time
 * 
 * @param renderer            The renderer
 * @param elapsedTimeInMillis The time already elapsed
*/
void process_time (SDL_Renderer *renderer, unsigned long long elapsedTimeInMillis);

/**
 * Make the pies appear and disappear in a random way depending on the difficulty
 * 
 * @param position_pie1                 The position of the first pie
 * @param position_pie2                 The position of the second pie
 * @param position_pie3                 The position of the third pie
 * @param position_pie4                 The position of the fourth pie
 * @param position_pie5                 The position of the fifth pie
 * @param position_pie6                 The position of the sixth pie
 * 
 * @param velocity_pie1                 The velocity of the first pie
 * @param velocity_pie2                 The velocity of the second pie
 * @param velocity_pie3                 The velocity of the third pie
 * @param velocity_pie4                 The velocity of the fourth pie
 * @param velocity_pie5                 The velocity of the fifth pie
 * @param velocity_pie6                 The velocity of the sixth pie
 * 
 * @param starting_position_for_circle  The starting position of the circle
 * 
 * @param velocity_min                  The minimum random velocity
 * @param velocity_max                  The maximum random velocity
*/
void make_pies_appear_and_disappear (double *position_pie1, double *position_pie2, double *position_pie3, double *position_pie4, double *position_pie5, double *position_pie6, double *velocity_pie1, double *velocity_pie2, double *velocity_pie3, double *velocity_pie4, double *velocity_pie5, double *velocity_pie6, double *starting_position_for_circle, int *velocity_min, int *velocity_max);

/**
 * Initializes the difficulty
 * 
 * @param difficulty_choice                 The difficulty chosen by the user
 * @param position_until_reach_the_circle   The position until the circle is reached by the circle
 * @param velocity_min                      The minimum random velocity of the circle
 * @param velocity_max                      The maximum random velocity of the circle
*/
void initialize_difficulty (int *difficulty_choice, double *position_until_reach_the_circle, int *velocity_min, int *velocity_max);

/**
 * Make the pies move
 * 
 * @param position_pie1 The position of the first pie
 * @param position_pie2 The position of the second pie
 * @param position_pie3 The position of the third pie
 * @param position_pie4 The position of the fourth pie
 * @param position_pie5 The position of the fifth pie
 * @param position_pie6 The position of the sixth pie
 * 
 * @param velocity_pie1 The velocity of the first pie
 * @param velocity_pie2 The velocity of the second pie
 * @param velocity_pie3 The velocity of the third pie
 * @param velocity_pie4 The velocity of the fourth pie
 * @param velocity_pie5 The velocity of the fifth pie
 * @param velocity_pie6 The velocity of the sixth pie
*/
void make_circles_move (double *position_pie1, double *position_pie2, double *position_pie3, double *position_pie4, double *position_pie5, double *position_pie6, double velocity_pie1, double velocity_pie2, double velocity_pie3, double velocity_pie4, double velocity_pie5, double velocity_pie6);

/**
 * Animate the circles
 * 
 * @param renderer      The renderer
 * @param position_pie1 The position of the first pie
 * @param position_pie2 The position of the second pie
 * @param position_pie3 The position of the third pie
 * @param position_pie4 The position of the fourth pie
 * @param position_pie5 The position of the fifth pie
 * @param position_pie6 The position of the sixth pie
*/
void animate_circles (SDL_Renderer *renderer, double position_pie1, double position_pie2, double position_pie3, double position_pie4, double position_pie5, double position_pie6);

/**
 * Displays the score
 * 
 * @param renderer The renderer
*/
void game_over (SDL_Renderer *renderer);

/**
 * Pauses the game
 * 
 * @param renderer  The renderer
 * @param music     The music to stop when the game is paused
*/
void game_paused (SDL_Renderer *renderer, Mix_Music *music);

/**
 * Displays the pause screen
 * 
 * @param renderer The renderer
*/
void display_pause (SDL_Renderer *renderer);

/**
 * Tracks the player using his rotation
 * 
 * @param rotation The rotation of the player
*/
void track_player (double *rotation);

/**
 * Detects the collision between the player and the circles
 * 
 * @param rotation      The rotation of the player
 * @param music         The music to stop when the collision is detected and the game is over
 * @param position_pie1 Pie to detect the collision with
 * @param position_pie2 Pie to detect the collision with
 * @param position_pie3 Pie to detect the collision with
 * @param position_pie4 Pie to detect the collision with
 * @param position_pie5 Pie to detect the collision with
 * @param position_pie6 Pie to detect the collision with
 * @return 1 if the collision is detected, 0 otherwise
*/
int collision_detection (double *rotation, Mix_Music *music, double *position_pie1, double *position_pie2, double *position_pie3, double *position_pie4, double *position_pie5, double *position_pie6);

/**
 * Displays the game over screen
 * 
 * @param renderer      The renderer
*/
void display_game_over (SDL_Renderer *renderer);

/**
 * Limits the frame rate each second
 * @param limit The limit
 */
void frame_limits (unsigned int limit);

#endif
