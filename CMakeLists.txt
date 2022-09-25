cmake_minimum_required(VERSION 3.0.0)
project(e01 VERSION 0.1.0)

include(CTest)
enable_testing()


add_executable(
    e01 
        src/main.c
        src/renderer/glad.c
        src/common/common.c
        src/common/dynamic_arrays.c
        src/common/io.c
        src/renderer/renderer.c
        src/renderer/texture.c
        src/renderer/shader.c
        src/game/game.c
        src/game/input.c
        src/game/transform.c
)

#add_compile_options(-no-pie)
target_link_libraries(e01 glfw GL X11 pthread Xrandr Xi dl m)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(EXECUTABLE_OUTPUT_PATH "../")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
include(CPack)
