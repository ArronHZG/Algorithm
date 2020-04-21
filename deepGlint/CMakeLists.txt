project(DeepGlint)
add_executable(${PROJECT_NAME}
        main.cpp weapon.cpp match-prior-box.cpp Matrix.cpp Matrix.h attack.cpp)
include_directories(${CMAKE_SOURCE_DIR}/utils)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})