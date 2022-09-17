#ifndef __input_h__
#define __input_h__

#define RENDER_PERSPECTIVE  1
#define RENDER_ORTHOGRAPHIC 2

#define KEY_STATE_UP 0
#define KEY_STATE_DOWN 1
#define KEY_STATE_HELD 2

typedef struct{
    float fov;
    int screen_width;
    int screen_height;
    int flags;
}GAME_INPUT;


typedef struct{
    short int Key_UP;
    short int Key_DOWN;
}CMD;


void handle_commands (CMD **__commands, GAME_INPUT **__gameinput);

#endif