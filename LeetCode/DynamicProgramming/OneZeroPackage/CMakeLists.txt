project(OneZeroPackage)

add_executable(${PROJECT_NAME}
        Package.cpp 416-partition-equal-subset-sum.cpp 494-target-sum.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})