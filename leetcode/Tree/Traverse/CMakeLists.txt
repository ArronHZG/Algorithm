
cmake_minimum_required(VERSION 3.15)
project(Traverse)
set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} 105-construct-binary-tree-from-preorder-and-inorder-traversal.cpp 144-binary-tree-preorder-traversal.cpp 94-binary-tree-inorder-traversal.cpp 145-binary-tree-postorder-traversal.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
