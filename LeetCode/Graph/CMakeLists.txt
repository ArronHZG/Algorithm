project(Graph)
add_executable(${PROJECT_NAME} 785-is-graph-bipartite.cpp 207-course-schedule.cpp 211-course-schedule-ii.cpp 684-redundant-connection.cpp)

include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})