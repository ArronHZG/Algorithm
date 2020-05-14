project(DynamicProgramming)
add_executable(${PROJECT_NAME} 221-maximal-square.cpp 1277-count-square-submatrices-with-all-ones.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})

add_subdirectory(ArrayInterval)
add_subdirectory(FibonacciSequence)
add_subdirectory(MatrixPath)
add_subdirectory(NumberSubsequence)
add_subdirectory(SplitInteger)
add_subdirectory(StringSequence)
add_subdirectory(OneZeroPackage)