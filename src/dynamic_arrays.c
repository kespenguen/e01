#include "dynamic_arrays.h"
#include <stdio.h>
#include <string.h>

/************DYNAMIC FLOAT ARRAY**************/
void set_floatArray(floatArray *a, size_t s){
    a->array = malloc(s * sizeof(float));
    a->used = 0;
    a->size = s;
    for(int i = 0; i < a->size;++i){
        a->array[i] = 0.0;
    }
}
void push_floatArray(floatArray *a, float e){

    if (a->used == a->size) {
      a->size *= 2;
      a->array = realloc(a->array, a->size * sizeof(float));
    }
    a->array[a->used++] = e;
}
void copy_floatArray(floatArray *a, const void *d, size_t s){

    a->array = malloc(s);

    memcpy(a->array,(float*)d,s);

    a->used = s / sizeof(float);
    a->size = s;
}
void free_floatArray(floatArray *a){
    
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}
/***********DYNAMIC INT ARRAY*****************/
void set_intArray(intArray *a, size_t s){
    
    a->array = malloc(s * sizeof(int));
    a->used = 0;
    a->size = s;

    for(int i = 0; i < a->size;++i){
        a->array[i] = 0;
    }
}
void push_intArray(intArray *a, int e){

    if (a->used == a->size) {
      a->size *= 2;
      a->array = realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = e;
}
void copy_intArray(intArray *a, const void *d, size_t s){

    a->array = malloc(s);

    memcpy(a->array,(int*)d,s);

    a->used = s / sizeof(int);
    a->size = s;
}
void free_intArray(intArray *a){
    
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}
/*********DYNAMIC UNSIGNED INT ARRAY**********/
void set_uIntArray(uIntArray *a, size_t s){
    
    a->array = malloc(s * sizeof(unsigned int));
    a->used = 0;
    a->size = s;

    for(int i = 0; i < a->size;++i){
        a->array[i] = 0;
    }
}
void push_uIntArray(uIntArray *a, unsigned int e){

    if (a->used == a->size) {
      a->size *= 2;
      a->array = realloc(a->array, a->size * sizeof(unsigned int));
    }
    a->array[a->used++] = e;
}
void copy_uIntArray(uIntArray *a, const void *d, size_t s){

    a->array = malloc(s);

    memcpy(a->array,(unsigned int*)d,s);

    a->used = s / sizeof(unsigned int);
    a->size = s;
}
void free_uIntArray(uIntArray *a){
    
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}
/************DYNAMIC DRAW ARRAY**************/
void set_drawArray(drawArray *a, size_t s){
    a->array = malloc(s * sizeof(drawArray));
    a->used = 0;
    a->size = s;
    for(int i = 0; i < a->size;++i){
        drawArray x;
        a->array[i] = x;
    }
}
void push_drawArray(drawArray *a, float e){

    if (a->used == a->size) {
      a->size *= 2;
      a->array = realloc(a->array, a->size * sizeof(float));
    }
    a->array[a->used++] = e;
}
void copy_drawArray(drawArray *a, const void *d, size_t s){

    a->array = malloc(s);

    memcpy(a->array,(float*)d,s);

    a->used = s / sizeof(float);
    a->size = s;
}
void free_drawArray(drawArray *a){
    
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}