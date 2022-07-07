#include "common.h"
 

int main()
{
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
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };  
    renderer_PushVertexBuffer(vertices,sizeof(vertices));
    
    renderer_CompileShader("gg");

    /********************/
    /*    MAIN_LOOP     */
    /********************/
    while(!glfwWindowShouldClose(_window)){
        handle_input(_window);

        renderer_ClearBackBuffer();

        renderer_RenderScene();

        glfwSwapBuffers(_window);
        glfwPollEvents();    
    }
    
    /********************/
    /*    EXIT_PROG     */
    /********************/

    return 0;
}

