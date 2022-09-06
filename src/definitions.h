#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#include <stdlib.h>

typedef struct {
    char *name;
    unsigned int layer;

    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    unsigned int IND;
    unsigned int PRG;
    unsigned int TXT;
}drawEntitiy;

typedef struct {
    drawEntitiy *array;

    size_t used;
    size_t size;
}drawArray;

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