#include "shader.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct shaderSource shader_seperate(char *source){
    struct shaderSource rVAL;

    int v_begin,f_begin,g_begin;

    //char *tmp = strtok(source,"__VERTEX__");
    size_t s = strlen(source);
    
    char *vsB = strstr(source,"__VERTEX__");
    char *vsE = strstr(source,"__VERTEX_END__");

    char *fsB = strstr(source,"__FRAGMENT__");
    char *fsE = strstr(source,"__FRAGMENT_END__");

    char *gsB = strstr(source,"__GEOMETRY__");
    char *gsE = strstr(source,"__GEOMETRY_END__");

    int vsIndex, fsIndex, gsIndex;
    int vsLenght, fsLenght, gsLenght;


    if(vsB != NULL && vsE != NULL){
        vsIndex  = (vsB - source);
        vsLenght = (vsE - source);

            vsIndex += strlen("__VERTEX__");  

                rVAL.vs = malloc(vsLenght * sizeof(char));

            vsLenght -=  strlen("__VERTEX__");
        
        memcpy(rVAL.vs,source+vsIndex,vsLenght * sizeof(char));
        rVAL.vs[vsLenght] = '\0';

        vsLenght += strlen("__VERTEX_END__");
    }else{printf("ShaderERR-> VERTEX SOURCE NOT FOUND!\n");}

    if(fsB != NULL && fsE != NULL){
        fsIndex  = (fsB - source);
        fsLenght = (fsE - source) - (vsIndex + vsLenght);

            fsIndex += strlen("__FRAGMENT__");  
            rVAL.fs = malloc(fsLenght * sizeof(char));    
            fsLenght -=  strlen("__FRAGMENT__")+1;//stupid
        
        memcpy(rVAL.fs,source+fsIndex,fsLenght * sizeof(char));
        rVAL.fs[fsLenght] = '\0';
    
    }else{printf("ShaderERR-> FRAGMENT SOURCE NOT FOUND\n");}
/*
    if(rGS != NULL && gsB != NULL && gsE != NULL){

        gsIndex  = (gsB - source);
        gsLenght = (gsE - source);

            gsIndex += strlen("__GEOMETRY__");  
            rVAL.gs = malloc(gsLenght);    
            gsLenght -=  strlen("__GEOMETRY_END__");
        
        memcpy(rVAL.gs,source+gsIndex,gsLenght);
        rVAL.gs[gsLenght] = '\0';
    
    }else{printf("ShaderINF-> GEOMETRY SOURCE NOT FOUND\n");}     
*/
 //printf("%s\n",rVS);

 return rVAL; 
}