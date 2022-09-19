#ifndef __renderer_h__
#define __renderer_h__


#include "dynamic_arrays.h"
#include "transform.h"
#include "texture.h"
#include "input.h"


void renderer_PushGeometry(drawArray *__scene, floatArray *__verticies, uIntArray *__indicies,
                            unsigned int __shader, MATERIAL_PROPERTIES __texture);

unsigned int renderer_CompileShader(char *shaderSource);

unsigned int renderer_GenerateTexture(const char* __texturepath);

MATERIAL_PROPERTIES renderer_GenerateMaterial(unsigned int __shaderprogram,unsigned int *__texture, size_t __size,unsigned char __type);

void renderer_SetUniform(unsigned int program, const char *name,float value);

void renderer_RenderScene(drawArray *__scene, GAME_SETTINGS *__settings);

void renderer_ClearBackBuffer();

void renderer_CleanUP();

#endif

/**/