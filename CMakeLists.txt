cmake_minimum_required(VERSION 3.0.0)
project(e01 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
    e01 
        src/main.c
        src/glad.c
        src/common.c
        src/dynamic_arrays.c
        src/renderer.c
)
target_link_libraries(e01 glfw GL X11 pthread Xrandr Xi dl)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
