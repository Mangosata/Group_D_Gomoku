cmake_minimum_required(VERSION 3.16)
project(Group_D_Gomoku)

set(CMAKE_C_STANDARD 99)

find_package (PkgConfig REQUIRED)
pkg_check_modules (GTK3 REQUIRED gtk+-3.0)
include_directories (${GTK3_INCLUDE_DIRS})
link_directories (${GTK3_LIBRARY_DIRS})
add_definitions (${GTK3_CFLAGS_OTHER})
add_executable(Group_D_Gomoku src/main.c include/game/game.h src/game/game.c include/board/board.h src/board/board.c src/graphic/graphic.c include/graphic/graphic.h src/graphic_logic/logic.c include/graphic_logic/logic.h)
target_link_libraries (Group_D_Gomoku ${GTK3_LIBRARIES})

