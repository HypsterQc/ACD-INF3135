// GENERAL CONSTANTS
#define SCREEN_WIDTH  (0.5 * 2048)
#define SCREEN_HEIGHT (0.5 * 1535)

// MENU CONSTANTS
#define BACKGROUND_FILENAME "../assets/background-small.png"
#define BACKGROUND_X 0
#define BACKGROUND_Y 0

#define TITLE_FILENAME "../assets/title-small.png"
#define TITLE_WIDTH 588
#define TITLE_X (0.5 * (SCREEN_WIDTH - TITLE_WIDTH))
#define TITLE_Y (0.05 * SCREEN_HEIGHT)

#define PLAY_FILENAME "../assets/play-small.png"
#define PLAY_WIDTH 122
#define PLAY_X (0.25 * SCREEN_WIDTH - 0.5 * PLAY_WIDTH)
#define PLAY_Y (0.45 * SCREEN_HEIGHT)

#define QUIT_FILENAME "../assets/quit-small.png"
#define QUIT_WIDTH 160
#define QUIT_X (0.75 * SCREEN_WIDTH - 0.5 * QUIT_WIDTH)
#define QUIT_Y (0.45 * SCREEN_HEIGHT)

#define DIFFICULTY_FILENAME "../assets/difficulty-small.png"
#define DIFFICULTY_WIDTH 325
#define DIFFICULTY_X (0.5 * SCREEN_WIDTH - 0.5 * DIFFICULTY_WIDTH)
#define DIFFICULTY_Y (0.8 * SCREEN_HEIGHT)

#define EASY_FILENAME "../assets/easy-small.png"
#define EASY_WIDTH 325
#define EASY_X (0.5 * SCREEN_WIDTH - 0.5 * DIFFICULTY_WIDTH)
#define EASY_Y (0.75 * SCREEN_HEIGHT)

#define MEDIUM_FILENAME "../assets/medium-small.png"
#define MEDIUM_WIDTH 325
#define MEDIUM_X (0.6 * SCREEN_WIDTH - 0.5 * DIFFICULTY_WIDTH)
#define MEDIUM_Y (0.75 * SCREEN_HEIGHT)

#define HARD_FILENAME "../assets/hard-small.png"
#define HARD_WIDTH 325
#define HARD_X (0.73 * SCREEN_WIDTH - 0.5 * DIFFICULTY_WIDTH)
#define HARD_Y (0.75 * SCREEN_HEIGHT)

#define GAME_OVER_FILENAME "../assets/game-over.png"
#define GAME_OVER_WIDTH 595
#define GAME_OVER_HEIGHT 300
#define GAME_OVER_X (SCREEN_WIDTH - GAME_OVER_WIDTH) / 2
#define GAME_OVER_Y (SCREEN_HEIGHT - GAME_OVER_HEIGHT) / 2

#define TIMER_FILENAME "../assets/digits-small.png"


// GAME CONSTANTS

// Game music
#define GAME_PLAY_MUSIC_FILENAME "../assets/courtesy.mp3"
#define GAME_OVER_MUSIC_FILENAME "../assets/beat.wav"
#define GAME_QUIT_SOUND_FILENAME "../assets/scratch.wav"
#define GAME_MENU_NAVIGATION_SOUND_FILENAME "../assets/medium.wav"

// Player constants
#define RADIUS 80
#define PLAYER_SPEED 0.04

// Circles constants
#define CIRCLE_WIDTH 12
#define ROTATION 0
#define ANGLE -11

// FRAMES CONSTANTS
#define FRAME_RATE 60
#define FRAME_TIME (1000 / FRAME_RATE)

// Timer constants
#define MINUTES_LEFT_DIGIT_POSITION_X SCREEN_WIDTH - 120
#define MINUTES_LEFT_DIGIT_POSITION_Y 40

#define MINUTES_RIGHT_DIGIT_POSITION_X SCREEN_WIDTH - 100
#define MINUTES_RIGHT_DIGIT_POSITION_Y 40

#define POINT_POSITION_X SCREEN_WIDTH - 80
#define POINT_POSITION_Y 40

#define SECONDS_DIGIT_POSITION_X SCREEN_WIDTH - 60
#define SECONDS_DIGIT_POSITION_Y 40

