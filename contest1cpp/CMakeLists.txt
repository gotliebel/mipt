cmake_minimum_required(VERSION 3.21)
project(contest1)

set(CMAKE_CXX_STANDARD 14)

add_executable(contest1 main.cpp binsearch.h merge.h sort.h "kthelement.h" heap.h sum.cpp test.cpp difference.cpp multiply.cpp new.cpp)
