cmake_minimum_required (VERSION 2.6)
project (strassen)

set(CMAKE_C_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_RELEASE "-O4")

add_executable (strassen_test main.c matrix.c strassen.c test.c)

