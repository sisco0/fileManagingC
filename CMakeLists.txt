cmake_minimum_required(VERSION 2.8.11)
project(NaiveProject)

add_subdirectory(googletest)
add_executable(myGoodApp main.c utils.h)
target_link_libraries(myGoodApp LINK_PUBLIC m)
add_executable(test test.cpp)
target_link_libraries(test gtest_main)
target_include_directories(test PUBLIC googletest/googletest/include)
