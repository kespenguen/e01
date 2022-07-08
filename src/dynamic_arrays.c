#include "dynamic_arrays.h"
#include <stdio.h>
#include <string.h>

/************DYNAMIC FLOAT ARRAY**************/
void set_floatArray(floatArray *a, size_t s, float *e){
    if(e == NULL){
        a->array = malloc(s * sizeof(float));
        a->used = 0;
        a->size = s;

        for(int i = 0; i < a->size;++i){
            a->array[i] = 0.0;
        }
    }else {
        //a->array = malloc(s * sizeof(float));
        
        memcpy(a->array, e, s);
            
        a->used = ((s) / sizeof(float));
        a->size = a->used;

        printf("size: %d\n", a->size);
    }
}
void push_floatArray(floatArray *a, float e){

    if (a->used == a->size) {
      a->size *= 2;
      a->array = realloc(a->array, a->size * sizeof(float));
    }
    a->array[a->used++] = e;
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
void free_uIntArray(uIntArray *a){
    
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}
