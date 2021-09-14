cmake_minimum_required(VERSION 3.5.1)

# project information
project(cool)

# Compile options
add_compile_options(-std=c++11)

# Specify target generation path
set(CMAKE_INSTALL_PREFIX "/usr/local")

set(CMAKE_CXX_FLAGS_DEBUG "-fPIC -O0 -g -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "-fPIC -O2 -Wall")



set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_RPATH}:/usr/local/ev_sdk/lib:/usr/local/3rd/release/libevent/lib")

# Header path
include_directories()

# add  lib path
link_directories()

file (GLOB COOL_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME}
               ${COOL_SOURCES}
              )

target_link_libraries(${PROJECT_NAME}
        pthread
        glog 
        )

INSTALL(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/cool)

