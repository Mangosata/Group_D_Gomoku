# Compiler, Linker Defines
CC = gcc
CFLAGS = -Iinclude/ -c -Wall

# Directories for objects and executables
BINDIR = bin
OBJDIR = build
OBJDIR_TESTS = build\tests
BINDIR_TESTS = bin\tests

all: main

test_1: main_a.o board_a.o test_1.o game_a.o
	$(CC) $(OBJDIR_TESTS)\main_a.o $(OBJDIR_TESTS)\board_a.o $(OBJDIR_TESTS)\test_1.o $(OBJDIR_TESTS)\game_a.o -o $(BINDIR_TESTS)\test_1
	
test_2: main_a.o board_a.o test_1.o test_2.o game_b.o
	$(CC) $(OBJDIR_TESTS)\main_a.o $(OBJDIR_TESTS)\board_a.o $(OBJDIR_TESTS)\test_1.o $(OBJDIR_TESTS)\test_2.o $(OBJDIR_TESTS)\game_b.o -o $(BINDIR_TESTS)\test_2
	
test_3: main_a.o board_a.o test_1.o test_3.o game_c.o
	$(CC) $(OBJDIR_TESTS)\main_a.o $(OBJDIR_TESTS)\board_a.o $(OBJDIR_TESTS)\test_1.o $(OBJDIR_TESTS)\test_3.o $(OBJDIR_TESTS)\game_c.o -o $(BINDIR_TESTS)\test_3
	
test_4: main_b.o board_a.o test_1.o test_2.o test_4.o game_b.o
	$(CC) $(OBJDIR_TESTS)\main_b.o $(OBJDIR_TESTS)\board_a.o $(OBJDIR_TESTS)\test_1.o $(OBJDIR_TESTS)\test_2.o $(OBJDIR_TESTS)\test_4.o $(OBJDIR_TESTS)\game_b.o -o $(BINDIR_TESTS)\test_4

test_5: main_c.o board_a.o test_1.o test_2.o test_5.o game_b.o
	$(CC) $(OBJDIR_TESTS)\main_c.o $(OBJDIR_TESTS)\board_a.o $(OBJDIR_TESTS)\test_1.o $(OBJDIR_TESTS)\test_2.o $(OBJDIR_TESTS)\test_5.o $(OBJDIR_TESTS)\game_b.o -o $(BINDIR_TESTS)\test_5
	
test_6: main_d.o board_a.o test_1.o test_2.o test_6.o game_b.o
	$(CC) $(OBJDIR_TESTS)\main_d.o $(OBJDIR_TESTS)\board_a.o $(OBJDIR_TESTS)\test_1.o $(OBJDIR_TESTS)\test_2.o $(OBJDIR_TESTS)\test_6.o $(OBJDIR_TESTS)\game_b.o -o $(BINDIR_TESTS)\test_6
	
test_7: main_e.o board_a.o test_1.o test_2.o test_7.o game_b.o
	$(CC) $(OBJDIR_TESTS)\main_e.o $(OBJDIR_TESTS)\board_a.o $(OBJDIR_TESTS)\test_1.o $(OBJDIR_TESTS)\test_2.o $(OBJDIR_TESTS)\test_7.o $(OBJDIR_TESTS)\game_b.o -o $(BINDIR_TESTS)\test_7
	
test_8: main_f.o board_a.o test_1.o test_2.o test_8.o game_b.o
	$(CC) $(OBJDIR_TESTS)\main_f.o $(OBJDIR_TESTS)\board_a.o $(OBJDIR_TESTS)\test_1.o $(OBJDIR_TESTS)\test_2.o $(OBJDIR_TESTS)\test_8.o $(OBJDIR_TESTS)\game_b.o -o $(BINDIR_TESTS)\test_8
	
test_9: main_g.o board_a.o test_1.o test_2.o test_9.o game_b.o
	$(CC) $(OBJDIR_TESTS)\main_g.o $(OBJDIR_TESTS)\board_a.o $(OBJDIR_TESTS)\test_1.o $(OBJDIR_TESTS)\test_2.o $(OBJDIR_TESTS)\test_9.o $(OBJDIR_TESTS)\game_b.o -o $(BINDIR_TESTS)\test_9

main: main.o board.o game.o
	$(CC) $(OBJDIR)\main.o $(OBJDIR)\board.o $(OBJDIR)\game.o -o $(BINDIR)\main_game.exe

main.o: .\src\main.c
	$(CC) $(CFLAGS) .\src\main.c -o $(OBJDIR)\main.o
	
board.o: .\src\board\board.c
	$(CC) $(CFLAGS) .\src\board\board.c -o $(OBJDIR)\board.o
	
game.o: .\src\game\game.c
	$(CC) $(CFLAGS) .\src\game\game.c -o $(OBJDIR)\game.o
	
main_a.o: .\test\src\main_a.c
	$(CC) $(CFLAGS) .\test\src\main_a.c -o $(OBJDIR_TESTS)\main_a.o
	
main_b.o: .\test\src\main_b.c
	$(CC) $(CFLAGS) .\test\src\main_b.c -o $(OBJDIR_TESTS)\main_b.o
	
main_c.o: .\test\src\main_c.c
	$(CC) $(CFLAGS) .\test\src\main_c.c -o $(OBJDIR_TESTS)\main_c.o
	
main_d.o: .\test\src\main_d.c
	$(CC) $(CFLAGS) .\test\src\main_d.c -o $(OBJDIR_TESTS)\main_d.o
	
main_e.o: .\test\src\main_e.c
	$(CC) $(CFLAGS) .\test\src\main_e.c -o $(OBJDIR_TESTS)\main_e.o
	
main_f.o: .\test\src\main_f.c
	$(CC) $(CFLAGS) .\test\src\main_f.c -o $(OBJDIR_TESTS)\main_f.o
	
main_g.o: .\test\src\main_g.c
	$(CC) $(CFLAGS) .\test\src\main_g.c -o $(OBJDIR_TESTS)\main_g.o

board_a.o: .\test\src\board\board_a.c
	$(CC) $(CFLAGS) .\test\src\board\board_a.c -o $(OBJDIR_TESTS)\board_a.o
	
game_a.o: .\test\src\game\game_a.c
	$(CC) $(CFLAGS) .\test\src\game\game_a.c -o $(OBJDIR_TESTS)\game_a.o
	
game_b.o: .\test\src\game\game_b.c
	$(CC) $(CFLAGS) .\test\src\game\game_b.c -o $(OBJDIR_TESTS)\game_b.o
	
game_c.o: .\test\src\game\game_c.c
	$(CC) $(CFLAGS) .\test\src\game\game_c.c -o $(OBJDIR_TESTS)\game_c.o
	
test_1.o: .\test\src\tests\test_1.c
	$(CC) $(CFLAGS) .\test\src\tests\test_1.c -o $(OBJDIR_TESTS)\test_1.o
	
test_2.o: .\test\src\tests\test_2.c
	$(CC) $(CFLAGS) .\test\src\tests\test_2.c -o $(OBJDIR_TESTS)\test_2.o
	
test_3.o: .\test\src\tests\test_3.c
	$(CC) $(CFLAGS) .\test\src\tests\test_3.c -o $(OBJDIR_TESTS)\test_3.o
	
test_4.o: .\test\src\tests\test_4.c
	$(CC) $(CFLAGS) .\test\src\tests\test_4.c -o $(OBJDIR_TESTS)\test_4.o
	
test_5.o: .\test\src\tests\test_5.c
	$(CC) $(CFLAGS) .\test\src\tests\test_5.c -o $(OBJDIR_TESTS)\test_5.o
	
test_6.o: .\test\src\tests\test_6.c
	$(CC) $(CFLAGS) .\test\src\tests\test_6.c -o $(OBJDIR_TESTS)\test_6.o
	
test_7.o: .\test\src\tests\test_7.c
	$(CC) $(CFLAGS) .\test\src\tests\test_7.c -o $(OBJDIR_TESTS)\test_7.o
	
test_8.o: .\test\src\tests\test_8.c
	$(CC) $(CFLAGS) .\test\src\tests\test_8.c -o $(OBJDIR_TESTS)\test_8.o
	
test_9.o: .\test\src\tests\test_9.c
	$(CC) $(CFLAGS) .\test\src\tests\test_9.c -o $(OBJDIR_TESTS)\test_9.o