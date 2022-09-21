#ifndef __game_h__
#define __game_h__

#include "input.h"


extern GAME_SETTINGS *settings;

//extern CMD *cmds;


// MAIN
void game_Init();
void game_Update(GLFWwindow **__window);
void game_PhysicsUpdate();

//VALUE CHANGE
void game_Fov(float __fov);

//GENERAL FUNCTIONS

void game_close();

#endif
