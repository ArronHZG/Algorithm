project(LongestSubsequence)

add_executable(${PROJECT_NAME}
        1143-longest-common-subsequence.cpp
        72-edit-distance.cpp
        516-longest-palindromic-subsequence.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})