project(huawei)
add_executable(${PROJECT_NAME} NoRepeatString.cpp decoder.cpp findWay.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})