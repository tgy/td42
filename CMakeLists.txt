cmake_minimum_required(VERSION 2.8)
project(td42)

set(CMAKE_CXX_COMPILER "clang++")
set(CXX_FLAGS "-Wall -Wextra -Werror -pedantic -std=c++1y")
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(include)

# The main sources for the project
file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cc)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics)

# The main non-debug target
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(td42 PROPERTIES COMPILE_FLAGS "${CXX_FLAGS} -O3")
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
#target_link_libraries(42sh ${CMAKE_THREAD_LIBS_INIT})

# The debug target
add_executable(debug EXCLUDE_FROM_ALL ${SOURCES})
set_target_properties(debug PROPERTIES COMPILE_FLAGS "${CXX_FLAGS} -ggdb3")
target_link_libraries(debug ${SFML_LIBRARIES})
#target_link_libraries(debug ${CMAKE_THREAD_LIBS_INIT})
