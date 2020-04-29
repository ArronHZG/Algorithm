project(String)
add_executable(${PROJECT_NAME} 43-multiply-strings.cpp 415-add-strings.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})