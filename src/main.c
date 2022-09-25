#include "common/common.h"
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
      
    game_Init();

    GLFWwindow* _window = glfwCreateWindow(g_settings->screen_width, g_settings->screen_height, "(╯ ͠° ͟ʖ ͡°)╯┻━┻ ", NULL, NULL);
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

    glViewport(0, 0, g_settings->screen_width, g_settings->screen_height);
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
    #ifdef __win32__
        unsigned int x = renderer_CompileShader("res\\vertex_shader");
    #else
        unsigned int x = renderer_CompileShader("res/vertex_shader");
    #endif
    push_uIntArray(&shaderPrograms, x);

    uIntArray textures;//TEXTURE LIST
    set_uIntArray(&textures,1);
    #ifdef __win32__
        unsigned int t1 = renderer_GenerateTexture("res\\textures\\base.tga");
        unsigned int t2 = renderer_GenerateTexture("res\\textures\\base2.tga");
    #else
        unsigned int t1 = renderer_GenerateTexture("res/textures/base.tga");
        unsigned int t2 = renderer_GenerateTexture("res/textures/base2.tga");
    #endif
    push_uIntArray(&textures,t1);
    push_uIntArray(&textures,t2);

    MATERIAL_PROPERTIES m = renderer_GenerateMaterial(x,textures.array,textures.used,TEXTURE_TYPE_BLEND);
    
    renderer_PushGeometry(&scene,&vert, &ind, x, m);

    free_floatArray(&vert);

    glm_translate(**scene.array->TRN,(vec3){-1.0f,0.0f,0.0f});
    glm_rotate(**scene.array->TRN,glm_rad(-55.0f),(vec3){1.0f,0.0f,0.0f});

    renderer_UpdateProjection(&scene);
    
    /*    MAIN_LOOP     */
    while(!glfwWindowShouldClose(_window)){
        
        game_Update(&_window);
        
        renderer_ClearBackBuffer();

        renderer_RenderScene(&scene);

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

