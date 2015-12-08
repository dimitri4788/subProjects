#Include the header files
include_directories(${CMAKE_SOURCE_DIR}/src)

#Create test executables
add_executable(test_singlyLinkedList test_singlyLinkedList.cpp)

#Specify all the libraries to be linked with tests executables
target_link_libraries(test_singlyLinkedList singlyLinkedList_lib ${GTEST_BOTH_LIBRARIES})
