#include "renderer.h"
#include "common.h"
#include "shader.h"


MATERIAL_PROPERTIES renderer_GenerateMaterial(unsigned int __shaderprogram, unsigned int *__texture,size_t __size ,unsigned char __type){
    MATERIAL_PROPERTIES rVAL;
        switch (__type){
        case TEXTURE_TYPE_SINGULAR:
            rVAL.type = TEXTURE_TYPE_SINGULAR;
            rVAL.texture = __texture;
            rVAL.texturecount = 1;
        break;
        case TEXTURE_TYPE_BLEND:
            rVAL.type = TEXTURE_TYPE_BLEND;
            rVAL.texture = malloc(__size * sizeof(unsigned int));
            rVAL.texture = __texture;
            rVAL.texturecount = __size;

            glUseProgram(__shaderprogram);
            unsigned int *l, *s;
            shader_GetUniforms(__shaderprogram,&l,&s,GL_SAMPLER_2D);
            
            if(*s != __size)
                {printf("ERROR! specified texture amount is larger than shader samplers!\n");}else{
                for(int i = 0; i < __size; ++i){
                    shader_SetINTwLOC(__shaderprogram,l[i],i);
                }
            }
            free(l);
            
        break;
        
        default: printf("err\n"); break;
        }

    return rVAL;
}

void renderer_SetUniform(unsigned int program, const char *name,float value){
    
    int vertexColorLocation = glGetUniformLocation(program, name);
    glUseProgram(program);
    glUniform4f(vertexColorLocation, 0.0f, value, 0.0f, 1.0f);
}

unsigned int renderer_GenerateTexture(const char *__texturepath){
    size_t *textureLenght;

    unsigned char *textureSource = io_readBinary(__texturepath,&textureLenght);
    if(textureSource == NULL){
        printf("MISSING OR CORRUPTED TEXTURE PATH!\n");
        return 0;
    }
    unsigned char *data = texture_parseTGA(textureSource,*textureLenght);
    if(data == NULL){
        printf("FAILED TO PARSE TGA TEXTURE!\n");
        return 0;
    }


    size_t width  =    (textureSource[13]<<8) | textureSource[12];
    size_t height =    (textureSource[15]<<8) | textureSource[14];

    //PAREMETERS
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);//WRAPING
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);//WRAPING
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);//FILTERING
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); //FILTERING
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); //MIPMAPING
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);               //MIPMAPING

    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //GEN TEXTURE
    unsigned int texture;
    glGenTextures(1, &texture); 
    glBindTexture(GL_TEXTURE_2D,texture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    //CLEAN SHIT
    free(data);
    free(textureSource);

    return texture;
}

unsigned int renderer_CompileShader(char *shaderSource){

/*VERTEX SHADER*/
    
    //Load shader from file
    char *tmp = io_read(shaderSource);

    struct shaderSource source = shader_seperate(tmp);
    free(tmp);

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, (const char**)&source.vs , NULL);
    glCompileShader(vertexShader);

    int  success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n %s", infoLog);
    }
/*FRAGMENT SHADER*/
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, (const char**)&source.fs, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n %s", infoLog);
    }

/*SHADER PROGRAM*/
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        printf("ERROR::SHADER::PROGRAM::COMPILATION_FAILED\n %s", infoLog);
    }
    
    //glUseProgram(shaderProgram);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

void renderer_UseShaderProgram(unsigned int program){
    glUseProgram(program);
}


void renderer_PushGeometry(drawArray *__scene, floatArray *__verticies,uIntArray *__indicies, 
                            unsigned int __shader, MATERIAL_PROPERTIES __texture){

    drawEntitiy tmp;

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);


    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, __verticies->size, __verticies->array, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, __indicies->size, __indicies->array, GL_STATIC_DRAW);

   // position attribute
                                                  //Sağdan sola vbo
                                                  //eleman sayısı
                                                  // vvvvvvvvvvvvv      
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);



    //glm_rotate_make(*transform, glm_rad(90.0f), GLM_ZUP); /* creates rotation matrix */
    //glm_scale_make(*transform,(vec3){0.5f, 0.5f, 0.5f});
    //glm_scale(*transform, (vec3){0.5f, 0.5f, 0.5f});

    tmp.name = "NEW";
    tmp.layer = 0;
    tmp.EBO = EBO;
    tmp.VAO = VAO;
    tmp.VBO = VBO;
    tmp.PRG = __shader;
    tmp.MAT = __texture;
    tmp.IND = __indicies->size;

    *tmp.TRN = malloc(sizeof(mat4));
    glm_translate_make(**tmp.TRN,(vec3){1.0f,0.0f,0.0f});

    push_drawArray(__scene,&tmp);
}

void renderer_RenderScene(drawArray *__scene, GAME_INPUT *__renderproperties){

    glEnable(GL_DEPTH_TEST);  

    mat4 proj = GLM_MAT4_IDENTITY_INIT;
    mat4 view = GLM_MAT4_IDENTITY_INIT;
    glm_translate(view,(vec3){0.0f, 0.0f, -3.0f}); 

    if(__renderproperties->flags == RENDER_PERSPECTIVE){
        glm_perspective(glm_rad(__renderproperties->fov),(float)__renderproperties->screen_width / (float)__renderproperties->screen_height, 0.1f,100.0f,proj);
    }
    printf("FOV: %d\n",__renderproperties->screen_width);
    for(int i = 0;i < __scene->used;++i){
        //SHADER PROGRAM
        glUseProgram(__scene->array[i].PRG);
        //TRANSFORM
        glUniformMatrix4fv(glGetUniformLocation(__scene->array[i].PRG, "model"),
                             1, GL_FALSE, **__scene->array[i].TRN[0]);
        
        glUniformMatrix4fv(glGetUniformLocation(__scene->array[i].PRG, "view"),
                             1, GL_FALSE, view[0]);

        glUniformMatrix4fv(glGetUniformLocation(__scene->array[i].PRG, "projection"),
                             1, GL_FALSE, proj[0]);
        
        //TEXTURE
        if(__scene->array[i].MAT.type == TEXTURE_TYPE_SINGULAR){
            glBindTexture(GL_TEXTURE_2D, *__scene->array[i].MAT.texture);
        }else{
            for(int j = 0;j < __scene->array[i].MAT.texturecount;++j){
                glActiveTexture(GL_TEXTURE0 + j);
                glBindTexture(GL_TEXTURE_2D, __scene->array[i].MAT.texture[j]);
               // printf("texture %d\n",__scene->array[i].MAT.texture[j]);
            }
        }
        //VERTEX ARRAY
        glBindVertexArray(__scene->array[i].VAO);
        //DRAWCALL
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //UNBIND
        glBindVertexArray(0);
    }
}

void renderer_ClearBackBuffer(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void renderer_CleanUP(){
    //glDeleteTextures(1, &n.MAT.texture);
//
    //glDeleteVertexArrays(1, &n.VAO);
    //glDeleteBuffers(1, &n.VBO);
    //glDeleteBuffers(1, &n.EBO);
}