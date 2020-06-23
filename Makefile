# Compiler, Linker Defines
CC = gcc
CFLAGS = -Iinclude/ -c -Wall

all: main

test_1: main_a.o board_a.o test_1.o game_a.o
	$(CC) .\test\src\main_a.o .\test\src\board\board_a.o .\test\src\tests\test_1.o .\test\src\game\game_a.o -o test_1
	
test_2: main_a.o board_a.o test_1.o test_2.o game_b.o
	$(CC) .\test\src\main_a.o .\test\src\board\board_a.o .\test\src\tests\test_1.o .\test\src\tests\test_2.o .\test\src\game\game_b.o -o test_2
	
test_3: main_a.o board_a.o test_1.o test_3.o game_c.o
	$(CC) .\test\src\main_a.o .\test\src\board\board_a.o .\test\src\tests\test_1.o .\test\src\tests\test_3.o .\test\src\game\game_c.o -o test_3
	
test_4: main_b.o board_a.o test_1.o test_2.o test_4.o game_b.o
	$(CC) .\test\src\main_b.o .\test\src\board\board_a.o .\test\src\tests\test_1.o .\test\src\tests\test_2.o .\test\src\tests\test_4.o .\test\src\game\game_b.o -o test_4
	
test_5: main_c.o board_a.o test_1.o test_2.o test_5.o game_b.o
	$(CC) .\test\src\main_c.o .\test\src\board\board_a.o .\test\src\tests\test_1.o .\test\src\tests\test_2.o .\test\src\tests\test_5.o .\test\src\game\game_b.o -o test_5
	
test_6: main_d.o board_a.o test_1.o test_2.o test_6.o game_b.o
	$(CC) .\test\src\main_d.o .\test\src\board\board_a.o .\test\src\tests\test_1.o .\test\src\tests\test_2.o .\test\src\tests\test_6.o .\test\src\game\game_b.o -o test_6
	
test_7: main_e.o board_a.o test_1.o test_2.o test_7.o game_b.o
	$(CC) .\test\src\main_e.o .\test\src\board\board_a.o .\test\src\tests\test_1.o .\test\src\tests\test_2.o .\test\src\tests\test_7.o .\test\src\game\game_b.o -o test_7
	
test_8: main_f.o board_a.o test_1.o test_2.o test_8.o game_b.o
	$(CC) .\test\src\main_f.o .\test\src\board\board_a.o .\test\src\tests\test_1.o .\test\src\tests\test_2.o .\test\src\tests\test_8.o .\test\src\game\game_b.o -o test_8
	
test_9: main_g.o board_a.o test_1.o test_2.o test_9.o game_b.o
	$(CC) .\test\src\main_g.o .\test\src\board\board_a.o .\test\src\tests\test_1.o .\test\src\tests\test_2.o .\test\src\tests\test_9.o .\test\src\game\game_b.o -o test_9

main: main.o board.o game.o
	$(CC) .\src\main.o .\src\board\board.o .\src\game\game.o -o main_game

main.o: .\src\main.c
	$(CC) $(CFLAGS) .\src\main.c
	
board.o: .\src\board\board.c
	$(CC) $(CFLAGS) .\src\board\board.c
	
game.o: .\src\game\game.c
	$(CC) $(CFLAGS) .\src\game\game.c
	
main_a.o: .\test\src\main_a.c
	$(CC) $(CFLAGS) .\test\src\main_a.c
	
main_b.o: .\test\src\main_b.c
	$(CC) $(CFLAGS) .\test\src\main_b.c
	
main_c.o: .\test\src\main_c.c
	$(CC) $(CFLAGS) .\test\src\main_c.c
	
main_d.o: .\test\src\main_d.c
	$(CC) $(CFLAGS) .\test\src\main_d.c
	
main_e.o: .\test\src\main_e.c
	$(CC) $(CFLAGS) .\test\src\main_e.c
	
main_f.o: .\test\src\main_f.c
	$(CC) $(CFLAGS) .\test\src\main_f.c
	
main_g.o: .\test\src\main_g.c
	$(CC) $(CFLAGS) .\test\src\main_g.c

board_a.o: .\test\src\board\board_a.c
	$(CC) $(CFLAGS) .\test\src\board\board_a.c
	
game_a.o: .\test\src\game\game_a.c
	$(CC) $(CFLAGS) .\test\src\game\game_a.c
	
game_b.o: .\test\src\game\game_b.c
	$(CC) $(CFLAGS) .\test\src\game\game_b.c
	
game_c.o: .\test\src\game\game_c.c
	$(CC) $(CFLAGS) .\test\src\game\game_c.c
	
test_1.o: .\test\src\tests\test_1.c
	$(CC) $(CFLAGS) .\test\src\tests\test_1.c
	
test_2.o: .\test\src\tests\test_2.c
	$(CC) $(CFLAGS) .\test\src\tests\test_2.c
	
test_3.o: .\test\src\tests\test_3.c
	$(CC) $(CFLAGS) .\test\src\tests\test_3.c
	
test_4.o: .\test\src\tests\test_4.c
	$(CC) $(CFLAGS) .\test\src\tests\test_4.c
	
test_5.o: .\test\src\tests\test_5.c
	$(CC) $(CFLAGS) .\test\src\tests\test_5.c
	
test_6.o: .\test\src\tests\test_6.c
	$(CC) $(CFLAGS) .\test\src\tests\test_6.c
	
test_7.o: .\test\src\tests\test_7.c
	$(CC) $(CFLAGS) .\test\src\tests\test_7.c
	
test_8.o: .\test\src\tests\test_8.c
	$(CC) $(CFLAGS) .\test\src\tests\test_8.c
	
test_9.o: .\test\src\tests\test_9.c
	$(CC) $(CFLAGS) .\test\src\tests\test_9.c
