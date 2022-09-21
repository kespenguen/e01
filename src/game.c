#include "game.h"

GAME_SETTINGS *settings;
CMD_ARRAY cmds;

GAME_SETTINGS *game_GetDefaultSettings(){
    GAME_SETTINGS *rVAL;    
        rVAL->screen_width = 800;
        rVAL->screen_height = 600;
        rVAL->vsync = 0;
        rVAL->windowtype = 1;

        rVAL->fov = 70.0f;
        rVAL->flags = RENDER_PERSPECTIVE;

    return rVAL;
}

void game_Init(){
    //LOAD SETTINGS
    settings = game_GetDefaultSettings();
    //LOAD RESOURCES

    //DO STUFF
    set_CMDArray(&cmds,1);
    game_BindCMD(&game_close,GLFW_KEY_ESCAPE);
}

void game_Update(GLFWwindow **__window){
    //GET USER INPUT
    input_fetch(__window);

}

void game_BindCMD(void *__function, short int __key){
    CMD tmp;
        tmp.function = __function;
        tmp.key = __key;
    push_CMDArray(cmds,&tmp);
}

void game_close(){
    printf("pls close :(\n");
}