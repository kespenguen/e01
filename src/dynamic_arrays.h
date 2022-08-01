#ifndef __dynamic_arrays_h__
#define __dynamic_arrays_h__

#include <stdlib.h>


/************DYNAMIC FLOAT ARRAY**************/
typedef struct{
    float *array;
    size_t used;
    size_t size;
}floatArray;

void set_floatArray(floatArray *a, size_t s);
void copy_floatArray(floatArray *a, const void *d, size_t s);
void push_floatArray(floatArray *a, float e);
void free_floatArray(floatArray *a);
/**************DYNAMIC INT ARRAY**************/
typedef struct{
    int *array;
    size_t used;
    size_t size;
}intArray;

void set_intArray(intArray *a, size_t s);
void copy_intArray(intArray *a, const void *d, size_t s);
void push_intArray(intArray *a, int e);
void free_intArray(intArray *a);
/*********DYNAMIC UNSIGNED INT ARRAY**********/
typedef struct {
    unsigned int *array;
    size_t used;
    size_t size;
}uIntArray;

void set_uIntArray(uIntArray *a, size_t s);
void copy_uIntArray(uIntArray *a, const void *d, size_t s);
void push_uIntArray(uIntArray *a, unsigned int e);
void free_uIntArray(uIntArray *a);

#endif