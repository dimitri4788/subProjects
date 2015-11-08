#Include the header files
include_directories(${CMAKE_SOURCE_DIR}/src/log)

#Create test executables
add_executable(test_log test_log.c)

#Specify all the libraries to be linked with tests executables
target_link_libraries(test_log log_lib)
