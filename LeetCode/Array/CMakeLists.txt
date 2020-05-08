project(Array)
add_executable(${PROJECT_NAME}
        283-move-zeroes.cpp 566-reshape-the-matrix.cpp 485-max-consecutive-ones.cpp 26-remove-duplicates-from-sorted-array.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})