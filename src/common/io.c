#include "io.h"
#include <stdio.h>
#include <stdlib.h>

char* io_read(const char *__path){
    FILE *f;
    
    f = fopen(__path, "r");
    if(!f){
        printf("IO ERROR! Failed to open %s\n", __path);
    }
    
    size_t s;
        fseek(f, 0, SEEK_END);
        s = ftell(f);
        fseek(f, 0, SEEK_SET);

    char *tmp = NULL;
        tmp = malloc(s *sizeof(char));
    fread(tmp, sizeof(char), s, f);

    fclose(f); 
    return tmp;
}

unsigned char* io_readBinary(const char *__path, size_t **__lenght){
    FILE *f;

    f = fopen(__path , "rb");

    if(!f){
        printf("IO ERROR! Failed to open %s\n",__path);
        *__lenght = 0;
        return NULL;
    }

    size_t s;
        fseek(f, 0 , SEEK_END);
        s = ftell(f)+1;
        fseek(f, 0, SEEK_SET);
    
    unsigned char *tmp = NULL;
        tmp = malloc(s *sizeof(char));
    
    fread(tmp, sizeof(char), s, f);

    fclose(f);
    *__lenght = &s;
    
    return tmp;
}

void io_ParseCollada(const char *__path){
    FILE *f;
    
    f = fopen(__path, "r");
    if(!f){
        printf("IO ERROR! Failed to open %s\n", __path);
    }
    
    size_t s;
        fseek(f, 0, SEEK_END);
        s = ftell(f);
        fseek(f, 0, SEEK_SET);

    
    char *str = malloc(s * sizeof(char));


    for(size_t i = 0; i < s; ++i){
       
    }

    fclose(f); 
    
}


void io_ParseXML(const char *__path){
    char *f = io_read(__path);



    free(f);
    f = NULL;
}