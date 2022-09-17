#include "common.h"
#include <string.h>

int main(){
    /*    INIT_GLFW     */
    if(!glfwInit()){
        fprintf(stderr, "GLFW Init Failed!\n");
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MacOS shit
  
    GAME_INPUT input;
        input.fov = 70.0f;
        input.screen_width = 800;
        input.screen_height = 600;
        input.flags = RENDER_PERSPECTIVE;
    GAME_INPUT *inputptr = &input;
    
    CMD cmd;
        cmd.Key_DOWN = 0;
        cmd.Key_UP = 0;
    CMD *cmdptr = &cmd;

    GLFWwindow* _window = glfwCreateWindow(inputptr->screen_width, inputptr->screen_height, "(╯ ͠° ͟ʖ ͡°)╯┻━┻ ", NULL, NULL);
    if (_window == NULL){
        printf("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(_window);


    /*    LOAD_GLAD     */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("Failed to initialize GLAD");
        return -1;
    }  

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

    drawArray scene;
    set_drawArray(&scene,1);
    
    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,      1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,      1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,      0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,      0.0f, 1.0f    // top left 
    };

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };  

    floatArray vert;
    set_floatArray(&vert,20);
    copy_floatArray(&vert,vertices,sizeof(vertices));

    uIntArray ind;
    set_uIntArray(&ind,6);
    copy_uIntArray(&ind,indices,sizeof(indices));

    uIntArray shaderPrograms;//SHADER LIST
    set_uIntArray(&shaderPrograms,1);
    unsigned int x = renderer_CompileShader("/home/od/e01/res/vertex_shader");
    push_uIntArray(&shaderPrograms, x);

    uIntArray textures;//TEXTURE LIST
    set_uIntArray(&textures,1);
    unsigned int t1 = renderer_GenerateTexture("/home/od/e01/res/textures/base.tga");
    unsigned int t2 = renderer_GenerateTexture("/home/od/e01/res/textures/base2.tga");
    push_uIntArray(&textures,t1);
    push_uIntArray(&textures,t2);

    MATERIAL_PROPERTIES m = renderer_GenerateMaterial(x,textures.array,textures.used,TEXTURE_TYPE_BLEND);
    

    renderer_PushGeometry(&scene,&vert, &ind, x, m);

    free_floatArray(&vert);
//glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)); 

    glm_translate(**scene.array->TRN,(vec3){-1.0f,0.0f,0.0f});
    glm_rotate(**scene.array->TRN,glm_rad(-55.0f),(vec3){1.0f,0.0f,0.0f});
    /*    MAIN_LOOP     */
    while(!glfwWindowShouldClose(_window)){
        handle_input(_window,&cmdptr,&inputptr);

        renderer_ClearBackBuffer();

        renderer_RenderScene(&scene,inputptr);

        glfwSwapBuffers(_window);
        glfwPollEvents();    
    }
    

    
    /*    EXIT_PROG     */
    free_drawArray(&scene);
    free_uIntArray(&shaderPrograms);
    free_uIntArray(&textures);
    
    renderer_CleanUP();
    glfwTerminate();
    return 0;
}

