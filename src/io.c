#include "io.h"
#include <stdio.h>
#include <stdlib.h>

char* io_read(const char *input){
    FILE *f;
    
    f = fopen(input, "r");
    
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