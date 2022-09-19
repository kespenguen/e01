#ifndef __input_h__
#define __input_h__

#define KEY_STATE_UP 0
#define KEY_STATE_DOWN 1
#define KEY_STATE_HELD 2

#include "definitions.h"

typedef struct{
    short int Key_UP;
    short int Key_DOWN;
    short int Key_LEFT;
    short int Key_RIGHT;
    short int Key_ESCAPE;
    short int Key_ENTER;
    short int Key_SPACE;
    short int Key_SHIFT;
    
}BINDS;


void update_binds (BINDS __binds);
void handle_commands ();

#endif