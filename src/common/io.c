#include "io.h"
#include "definitions.h"
#include <stdio.h>
#include <string.h>


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
    FILE *f;

    f = fopen(__path, "r");
    if(!f)
        {printf("IO ERROR! Failed to open %s\n", __path);}

    size_t s;
        fseek(f, 0, SEEK_END);
        s = ftell(f);
        fseek(f, 0, SEEK_SET);

    char *str = malloc(s * sizeof(char));
    fread(str, sizeof(char), s, f);

    //PARSE XML
    XML_TAG doc;

    short int read_tag = 0;
        //buffertag
        char buffer_name[128];
        size_t buffer_namesize = 0;
        //bufferattribute
        char attrib_name[128];
        char *attrib_value;
        size_t  attrib_size = 0;
    
    short int skip_header = 0;
    short int run = 1;
    size_t i = 0;
    while(run == 1){
        //SKIP XML HEADER
        if(skip_header == 0){
            if(str[i] == '<' && str[i+1] == '?'){skip_header = 1;}
        }else if (skip_header == 1){
            if(str[i] == '?' + str[i] == '>'){skip_header = 3;}
        }else{
        //CONTINUE
            if(str[i] == '<'){
                memset(buffer_name, 0 , 128);
                buffer_namesize = 0;
                read_tag = 1;
                ++i;
            }
            if(read_tag == 1 && (str[i] == ' ' || str[i] == '>')){//COUNTINUE READING TAG
                if(str[i+1] != '>'){
                    
                }
            }else{
                buffer_name[buffer_namesize] = str[i];
                ++buffer_namesize;
            }


            
        }
        if(i < s){++i;}else{
            run = 0;
        }
    }

    free (str);
    free(f);
    str = NULL;
    f   = NULL;
}