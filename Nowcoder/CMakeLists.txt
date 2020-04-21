project(Alibaba)
add_executable(${PROJECT_NAME}
        main.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})