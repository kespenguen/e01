#ifndef __common_h_
#define __common_h_

#include "glad.h"
#include <GLFW/glfw3.h>

#include "renderer.h"

#include <stdlib.h>
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);  

void handle_input(GLFWwindow *window);

#endif