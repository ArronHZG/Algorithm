project(Test)

add_executable(${PROJECT_NAME}
        test.cpp)

include_directories(${CMAKE_SOURCE_DIR}/Utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})
