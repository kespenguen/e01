#ifndef __renderer_h__
#define __renderer_h__

#include "dynamic_arrays.h"
#include "texture.h"

typedef struct {
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    unsigned int IND;
    unsigned int PRG;
    unsigned int TXT;
}drawEntitiy;


void renderer_ClearBackBuffer();

void renderer_PushGeometry(floatArray *__verticies, uIntArray *__indicies,
                            unsigned int __shader, unsigned int __texture);

unsigned int renderer_CompileShader(char *shaderSource);

unsigned int renderer_GenerateTexture(const char* __texturepath);

void renderer_SetUniform(unsigned int program, const char *name,float value);

void renderer_RenderScene();

void renderer_CleanUP();

#endif

/**/