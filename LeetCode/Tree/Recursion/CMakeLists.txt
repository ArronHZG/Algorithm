project(Recursion)
add_executable(${PROJECT_NAME} hello.cpp)
include_directories(${CMAKE_SOURCE_DIR}/Utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})