cmake_minimum_required(VERSION 3.15)
project(GenericVector C)

set(CMAKE_C_STANDARD 11)

add_executable(GenericVector main.c vector.h vector.c tInteger.c tInteger.h matrix.h matrix.c)