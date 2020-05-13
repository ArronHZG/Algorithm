project(Design)
add_executable(${PROJECT_NAME} LRUCache.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})