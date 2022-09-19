#include "input.h"

BINDS binds;

void update_binds(BINDS __binds){
    binds = __binds;
    handle_commands();
}

void handle_commands (){
    
    switch (binds.Key_UP){
    case KEY_STATE_UP:
       
    break;
    case KEY_STATE_DOWN:
        
    break;
    case KEY_STATE_HELD:

    break;
    default:break;
    };


    switch (binds.Key_DOWN){
    case KEY_STATE_UP:
        
    break;
    case KEY_STATE_DOWN:
        
    break;
    case KEY_STATE_HELD:

    break;
    default:break;
    };
}
/*    //UP ARROW
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

    handle_commands(__commands,__settings);*/