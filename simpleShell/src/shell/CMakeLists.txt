#Include the header files
include_directories(${CMAKE_SOURCE_DIR}/src/log)

#Add executables
add_executable(simpleShell shell.c)

#Link libraries
target_link_libraries(simpleShell log_lib)
