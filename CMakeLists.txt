cmake_minimum_required(VERSION 3.12)
project(foundation)

set(CMAKE_CXX_STANDARD 14)

add_executable(foundation foundation/foundation1.cpp foundation/x.h text11111111/test11111.cpp)
add_executable(foundation2 foundation/foundation2.cpp foundation/x.h)
add_executable(foundation3 foundation/foundation3.cpp foundation/x.h )
add_executable(LinerTable Chapter1LinerTable/LinerTable.cpp )
add_executable(doubleLinerTable section1/doubleLinerTable.cpp)
add_executable(lists section1/lists.cpp)

