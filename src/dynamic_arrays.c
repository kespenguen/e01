#include "dynamic_arrays.h"
#include <stdio.h>
#include <string.h>

/************DYNAMIC FLOAT ARRAY**************/
void set_floatArray(floatArray *__arr, size_t __size){ //INITIALIZE
    __arr->array = malloc(__size * sizeof(float));
    __arr->used = 0;
    __arr->size = __size;
    for(int i = 0; i < __arr->size;++i){
        __arr->array[i] = 0.0;
    }
}
void push_floatArray(floatArray *__arr, float __element){ //PUSH

    if (__arr->used == __arr->size) {
      __arr->size *= 2;
      __arr->array = realloc(__arr->array, __arr->size * sizeof(float));
    }
    __arr->array[__arr->used++] = __element;
}
void copy_floatArray(floatArray *__arr, const void *__src, size_t __size){ //COPY

    __arr->array = malloc(__size);

    memcpy(__arr->array,(float*)__src,__size);

    __arr->used = __size / sizeof(float);
    __arr->size = __size;
}
void free_floatArray(floatArray *__arr){ // FREE
    
    free(__arr->array);
    __arr->array = NULL;
    __arr->used = __arr->size = 0;
}

/***********DYNAMIC INT ARRAY*****************/
void set_intArray(intArray *__arr, size_t __size){ //INITIALIZE
    
    __arr->array = malloc(__size * sizeof(int));
    __arr->used = 0;
    __arr->size = __size;

    for(int i = 0; i < __arr->size;++i){
        __arr->array[i] = 0;
    }
}
void push_intArray(intArray *__arr, int __element){ //PUSH

    if (__arr->used == __arr->size) {
      __arr->size *= 2;
      __arr->array = realloc(__arr->array, __arr->size * sizeof(int));
    }
    __arr->array[__arr->used++] = __element;
}
void copy_intArray(intArray *__arr, const void *__src, size_t __size){ //COPY

    __arr->array = malloc(__size);

    memcpy(__arr->array,(int*)__src,__size);

    __arr->used = __size / sizeof(int);
    __arr->size = __size;
}
void free_intArray(intArray *__arr){ //FREE
    
    free(__arr->array);
    __arr->array = NULL;
    __arr->used = __arr->size = 0;
}

/*********DYNAMIC UNSIGNED INT ARRAY**********/
void set_uIntArray(uIntArray *__arr, size_t __size){ //INITIALIZE
    
    __arr->array = malloc(__size * sizeof(unsigned int));
    __arr->used = 0;
    __arr->size = __size;

    for(int i = 0; i < __arr->size;++i){
        __arr->array[i] = 0;
    }
}
void push_uIntArray(uIntArray *__arr, unsigned int __element){ //PUSH

    if (__arr->used == __arr->size) {
      __arr->size *= 2;
      __arr->array = realloc(__arr->array, __arr->size * sizeof(unsigned int));
    }
    __arr->array[__arr->used++] = __element;
}
void copy_uIntArray(uIntArray *__arr, const void *__src, size_t __size){ //COPY

    __arr->array = malloc(__size);

    memcpy(__arr->array,(unsigned int*)__src,__size);

    __arr->used = __size / sizeof(unsigned int);
    __arr->size = __size;
}
void free_uIntArray(uIntArray *__arr){ //FREE
    
    free(__arr->array);
    __arr->array = NULL;
    __arr->used = __arr->size = 0;
}

/************DYNAMIC DRAW ARRAY**************/
void set_drawArray(drawArray *__arr, size_t __size){ //INITIALIZE
    __arr->array = malloc(__size * sizeof(drawEntitiy));
    __arr->used = 0;
    __arr->size = __size;

    drawEntitiy def;
    for(int i = 0; i < __size;++i){

        __arr->array[i] = def;
    }
}
void push_drawArray(drawArray *__arr, drawEntitiy *__element){ //PUSH

    if (__arr->used == __arr->size) {
      __arr->size *= 2;
      __arr->array = realloc(__arr->array, __arr->size * sizeof(drawEntitiy));
    }
    __arr->array[__arr->used++] = *__element;
}
void copy_drawArray(drawArray *__arr, const void *__src, size_t __size){ //COPY

    __arr->array = malloc(__size);

    memcpy(__arr->array,(float*)__src,__size);

    __arr->used = __size / sizeof(float);
    __arr->size = __size;
}
void free_drawArray(drawArray *__arr){ //FREE

    free(*__arr->array->TRN);
    *__arr->array->TRN = NULL;

    free(__arr->array);

    __arr->array = NULL;
    __arr->used = __arr->size = 0;
}