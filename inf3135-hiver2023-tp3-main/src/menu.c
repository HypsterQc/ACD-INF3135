#include "menu.h"

#include <stdbool.h>

struct menu *menu_initialize(SDL_Renderer *renderer) {
    struct menu *menu;
    menu = malloc(sizeof(struct menu));
    menu->renderer = renderer;
    menu->state = MENU_PLAY_FOCUS;
    menu->background = spritesheet_create(BACKGROUND_FILENAME, 1, 1, 1, renderer);
    menu->difficulty = spritesheet_create(DIFFICULTY_FILENAME, 1, 1, 1, renderer);
    menu->easy = spritesheet_create(EASY_FILENAME, 1, 1, 1, renderer);
    menu->medium = spritesheet_create(MEDIUM_FILENAME, 1, 1, 1, renderer);
    menu->hard = spritesheet_create(HARD_FILENAME, 1, 1, 1, renderer);
    menu->title = spritesheet_create(TITLE_FILENAME, 1, 1, 1, renderer);
    menu->play = spritesheet_create(PLAY_FILENAME, 1, 1, 1, renderer);
    menu->quit = spritesheet_create(QUIT_FILENAME, 1, 1, 1, renderer);
    return menu;
}

int menu_alpha(bool chosen) {
    return chosen ? 255 : 64;
}

void menu_run(struct menu *menu) {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        fprintf(stderr, "Failed to open audio: %s\n", Mix_GetError());
    }
    Mix_Music *menu_sound = Mix_LoadMUS(GAME_MENU_NAVIGATION_SOUND_FILENAME);
    Mix_Music *music_quit = Mix_LoadMUS(GAME_QUIT_SOUND_FILENAME);

    if (!menu_sound) {
        fprintf(stderr, "Failed to load music: %s\n", Mix_GetError());
        Mix_CloseAudio();
        Mix_Quit();
    }
    SDL_Event e;
    while (menu->state != MENU_PLAY && menu->state != MENU_QUIT) {
        while (SDL_PollEvent(&e) != 0) {
            switch (e.type) {
                case SDL_QUIT:
                    if (Mix_PlayMusic(music_quit, 0) < 0) {
                        fprintf(stderr, "Failed to play music: %s\n", Mix_GetError());
                    }
                    SDL_Delay (350);
                    menu->state = MENU_QUIT;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_LEFT:
                            if (Mix_PlayMusic(menu_sound, 0) < 0) {
                                fprintf(stderr, "Failed to play music: %s\n", Mix_GetError());
                            }
                            if (menu->state == MENU_PLAY_FOCUS) {
                                menu->state = MENU_QUIT_FOCUS;
                            } else if (menu->state == MENU_QUIT_FOCUS) {
                                menu->state = MENU_PLAY_FOCUS;
                            } else if (menu->state == MENU_DIFFICULTY_EASY_FOCUS) {
                                menu->state = MENU_DIFFICULTY_HARD_FOCUS;
                                menu->difficulty_choice = HARD;
                            } else if (menu->state == MENU_DIFFICULTY_MEDIUM_FOCUS) {
                                menu->state = MENU_DIFFICULTY_EASY_FOCUS;
                                menu->difficulty_choice = EASY;
                            } else if (menu->state == MENU_DIFFICULTY_HARD_FOCUS) {
                                menu->state = MENU_DIFFICULTY_MEDIUM_FOCUS;
                                menu->difficulty_choice = MEDIUM;
                            }
                            break;
                        case SDLK_RIGHT:
                            if (Mix_PlayMusic(menu_sound, 0) < 0) {
                                fprintf(stderr, "Failed to play music: %s\n", Mix_GetError());
                            }
                            if (menu->state == MENU_PLAY_FOCUS) {
                                menu->state = MENU_QUIT_FOCUS;
                            } else if (menu->state == MENU_QUIT_FOCUS) {
                                menu->state = MENU_PLAY_FOCUS;
                            } else if (menu->state == MENU_DIFFICULTY_EASY_FOCUS) {
                                menu->state = MENU_DIFFICULTY_MEDIUM_FOCUS;
                                menu->difficulty_choice = MEDIUM;
                            } else if (menu->state == MENU_DIFFICULTY_MEDIUM_FOCUS) {
                                menu->state = MENU_DIFFICULTY_HARD_FOCUS;
                                menu->difficulty_choice = HARD;
                            } else if (menu->state == MENU_DIFFICULTY_HARD_FOCUS) {
                                menu->state = MENU_DIFFICULTY_EASY_FOCUS;
                                menu->difficulty_choice = EASY;
                            }
                            break;
                        case SDLK_RETURN:
                            if (Mix_PlayMusic(menu_sound, 0) < 0) {
                                fprintf(stderr, "Failed to play music: %s\n", Mix_GetError());
                            }
                            if (menu->state == MENU_PLAY_FOCUS) {
                                menu->state = MENU_DIFFICULTY_MEDIUM_FOCUS;
                            } else if (menu->state == MENU_DIFFICULTY_EASY_FOCUS) {
                                menu->difficulty_choice = EASY;
                                menu->state = MENU_PLAY;
                            } else if (menu->state == MENU_DIFFICULTY_MEDIUM_FOCUS) {
                                menu->difficulty_choice = MEDIUM;
                                menu->state = MENU_PLAY;
                            } else if (menu->state == MENU_DIFFICULTY_HARD_FOCUS) {
                                menu->difficulty_choice = HARD;
                                menu->state = MENU_PLAY;
                            } else if (menu->state == MENU_QUIT_FOCUS) {
                                menu->state = MENU_QUIT;
                            }
                            break;
                        case SDLK_ESCAPE:
                            if (Mix_PlayMusic(menu_sound, 0) < 0) {
                                fprintf(stderr, "Failed to play music: %s\n", Mix_GetError());
                            }
                            if (menu->state == MENU_DIFFICULTY_EASY_FOCUS || menu->state == MENU_DIFFICULTY_MEDIUM_FOCUS || menu->state == MENU_DIFFICULTY_HARD_FOCUS) {
                                menu->state = MENU_PLAY_FOCUS;
                            }
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_SetRenderDrawColor(menu->renderer, 0x00, 0x00, 0x00, 0x00 );
        SDL_RenderClear(menu->renderer);
        spritesheet_render(menu->background, BACKGROUND_X, BACKGROUND_Y,
                           255, 0);
        spritesheet_render(menu->title,      TITLE_X,      TITLE_Y,
                           255, 0);
        spritesheet_render(menu->play,       PLAY_X,       PLAY_Y,
                           menu_alpha(menu->state == MENU_PLAY_FOCUS), 0);
        spritesheet_render(menu->quit,       QUIT_X,       QUIT_Y,
                           menu_alpha(menu->state == MENU_QUIT_FOCUS), 0);
        spritesheet_render(menu->difficulty, DIFFICULTY_X, DIFFICULTY_Y,
                           255, 0);
        spritesheet_render(menu->easy, EASY_X, EASY_Y,
                           menu_alpha(menu->state == MENU_DIFFICULTY_EASY_FOCUS), 0);
        spritesheet_render(menu->medium, MEDIUM_X, MEDIUM_Y,
                           menu_alpha(menu->state == MENU_DIFFICULTY_MEDIUM_FOCUS), 0);
        spritesheet_render(menu->hard, HARD_X, HARD_Y,
                           menu_alpha(menu->state == MENU_DIFFICULTY_HARD_FOCUS), 0);
        SDL_RenderPresent(menu->renderer);
    }
    Mix_FreeMusic (menu_sound);
    Mix_FreeMusic (music_quit);
    Mix_CloseAudio ();
    Mix_Quit ();
}

void menu_delete(struct menu *menu) {
    if (menu != NULL) {
        spritesheet_delete(menu->background);
        spritesheet_delete(menu->title);
        spritesheet_delete(menu->play);
        spritesheet_delete(menu->quit);
        spritesheet_delete(menu->easy);
        spritesheet_delete(menu->medium);
        spritesheet_delete(menu->hard);
        spritesheet_delete(menu->difficulty);
        free(menu);
    }
}
