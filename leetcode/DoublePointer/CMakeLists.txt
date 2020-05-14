project(DoublePointer)

add_executable(${PROJECT_NAME}
        167-two-sum-ii-input-array-is-sorted.cpp
        345-reverse-vowels-of-a-string.cpp
        141-linked-list-cycle.cpp
        524-longest-word-in-dictionary-through-deleting.cpp
        125-valid-palindrome.cpp
        3-longest-substring-without-repeating-characters.cpp
        142-linked-list-cycle-ii.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})