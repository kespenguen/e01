#ifndef __shader_h__
#define __shader_h__

struct shaderSource{
    char *vs;
    char *fs;
    char *gs;
};

struct shaderSource shader_seperate(char *source);

void shader_GetUniforms(unsigned int __program, unsigned int **__locations, unsigned int **__amount, int __filter);
void shader_GetAttributes();

void shader_SetINT(unsigned int __program, const char *__name, int __val);
void shader_SetINTwLOC(unsigned int __program, unsigned int __location, int __val);


#endif