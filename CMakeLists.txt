cmake_minimum_required(VERSION 3.25)
project(cpp_exam)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_exam main.cpp
        functions/exponenta.cpp
        functions/hiperbola.cpp
        functions/parabola.cpp
        functions/polinom.cpp)