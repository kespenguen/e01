#include "renderer.h"
#include "common.h"
#include "shader.h"


MATERIAL_PROPERTIES renderer_AssignTexture(unsigned int __texture ,unsigned char __type){
    MATERIAL_PROPERTIES rVAL;
        switch (__type){
        case TEXTURE_TYPE_SINGULAR:
            rVAL.type = __type;
            rVAL.texture = __texture;
            rVAL.texturecount = 1;
            printf("TEXTURE_TYPE_SINGULAR\n");
        break;
        case TEXTURE_TYPE_BLEND:
            printf("TEXTURE_TYPE_BLEND\n");
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
    if(data != NULL)
        {printf("success!\n");}


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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    tmp.name = "NEW";
    tmp.layer = 0;
    tmp.EBO = EBO;
    tmp.VAO = VAO;
    tmp.VBO = VBO;
    tmp.PRG = __shader;
    tmp.MAT  = __texture;
    tmp.IND = __indicies->size;
    push_drawArray(__scene,&tmp);
}

void renderer_RenderScene(drawArray *__scene){
    for(int i = 0;i < __scene->used;++i){
        glUseProgram(__scene->array[i].PRG);
        glBindTexture(GL_TEXTURE_2D, __scene->array[i].MAT.texture);
        glBindVertexArray(__scene->array[i].VAO);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
    }
}

void renderer_ClearBackBuffer(){
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void renderer_CleanUP(){
    //glDeleteTextures(1, &n.MAT.texture);
//
    //glDeleteVertexArrays(1, &n.VAO);
    //glDeleteBuffers(1, &n.VBO);
    //glDeleteBuffers(1, &n.EBO);
}