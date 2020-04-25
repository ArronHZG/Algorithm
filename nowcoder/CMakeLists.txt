project(Nowcoder)
add_executable(${PROJECT_NAME}
        seqSum.cpp sequenceSum.cpp countLR.cpp  cakeNumber.cpp  selectPresent.cpp increasingArray.cpp maxPresent.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})