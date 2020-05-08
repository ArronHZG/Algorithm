project(kuaishou)
add_executable(${PROJECT_NAME} main.cpp test.cpp howManySort.cpp arrange.cpp splitString.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})