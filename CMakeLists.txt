cmake_minimum_required(VERSION 3.16)
project(Group_D_Gomoku C)

set(CMAKE_C_STANDARD 99)

add_executable(Group_D_Gomoku src/main.c include/game/game.h src/game/game.c include/board/board.h src/board/board.c)