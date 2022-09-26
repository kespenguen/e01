#include "game.h"
#include <string.h>

//GLOBALS
GAME_SETTINGS *g_settings;
CMD *g_cmd;
size_t g_cmdsize = 0;
short int g_run = 1;

//GAME FUNCTIONS
void game_Close(){
    free (g_cmd);
    free(g_settings);
    
    g_run = 0;
}

void game_ChangeFov(const void *p){
    float *v = malloc(sizeof(float));
    memcpy(v,(float*)p,sizeof(float));
    
    g_settings->fov = *v;
        
    free(v);
    v = NULL;
}

void game_IncreaseFov()
    {g_settings->fov = g_settings->fov + 1;}

void game_DecreaseFov()
    {g_settings->fov = g_settings->fov - 1;}

void game_NewCommand(void (*__ptr), short int __param,short int __bind){
    if(g_cmd == NULL){
        g_cmd = malloc(sizeof(CMD));
    }else{
        g_cmd = (CMD *)realloc(g_cmd, (g_cmdsize + 1) * sizeof(CMD));
    }
        
        g_cmd[g_cmdsize].param      = __param;
        g_cmd[g_cmdsize].key        = __bind;

        g_cmd[g_cmdsize].function = __ptr;
        ++g_cmdsize;
}


void game_Init(){
    //LOAD SETTINGS
        g_settings = malloc(sizeof(GAME_SETTINGS));
        g_settings->screen_width = 800;
        g_settings->screen_height = 600;
        g_settings->vsync = 0;
        g_settings->windowtype = 1;
        g_settings->fov = 70.0f;
        g_settings->flags = RENDER_PERSPECTIVE;
    //LOAD RESOURCES

    //DO STUFF

    game_NewCommand(&game_Close, CMD_PARAM_NONE , GLFW_KEY_ESCAPE);
    game_NewCommand(&game_ChangeFov, CMD_PARAM_FLOAT, GLFW_KEY_ENTER);
    game_NewCommand(&game_IncreaseFov, CMD_PARAM_NONE, GLFW_KEY_KP_ADD);
    game_NewCommand(&game_DecreaseFov, CMD_PARAM_NONE, GLFW_KEY_KP_SUBTRACT);
}

void game_Update(GLFWwindow **__window){
    //GET USER INPUT
    input_fetch(__window);
    float val = 70.0f;
    for(int i = 0; i < g_cmdsize; ++i){
            if(g_binds[g_cmd[i].key] == GLFW_PRESS){
                switch(g_cmd[i].param){
                    case CMD_PARAM_NONE:
                        (*g_cmd[i].function)(NULL);
                    break;
                    case CMD_PARAM_INT:
                        (*g_cmd[i].function)(NULL);
                    break;
                    case CMD_PARAM_SHORT_INT:
                        (*g_cmd[i].function)(NULL);
                    break;
                    case CMD_PARAM_FLOAT:
                        
                        (*g_cmd[i].function)(&val);
                    break;
                    case CMD_PARAM_DOUBLE:
                        (*g_cmd[i].function)(NULL);
                    break;
                    case CMD_PARAM_PTR:
                        (*g_cmd[i].function)(NULL);
                    break;
                default:break;
                }   
            }
        }
    if(g_run == 0)
        {glfwSetWindowShouldClose(*__window, true);}
}


