cmake_minimum_required( VERSION 3.5.0 )
message( STATUS "Cmake version: " ${CMAKE_VERSION})
project( test CXX)
set(CMAKE_CXX_STANDARD 14)
set( CMAKE_BUILD_TYPE Release)
# set( CMAKE_BUILD_TYPE Debug)


set( CMAKE_TOOLCHAIN_FILE " ")
set( TOOL_CHAIN_BASE_PATH " ")
    
#需要添加的头文件路径
include_directories(.)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(main ${DIR_SRCS})

# add_executable(${PROJECT_NAME} main.cpp)
# add_executable(test main.cpp)