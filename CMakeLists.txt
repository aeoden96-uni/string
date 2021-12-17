cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
project(proj)
find_package(fmt)


add_executable(proj main.cpp String.cpp String.h)
target_link_libraries(proj fmt::fmt-header-only)
