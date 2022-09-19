#include "game.h"


GAME_SETTINGS game_GetDefaultSettings(){
    GAME_SETTINGS rVAL;    
        rVAL.screen_width = 800;
        rVAL.screen_height = 600;
        rVAL.vsync = 0;
        rVAL.windowtype = 1;

        rVAL.fov = 70.0f;
        rVAL.flags = RENDER_PERSPECTIVE;
    return rVAL;
}

void game_Start(){
    GAME_SETTINGS lulul = game_GetDefaultSettings();
}

void game_Update(){

}