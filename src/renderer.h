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

void renderer_PushGeometry(floatArray *vert, size_t vert_size, unsigned int *ind, size_t ind_size,unsigned int shaderProgram);

unsigned int renderer_CompileShader(char *shaderSource);

void renderer_RenderScene();

void renderer_CleanUP();

#endif

/**/