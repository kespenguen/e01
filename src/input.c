#include "input.h"

short int binds[316] = {0};

void input_fetch(GLFWwindow **__window){
    size_t index = 0;
    //Cycle GLFW KEYS
    for(short int i = 32; i < 348;++i){
        switch(glfwGetKey(*__window,i)){
            case GLFW_RELEASE:
                binds[i] = 0;
            break;
            case GLFW_PRESS:
                binds[i] = 1;
            break;
            case GLFW_REPEAT:
                binds[i] = 2;
            break;
            default:break;
        };
        ++index;
    }
}

