#ifndef __game_h__
#define __game_h__

#include "definitions.h"

extern GAME_SETTINGS lulul;

GAME_SETTINGS game_GetDefaultSettings();

void game_Start();
void game_Update();
void game_PhysicsUpdate();

void game_Fov(float __fov);

#endif
