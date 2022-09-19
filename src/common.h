#ifndef __common_h_
#define __common_h_

#include "glad.h"
#include <GLFW/glfw3.h>

#include "game.h"
#include "renderer.h"
#include "io.h"
#include "input.h"

#include <stdlib.h>
#include <stdio.h>


void framebuffer_size_callback(GLFWwindow *__window, int __width, int __height);  

void handle_input(GLFWwindow *__window);


#endif