cmake_minimum_required(VERSION 3.22)
project(ced LANGUAGES CXX)
find_package(CUDAToolkit)
set(CMAKE_CXX_FLAGS "-fopenmp")

add_executable(farao
 farao.cpp
 f.cpp
 soma_integral.cpp
 heat_diffusion_2d.cpp
 farao.h
)
