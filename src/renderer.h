#ifndef __renderer_h__
#define __renderer_h__

#include "common.h"

typedef struct ent{
    
};

void renderer_ClearBackBuffer();

void renderer_PushVertexBuffer(float *vert,int size);

void renderer_CompileShader(char *shaderSource);

void renderer_RenderScene();

#endif

/**/