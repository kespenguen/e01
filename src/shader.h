#ifndef __shader_h__
#define __shader_h__

struct shaderSource{
    char *vs;
    char *fs;
    char *gs;
};

struct shaderSource shader_seperate(char *source);

#endif