cmake_minimum_required(VERSION 3.15)
project(GenericVector C)

set(CMAKE_C_STANDARD 11)

add_executable(GenericVector main.c tVector.h tVector.c tInteger.c tInteger.h tMatrix.h tMatrix.c quickSort.c quickSort.h tDouble.c tDouble.h)