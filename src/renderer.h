#ifndef __renderer_h__
#define __renderer_h__

#include "dynamic_arrays.h"


typedef struct {
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    unsigned int IND;
    unsigned int PRG;
}drawEntitiy;


void renderer_ClearBackBuffer();

void renderer_PushGeometry(floatArray *vert, uIntArray *ind,unsigned int shaderProgram);

unsigned int renderer_CompileShader(char *shaderSource);

void renderer_RenderScene();

void renderer_CleanUP();

#endif

/**/