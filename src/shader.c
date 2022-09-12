#include "shader.h"
#include "common.h"
#include <string.h>


void shader_GetUniforms(unsigned int __program, unsigned int **__locations, unsigned int **__amount, int __filter){

    GLint i;
    GLint count;

    GLint size; // size of the variable
    GLenum type; // type of the variable (float, vec3 or mat4, etc)

    const GLsizei bufSize = 16; // maximum name length
    GLchar name[bufSize]; // variable name in GLSL
    GLsizei length; // name length
    
    glGetProgramiv(__program, GL_ACTIVE_UNIFORMS, &count);
    printf("Active Uniforms: %d\n", count);

    unsigned int *locations = malloc(count * sizeof(unsigned int));
    unsigned int filtered_type = 0;

    for (int i = 0; i < count; i++){
        glGetActiveUniform(__program, (GLuint)i, bufSize, &length, &size, &type, name);

        if(type == __filter){
            printf("Uniform #%d Type: %u Name: %s\n", i, type, name);
            locations[filtered_type] = i;

            ++filtered_type;
        }
    }
    *__locations = locations;
    *__amount = &filtered_type;
}

void shader_SetINT(unsigned int __program, const char *__name, int __val){
    glUseProgram(__program);
    glUniform1i(glGetUniformLocation(__program, __name), __val);
}

void shader_SetINTwLOC(unsigned int __program, unsigned int __location, int __val){
    glUseProgram(__program);
    glUniform1i(__location, __val);
}


struct shaderSource shader_seperate(char *source){
    struct shaderSource rVAL;

    int v_begin,f_begin,g_begin;

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
            fsLenght -=  strlen("__FRAGMENT__")+2;// double stupid
        
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