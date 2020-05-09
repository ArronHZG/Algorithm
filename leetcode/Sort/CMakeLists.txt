project(Sort)

add_executable(${PROJECT_NAME}
        215-kth-largest-element-in-an-array.cpp
        347-top-k-frequent-elements.cpp
        451-sort-characters-by-frequency.cpp
        75-sort-colors.cpp
        88-merge-sorted-array.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})