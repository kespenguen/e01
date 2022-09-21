#ifndef __game_h__
#define __game_h__

#include "input.h"


extern GAME_SETTINGS *settings;

extern CMD_ARRAY cmds;

GAME_SETTINGS *game_GetDefaultSettings();

// MAIN
void game_Init();
void game_Update(GLFWwindow **__window);
void game_PhysicsUpdate();

//VALUE CHANGE
void game_Fov(float __fov);

//GENERAL FUNCTIONS
void game_BindCMD(void *__function, short int __key);

void game_close();

#endif
