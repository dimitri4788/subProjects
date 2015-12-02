cmake_minimum_required(VERSION 2.8)

#Sets the name of the project and stores the name in the PROJECT_NAME variable
project(libraries)

#Set the compiler flags for compiling C and C++ sources
#TODO change the optimization level back to 3
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11 -stdlib=libc++ -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -std=c11 -O0")

#Set the binary directory location; all the executable will be there
#   CMAKE_SOURCE_DIR points to the the top level directory
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

#A common place to put all the libraries
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

#Contains the full path to the root of project source directory
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)

#Set CMAKE_MODULE_PATH to distribute the custom CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

#Finds and loads settings from <Boost> libraries (NOTE: Only tested with versions 1.55 and 1.56)
SET(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.58.0 EXACT COMPONENTS regex log log_setup filesystem system thread coroutine context REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

#Finds and loads settings from <GTest> libraries
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#Add src and test subdirectories to the build
add_subdirectory(src)
add_subdirectory(test)

#GTest Unit Tests
enable_testing()
add_test(NAME SinglyLinkedListTest COMMAND $<TARGET_FILE:test_singlyLinkedList>)
add_test(NAME DoublyLinkedListTest COMMAND $<TARGET_FILE:test_doublyLinkedList>)
