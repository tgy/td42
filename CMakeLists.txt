cmake_minimum_required(VERSION 2.8)
#set(PROJECT_NAME td42)
project(td42)

#set(TD42_VERSION_MAJOR 0)
#set(TD42_VERSION_MINOR 9)

set(CXX "clang++")
set(CXX_FLAGS "-Wall -Wextra -Werror -pedantic -std=c++1y")
#find_package(Threads)
#find_package(Curses REQUIRED)
#set(TD42_VERSION ${42SH_VERSION_MAJOR}.${42SH_VERSION_MINOR})
#set(CHECK_UNIT_DIR ${PROJECT_SOURCE_DIR}/check/unit)
#set(CHECK_SYSTEM_DIR ${PROJECT_SOURCE_DIR}/check/system)
set(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
#SET(CMAKE_COLOR_MAKEFILE ON)

include_directories(include)
#include_directories(./)
#include_directories(${CURSES_INCLUDE_DIR})

# The main sources for the project
file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cc)

# The test suite needed sources
#set(TMP_TEST_SOURCES ${SOURCES})
#message("CHECK_UNIT_SOURCES before removing main.c:" ${TMP_TEST_SOURCES})
#list(REMOVE_ITEM TMP_TEST_SOURCES "${SOURCE_DIR}/main.c")
#message("CHECK_UNIT_SOURCES after removing main.c:" ${TMP_TEST_SOURCES})
#file(GLOB_RECURSE CHECK_UNIT_SOURCES ${CHECK_UNIT_DIR}/*.c)
#set(CHECK_UNIT_SOURCES ${TMP_TEST_SOURCES} ${CHECK_UNIT_SOURCES})

# The main non-debug target
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(td42 PROPERTIES COMPILE_FLAGS "${CXX_FLAGS} -O3")
#target_link_libraries(42sh ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(42sh ${CURSES_LIBRARIES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

# The debug target
add_executable(debug EXCLUDE_FROM_ALL ${SOURCES})
set_target_properties(debug PROPERTIES COMPILE_FLAGS "${CXX_FLAGS} -ggdb3")
#target_link_libraries(debug ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(debug ${CURSES_LIBRARIES})

# The test suite target
#add_executable(unit EXCLUDE_FROM_ALL ${CHECK_UNIT_SOURCES})
#set_target_properties(unit PROPERTIES COMPILE_FLAGS "${C_FLAGS} -ggdb3")
#target_link_libraries(unit ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(unit ${CURSES_LIBRARIES})

# Here, the unit tests and the funtional tests
#add_custom_target(check
#  COMMAND ./run.py -r
#  COMMAND ./run.py -nd
#  WORKING_DIRECTORY ${CHECK_SYSTEM_DIR}
#  DEPENDS unit debug)

#message("Projet current version is " ${TD42_VERSION})
#message("Source directory is " ${PROJECT_SOURCE_DIR})
#message("Sources: " ${SOURCES})
#message("Check Unit Source directory is " ${CHECK_UNIT_DIR})
#message("Check Unit Sources: " ${CHECK_UNIT_SOURCES})
