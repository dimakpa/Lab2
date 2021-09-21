cmake_minimum_required(VERSION 3.17)
project(Lab2)

set(CMAKE_CXX_STANDARD 20)
include_directories(Google_tests/lib/googletest-master/googletest)

add_executable(Lab2 main.cpp " Messeges.cpp" cmake-build-debug/ Messege.h Epycycloid.h Epycycloid.cpp )
