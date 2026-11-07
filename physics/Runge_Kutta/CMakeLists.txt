cmake_minimum_required(VERSION 3.10)
project(orbita CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(orbita Orbita.cpp)
target_compile_options(orbita PRIVATE -Wall -Wextra -O2)