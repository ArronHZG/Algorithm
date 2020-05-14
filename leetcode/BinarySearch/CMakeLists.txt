project(BinarySearch)
add_executable(${PROJECT_NAME} 69-sqrtx.cpp
        744-find-smallest-letter-greater-than-target.cpp
        540-single-element-in-a-sorted-array.cpp
        278-first-bad-version.cpp
        153-find-minimum-in-rotated-sorted-array.cpp
        34-find-first-and-last-position-of-element-in-sorted-array.cpp
        154-find-minimum-in-rotated-sorted-array-ii.cpp
        633-sum-of-square-numbers.cpp
        680-valid-palindrome-ii.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})