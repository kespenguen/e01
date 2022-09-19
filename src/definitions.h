#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#include <stdlib.h>
#include <cglm/cglm.h>

/****** GAME DEFINITONS *****/

typedef struct{
    //SCREEN
    int screen_width;
    int screen_height;
    short int vsync;
    short int windowtype;

    //GRAPHICS
    float fov;
    short flags;
}GAME_SETTINGS;

typedef struct{
    void *function;
    int bind;
}CMD;

typedef struct{
    CMD *array;
    
    size_t used;
    size_t size;
}CMD_ARRAY;

/****** RENDERER DEFINITIONS *****/
#define RENDER_PERSPECTIVE  1
#define RENDER_ORTHOGRAPHIC 2

typedef struct {
   unsigned char type;
   unsigned int *texture;
   size_t texturecount;
} MATERIAL_PROPERTIES;

typedef struct {
    char *name;
    unsigned int layer;

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    unsigned int IND;
    unsigned int PRG;
    mat4 **TRN;
    MATERIAL_PROPERTIES MAT;
}drawEntitiy;

typedef struct {
    drawEntitiy *array;

    size_t used;
    size_t size;
}drawArray;

/*****  GENERAL DEFINITONS  *****/
typedef struct{
    float *array;
    size_t used;
    size_t size;
}floatArray;

typedef struct{
    int *array;
    size_t used;
    size_t size;
}intArray;

typedef struct {
    unsigned int *array;
    size_t used;
    size_t size;
}uIntArray;

#endif