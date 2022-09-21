#ifndef __input_h__
#define __input_h__

#define KEY_STATE_UP 0
#define KEY_STATE_DOWN 1
#define KEY_STATE_HELD 2

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "definitions.h"

extern short int binds[316];

void input_fetch (GLFWwindow **__window);

#endif