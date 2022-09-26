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
#define CMD_PARAM_NONE       0
#define CMD_PARAM_INT        1
#define CMD_PARAM_SHORT_INT  2
#define CMD_PARAM_FLOAT      3
#define CMD_PARAM_DOUBLE     4
#define CMD_PARAM_PTR        5

typedef struct{
    void (*function)(const void *p);
    short int param;
    short int key;
}CMD;

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
    mat4 projection_matrix;

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