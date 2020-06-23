# Group_D_Gomoku

## Organization

University of Ottawa & Carleton University



## Authors:

Bin Jia

Tingyu Ye

Hongzhi Zhang



## Project Statement

Gomoku, also called Five in a Row, is an abstract strategy board game. It is traditionally played with Go pieces (black and white stones) on a Go board. It can be played using the 15×15 board or the 19×19 board. Players alternate turns to place a stone of their colour on an empty intersection. The winner is the first player to form an unbroken chain of five stones.

![Gomoku](https://upload.wikimedia.org/wikipedia/commons/thumb/d/db/Gomoku-game-3.svg/300px-Gomoku-game-3.svg.png)



## Basic Functions:

1. The main function is to achieve a two-player battle.

2. The board size should be 15x15 or 19x19. Each player will have different colored stones (for example player 1 will have black and player 2 will have blue). After each move, the program will check if there is a winner or not.

3. The victory condition is that when the five stones of the same player practice a straight line vertically or horizontally or diagonally, that player wins and then exits the game. You can exit the game at any time during the game.

   

## Description

The console version will provide two size boards shown like the following:

   ![board](data/board.JPG)

   After choosing the board size, player 1 can put the stone (X) on the board by inputting row and column, then change the turn, player 2 will put the stone (O) on the board by the same way, like following:

   ![board_player](data/board_player.png)

   If any player satisfy the victory condition, it will output who it the winner.




## File Structure

The file structure shown like the following:

```
├─bin
├─build
│  └─cmake-build
├─data
├─include
│  ├─board
│  │  ├─board.h
│  ├─game
│  │  ├─game.h
│  └─graphic
│  │  ├─graphic.h
│  └─test
│  │  ├─test.h
├─src
│  ├─board
│  │    ├─board.c
│  ├─game
│  │    ├─game.c
│  └─main.c
└─test
 ├─data
 ├─include
 ├─src
 │  ├─board
 │  │    └─board_a.c
 │  ├─game
 │  │    ├─game_a.c
 │  │    ├─game_b.c
 │  │    └─game_c.c
 │  ├─tests
 │  │    ├─test_1.c
 │  │    ├─test_2.c
 │  │    ├─test_3.c
 │  │    ├─test_4.c
 │  │    ├─test_5.c
 │  │    ├─test_6.c
 │  │    ├─test_7.c
 │  │    ├─test_8.c
 │  │    └─test_9.c
 │  ├─main_a.c
 │  ├─main_b.c
 │  ├─main_c.c
 │  ├─main_d.c
 │  ├─main_e.c
 │  ├─main_f.c
 │  └─main_g.c
```

- the compiled objects will be created at the location as of C file.

- include folder contains the header files.

- src folder contains the source files.

- test folder contains the test files.

## How to use it:

You can clone the console version using the following command:

```bash
git clone -b console_version https://github.com/Mangosata/Group_D_Gomoku.git
```

Then open a terminal in the project directory (the project folder should call Group_D_Gomoku) and  use the following command to compile the game:
``` bash
make all
```

Finally, to run the game:

```bash
./main_game
```
