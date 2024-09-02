#ifndef MENU_H
#define MENU_H

#include "sdl2.h"

#include "constants.h"
#include "spritesheet.h"
#include "game.h"

// --------------- //
// Data structures //
// --------------- //

enum menu_state {
    MENU_PLAY_FOCUS,                    // Play choice has focus
    MENU_QUIT_FOCUS,                    // Quit choice has focus
    MENU_DIFFICULTY_EASY_FOCUS,         // Easy difficulty has focus
    MENU_DIFFICULTY_MEDIUM_FOCUS,       // Medium difficulty has focus
    MENU_DIFFICULTY_HARD_FOCUS,         // Hard difficulty has focus
    MENU_PLAY,                          // Play has been chosen
    MENU_QUIT,                          // Play has been chosen
    MENU_DIFFICULTY_FOCUS               // Difficulty has been chosen
};

enum difficulty {
    EASY,                               // Easy difficulty
    MEDIUM,                             // Medium difficulty
    HARD,                               // Hard difficulty
};

struct menu {
    enum menu_state state;              // The choice of the user
    int difficulty_choice;              // The difficulty choice
    
    struct spritesheet *background;     // The menu background
    struct spritesheet *title;          // The title sprite
    struct spritesheet *play;           // The play sprite
    struct spritesheet *quit;           // The quit sprite

    struct spritesheet *difficulty;     // The difficulty sprite
    struct spritesheet *easy;           // The easy sprite
    struct spritesheet *medium;         // The medium sprite
    struct spritesheet *hard;           // The hard sprite

    SDL_Renderer *renderer;             // The renderer
};

// --------- //
// Functions //
// --------- //

/**
 * Creates a new menu.
 *
 * @param renderer  The renderer
 * @return          A pointer to the menu, NULL if there was an error
 */
struct menu *menu_initialize(SDL_Renderer *renderer);

/**
 * Start running the menu.
 *
 * @param menu  The menu to show
 */
void menu_run(struct menu *menu);

/**
 * Delete the menu.
 *
 * @param menu  The menu to delete
 */
void menu_delete(struct menu *menu);

#endif
