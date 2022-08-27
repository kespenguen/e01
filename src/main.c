#include "common.h"
#include <string.h>
#include <math.h>

int main(){
    
    /********************/
    /*    INIT_GLFW     */
    /********************/
    if(!glfwInit()){
        fprintf(stderr, "GLFW Init Failed!\n");
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); MacOS shit
  
    GLFWwindow* _window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (_window == NULL){
        printf("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(_window);

    /********************/
    /*    LOAD_GLAD     */
    /********************/
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("Failed to initialize GLAD");
        return -1;
    }  

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);


    

    float vertices[] = {
         0.5,  0.5, 0.0,  // top right
         0.5, -0.5, 0.0,  // bottom right
        -0.5, -0.5, 0.0,  // bottom left
        -0.5,  0.5, 0.0   // top left 
    };

    unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };  

    floatArray vert;
    set_floatArray(&vert,12);
    copy_floatArray(&vert,vertices,sizeof(vertices));

    uIntArray ind;
    set_uIntArray(&ind,6);
    copy_uIntArray(&ind,indices,sizeof(indices));

    uIntArray shaderPrograms;
    set_uIntArray(&shaderPrograms,1);

    unsigned int x = renderer_CompileShader("/home/od/e01/res/vertex_shader");
    push_uIntArray(&shaderPrograms, x);
    
    renderer_PushGeometry(&vert, &ind, x);
    free_floatArray(&vert);

    /********************/
    /*    MAIN_LOOP     */
    /********************/
    while(!glfwWindowShouldClose(_window)){
        handle_input(_window);
        float time = glfwGetTime();
        float greenValue = (sin(time) / 2.0f) + 0.5f;
        renderer_SetUniform(x,"ourColor", greenValue);

        renderer_ClearBackBuffer();

        renderer_RenderScene();

        glfwSwapBuffers(_window);
        glfwPollEvents();    
    }
    
    /********************/
    /*    EXIT_PROG     */
    /********************/

    free_uIntArray(&shaderPrograms);
    //renderer_CleanUP();
    glfwTerminate();
    return 0;
}

