#include "common.h"


void framebuffer_size_callback(GLFWwindow* __window, int __width, int __height){
    glViewport(0, 0, __width, __height);
}  

void handle_input(GLFWwindow *__window){
    BINDS tmp;
    //ESCAPE
    if(glfwGetKey(__window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(__window, GLFW_TRUE);
        if(tmp.Key_ESCAPE == KEY_STATE_DOWN){
            tmp.Key_ESCAPE = KEY_STATE_HELD;
        }else{
            tmp.Key_ESCAPE = KEY_STATE_DOWN;
        }
    }else   {tmp.Key_ESCAPE = KEY_STATE_UP;}
    //UP ARROW
    if(glfwGetKey(__window, GLFW_KEY_UP) == GLFW_PRESS){
        if(tmp.Key_UP == KEY_STATE_DOWN){
            tmp.Key_UP = KEY_STATE_HELD;
        }else{
            tmp.Key_UP = KEY_STATE_DOWN;
        }
    }else   {tmp.Key_UP = KEY_STATE_UP;}
    //DOWN ARROW
    if(glfwGetKey(__window, GLFW_KEY_DOWN) == GLFW_PRESS){
        if(tmp.Key_DOWN == KEY_STATE_DOWN){
            tmp.Key_DOWN = KEY_STATE_HELD;
        }else{
            tmp.Key_DOWN = KEY_STATE_DOWN;
        }
    }else   {tmp.Key_DOWN = KEY_STATE_UP;}
    //LEFT ARROW
    if(glfwGetKey(__window, GLFW_KEY_LEFT) == GLFW_PRESS){
        if(tmp.Key_LEFT == KEY_STATE_DOWN){
            tmp.Key_LEFT = KEY_STATE_HELD;
        }else{
            tmp.Key_LEFT = KEY_STATE_DOWN;
        }
    }else   {tmp.Key_LEFT = KEY_STATE_UP;}
    //RIGHT ARROW
    if(glfwGetKey(__window, GLFW_KEY_RIGHT) == GLFW_PRESS){
        if(tmp.Key_RIGHT == KEY_STATE_DOWN){
            tmp.Key_RIGHT = KEY_STATE_HELD;
        }else{
            tmp.Key_RIGHT = KEY_STATE_DOWN;
        }
    }else   {tmp.Key_RIGHT = KEY_STATE_UP;}
    //ENTER
    if(glfwGetKey(__window, GLFW_KEY_ENTER) == GLFW_PRESS){
        if(tmp.Key_ENTER == KEY_STATE_DOWN){
            tmp.Key_ENTER = KEY_STATE_HELD;
        }else{
            tmp.Key_ENTER = KEY_STATE_DOWN;
        }
    }else   {tmp.Key_ENTER = KEY_STATE_UP;}
    //SPACE
    if(glfwGetKey(__window, GLFW_KEY_SPACE) == GLFW_PRESS){
        if(tmp.Key_SPACE == KEY_STATE_DOWN){
            tmp.Key_SPACE = KEY_STATE_HELD;
        }else{
            tmp.Key_SPACE = KEY_STATE_DOWN;
        }
    }else   {tmp.Key_SPACE = KEY_STATE_UP;}
    //SHIFT
    if(glfwGetKey(__window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS){
        if(tmp.Key_SHIFT == KEY_STATE_DOWN){
            tmp.Key_SHIFT = KEY_STATE_HELD;
        }else{
            tmp.Key_SHIFT = KEY_STATE_DOWN;
        }
    }else   {tmp.Key_SHIFT = KEY_STATE_UP;}

    update_binds(tmp);
}

