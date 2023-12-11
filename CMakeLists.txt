cmake_minimum_required(VERSION 3.22)
project(kakuro)

set(CMAKE_CXX_STANDARD 17)

add_executable(kakuro main.cpp
        lib/base_board.cpp
        lib/base_board.h
        lib/base_block.cpp
        lib/base_block.h
        lib/block_type.h
        lib/ai_game.cpp
        lib/ai_game.h)
