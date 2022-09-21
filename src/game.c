#include "game.h"

GAME_SETTINGS *settings;
CMD cmds;


void game_Init(){
    //LOAD SETTINGS
        settings = malloc(sizeof(GAME_SETTINGS));
        settings->screen_width = 800;
        settings->screen_height = 600;
        settings->vsync = 0;
        settings->windowtype = 1;
        settings->fov = 70.0f;
        settings->flags = RENDER_PERSPECTIVE;
    //LOAD RESOURCES

    //DO STUFF

        cmds.function = &game_close;
        cmds.key = 259;
    //game_BindCMD(game_close,GLFW_KEY_ESCAPE);
}

void game_Update(GLFWwindow **__window){
    //GET USER INPUT
    input_fetch(__window);

    for(int i = 0; i < 1; ++i){
        
        int k = 256 - 32;
        
        if(binds[GLFW_KEY_ESCAPE] == GLFW_PRESS){
           (*cmds.function)();
        }
    }
}
//    void (*function)();


void game_close(){
    free(settings);
    
    printf("pls close :(\n");
}