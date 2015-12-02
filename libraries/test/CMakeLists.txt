#Include the header files
include_directories(${CMAKE_SOURCE_DIR}/src/singlyLinkedList
                    ${CMAKE_SOURCE_DIR}/src/doublyLinkedList)

#Create test executables
add_executable(test_singlyLinkedList test_singlyLinkedList.cpp)
add_executable(test_doublyLinkedList test_doublyLinkedList.cpp)

#Specify all the libraries to be linked with tests executables
target_link_libraries(test_singlyLinkedList singlyLinkedList_lib ${GTEST_BOTH_LIBRARIES})
target_link_libraries(test_doublyLinkedList doublyLinkedList_lib ${GTEST_BOTH_LIBRARIES})
