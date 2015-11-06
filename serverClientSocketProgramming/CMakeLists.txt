cmake_minimum_required(VERSION 2.8)

#Sets the name of the project and stores the name in the PROJECT_NAME variable
project(key-value-store)

#Check for the Clang compiler location and set CMAKE_C_COMPILER and CMAKE_CXX_COMPILER
#find_program(CLANG_COMPILER Clang)
#SET(CMAKE_C_COMPILER ${CLANG_COMPILER})
#SET(CMAKE_CXX_COMPILER ${CLANG_COMPILER})

#Set the compiler flags for compiling C sources
#TODO change the optimization level back to 3
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -std=c11 -O0")

#Set the binary directory location; all the executable will be there
#   CMAKE_SOURCE_DIR points to the the top level directory
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

#A common place to put all the libraries
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

#Contains the full path to the root of project source directory
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

#Add src subdirectory to the build
add_subdirectory(src)
