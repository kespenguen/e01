#include "input.h"

short int g_binds[316] = {0};

void input_fetch(GLFWwindow **__window){
    size_t index = 0;
    //Cycle GLFW KEYS
    for(short int i = 32; i < 348;++i){
        switch(glfwGetKey(*__window,i)){
            case GLFW_RELEASE:
                g_binds[i] = 0;
            break;
            case GLFW_PRESS:
                g_binds[i] = 1;
            break;
            case GLFW_REPEAT:
                g_binds[i] = 2;
            break;
            default:break;
        };
        ++index;
    }
}

