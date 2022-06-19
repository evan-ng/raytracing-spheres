cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 14)

project(spheres)
include_directories(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(sources STATIC src/vec3.cpp ./src/canvas.cpp)

add_executable(${PROJECT_NAME} ./main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC sources)