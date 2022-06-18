cmake_minimum_required(VERSION 3.1)
project(spheres)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# create executable
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# add project files
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include/")
file(GLOB SRCFILES src/*.cpp)

add_executable(${PROJECT_NAME} "main.cpp" ${SRCFILES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME})