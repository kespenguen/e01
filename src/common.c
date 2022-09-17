#include "common.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}  

void handle_input(GLFWwindow *__window, CMD **__commands, GAME_INPUT **__gameinput){
    if(glfwGetKey(__window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(__window, GLFW_TRUE);
    }

    //UP ARROW
    if(glfwGetKey(__window, GLFW_KEY_UP) == GLFW_PRESS){
        (*__commands)->Key_UP = KEY_STATE_UP;
    }else{
        (*__commands)->Key_UP = KEY_STATE_DOWN;
    }

    if(glfwGetKey(__window, GLFW_KEY_DOWN) == GLFW_PRESS){
        (*__commands)->Key_DOWN = KEY_STATE_UP;
    }else{
        (*__commands)->Key_DOWN = KEY_STATE_DOWN;
    }

    handle_commands(__commands,__gameinput);
}

