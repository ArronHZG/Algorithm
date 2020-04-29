project(Stack)
add_executable(${PROJECT_NAME} 84-largest-rectangle-in-histogram.cpp 85-maximal-rectangle.cpp 394-decodeString.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})