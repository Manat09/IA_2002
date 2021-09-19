# cmake_minimum_required(VERSION <specify CMake version here>)
project(L1_IA2002_master)

set(CMAKE_CXX_STANDARD 14)

include_directories(L1_IA2002-master)

add_executable(L1_IA2002_master
        L1_IA2002-master/Character.cpp
        L1_IA2002-master/Character.h
        L1_IA2002-master/Enemy.cpp
        L1_IA2002-master/Enemy.h
        L1_IA2002-master/Fight.cpp
        L1_IA2002-master/Fight.h
        L1_IA2002-master/Game.cpp
        L1_IA2002-master/Game.h
        L1_IA2002-master/Item.cpp
        L1_IA2002-master/Item.h
        L1_IA2002-master/main.cpp)
