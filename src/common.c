#include "common.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}  

void handle_input(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    if(glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS){
        if(FOV< 180){
            printf("sa\n");
            FOV = FOV + 1;
        }else{
            FOV = 180;
        }
    }
    if(glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS){
        if(FOV > 10){
            printf("as\n");
            FOV = FOV - 1;
        }else{
            FOV = 10;
        }
    }
}

