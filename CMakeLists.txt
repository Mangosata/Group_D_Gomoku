cmake_minimum_required(VERSION 3.16)
project(Group_D_Gomoku)

set(CMAKE_C_STANDARD 99)

find_package (PkgConfig REQUIRED)
pkg_check_modules (GTK3 REQUIRED gtk+-3.0)
include_directories (${GTK3_INCLUDE_DIRS})
link_directories (${GTK3_LIBRARY_DIRS})
add_definitions (${GTK3_CFLAGS_OTHER})
add_executable(Group_D_Gomoku src/main.c src/graphic/graphic.c include/graphic/graphic.h src/game_logic/game_logic.c include/game_logic/game_logic.h src/button_logic/button_logic.c include/button_logic/button_logic.h)
target_link_libraries (Group_D_Gomoku ${GTK3_LIBRARIES})

