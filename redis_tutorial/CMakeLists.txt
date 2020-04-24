cmake_minimum_required(VERSION 3.14)
project(redis_tutorial C)

set(CMAKE_C_STANDARD 11)

include_directories(lib)

add_executable(redis_tutorial
        lib/atomicvar.h
        lib/sds.c
        lib/sds.h
        lib/sdsalloc.h
        lib/zmalloc.c
        lib/zmalloc.h
        main.c)
