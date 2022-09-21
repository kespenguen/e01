#ifndef __dynamic_arrays_h__
#define __dynamic_arrays_h__

#include "definitions.h"

/************DYNAMIC FLOAT ARRAY**************/
void set_floatArray(floatArray *__arr, size_t __size);
void copy_floatArray(floatArray *_arr, const void *__src, size_t __size);
void push_floatArray(floatArray *_arr, float __element);
void free_floatArray(floatArray *_arr);
/**************DYNAMIC INT ARRAY**************/
void set_intArray(intArray *_arr, size_t __size);
void copy_intArray(intArray *_arr, const void *__src, size_t __size);
void push_intArray(intArray *_arr, int __element);
void free_intArray(intArray *_arr);
/*********DYNAMIC UNSIGNED INT ARRAY**********/
void set_uIntArray(uIntArray *_arr, size_t __size);
void copy_uIntArray(uIntArray *_arr, const void *__src, size_t __size);
void push_uIntArray(uIntArray *_arr, unsigned int __element);
void free_uIntArray(uIntArray *_arr);
/*************DYNAMIC DRAW ARRAY**************/
void set_drawArray(drawArray *_arr, size_t __size);
void copy_drawArray(drawArray *_arr, const void *__src, size_t __size);
void push_drawArray(drawArray *_arr, drawEntitiy *__element);
void free_drawArray(drawArray *_arr);
/*************DYNAMIC CMD ARRAY**************/
void set_CMDArray (CMD_ARRAY *_arr, size_t __size);
void copy_CMDArray(CMD_ARRAY *_arr, const void *__src, size_t __size);
void push_CMDArray(CMD_ARRAY *_arr, CMD *__element);
void free_CMDArray(CMD_ARRAY *_arr);

#endif