#Add library
add_library(logging_lib log.cpp)

add_executable(logging main.cpp)
target_link_libraries(logging logging_lib)
