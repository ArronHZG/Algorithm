project(Backtracking)

add_executable(${PROJECT_NAME}
        17-letter-combinations-of-a-phone-number.cpp
        93-restore-ip-addresses.cpp
        79-word-search.cpp
        257-binary-tree-paths.cpp
        77-combinations.cpp
        39-combination-sum.cpp
        40-combination-sum-ii.cpp
        216-combination-sum-iii.cpp
        78-subsets.cpp
        131-palindrome-partitioning.cpp
        sudoku-solver.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})