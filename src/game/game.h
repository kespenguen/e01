#ifndef __game_h__
#define __game_h__

#include "input.h"


extern GAME_SETTINGS *g_settings;


extern CMD *g_cmd;
extern size_t g_cmdsize;


// MAIN
void game_Init();
void game_Update(GLFWwindow **__window);
void game_PhysicsUpdate();

//VALUE CHANGE
void game_Fov(float __fov);

//GENERAL FUNCTIONS
void game_NewCommand(void (*__ptr), short int __param, short int __bind);

//GAME FUNCTIONS
void game_IncreaseFov();
void game_DecreaseFov();
void game_ChangeFov(float __fov);
void game_close();

#endif