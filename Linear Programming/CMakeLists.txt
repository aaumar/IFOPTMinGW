cmake_minimum_required(VERSION 3.15)
project(LP)
find_package(ifopt)

add_library(mylib STATIC src/problem.cpp include/problem.hpp)
target_include_directories(mylib PUBLIC include/ ${ifopt_INCLUDE_DIRS})
target_link_libraries(mylib PUBLIC ${ifopt_LIBRARIES})

add_executable(${PROJECT_NAME} app/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE mylib)