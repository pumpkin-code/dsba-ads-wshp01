cmake_minimum_required(VERSION 3.0)

project(ADSWorkshop1 CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

#### the list of targets ####
add_executable(ex1_general ex1_general/main.cpp)        # general tasks
add_executable(ex2_employees                            # employess problem
        ex2_employees/main.cpp
        ex2_employees/employee.h
        ex2_employees/employee.cpp        
    )    

