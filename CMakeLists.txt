cmake_minimum_required(VERSION 3.30)
project(mugi_c C)

set(CMAKE_C_STANDARD 99)

add_executable(mugi_tests
        src/tests.c
        src/mugi.c)
