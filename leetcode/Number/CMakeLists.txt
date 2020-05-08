project(Number)
add_executable(${PROJECT_NAME}
        9-palindrome-number.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})