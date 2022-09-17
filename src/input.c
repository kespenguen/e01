#include "input.h"


void handle_commands (CMD **__commands,GAME_INPUT **__gameinput){
    
    switch ((*__commands)->Key_UP){
    case KEY_STATE_UP:
        (*__gameinput)->fov += 1;
    break;
    case KEY_STATE_DOWN:
        
    break;
    default:break;
    };


    switch ((*__commands)->Key_DOWN){
    case KEY_STATE_UP:
        (*__gameinput)->fov -= 1;
    break;
    case KEY_STATE_DOWN:
        
    break;
    default:break;
    };
}
