#ifndef __dynamic_arrays_h__
#define __dynamic_arrays_h__

#include "definitions.h"


/************DYNAMIC FLOAT ARRAY**************/
void set_floatArray(floatArray *a, size_t s);
void copy_floatArray(floatArray *a, const void *d, size_t s);
void push_floatArray(floatArray *a, float e);
void free_floatArray(floatArray *a);
/**************DYNAMIC INT ARRAY**************/
void set_intArray(intArray *a, size_t s);
void copy_intArray(intArray *a, const void *d, size_t s);
void push_intArray(intArray *a, int e);
void free_intArray(intArray *a);
/*********DYNAMIC UNSIGNED INT ARRAY**********/
void set_uIntArray(uIntArray *a, size_t s);
void copy_uIntArray(uIntArray *a, const void *d, size_t s);
void push_uIntArray(uIntArray *a, unsigned int e);
void free_uIntArray(uIntArray *a);


/*************DYNAMIC DRAW ARRAY**************/
void set_drawArray(drawArray *a, size_t s);
void copy_drawArray(drawArray *a, const void *d, size_t s);
void push_drawArray(drawArray *a, unsigned int e);
void free_drawArray(drawEntitiy *a);



#endif