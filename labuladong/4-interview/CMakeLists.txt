project(4-interview)
add_executable(${PROJECT_NAME})
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})