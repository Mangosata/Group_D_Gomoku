# Group_D_Gomoku

- [Group_D_Gomoku](#group-d-gomoku)
  * [Organization](#organization)
  * [Authors](#authors)
  * [Description](#description)
  * [File Structure](#file-structure)
  * [How to use it](#how-to-use-it)
  * [How to run the Tests](#how-to-run-the-tests)
    - [Test 1:](#test-1)
    - [Test 2:](#test-2)
    - [Test 3:](#test-3)
    - [Test 4:](#test-4)
    - [Test 5:](#test-5)
    - [Test 6:](#test-6)
    - [Test 7:](#test-7)
    - [Test 8:](#test-8)
    - [Test 9:](#test-9)
  * [More Details](#more-details)

## Organization

University of Ottawa & Carleton University



## Authors

Bin Jia

Tingyu Ye

Hongzhi Zhang



## Description

This version is only for console. Please follow the below instruction to use it.



## File Structure

The file structure shown like the following:

```
├─bin
│  └─tests
├─build
│  └─tests
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

- bin folder is for the executable files. The tests folder in it will contain the executable test files.
- build folder will contain the compile files (.o files). The test folder will contain the test object files.
- include folder contains the header files.
- src folder contains the source files.
- test folder contains the test files.
- data folder contains the pictures which README needs.

****

## How to use it

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
./bin/main_game
```

Have fun with it!

****

## How to run the Tests

#### Test 1:

**@Function: int select_board_size(void);**

The test is used to test the select_board_size(). By testing, function’s behaviour can be noticed when values ranging from -10 to 10 are inputted randomly to function using the test_1.c. It should generate the board only if the value is 1 or 2. 

To run this test, use:

``` bash
make test_1
```

``` bash
./bin/tests/test_1
```

#### Test 2:

**@Function: int check_winner(int board_size, char board[][board_size], int player_name);**

The test is used to test the check_winner(). In this, the function's output can be noticed when random coordinates are inputted by test_2.c. 
Player 1 is represented by ‘X’: If player 1 is the winner, there should be five ‘X’ in a straight row.
Player 2 is represented by ‘O’: If player 2 is the winner, there should be five ‘O’ in a straight row.
Verification:It can be done by a person. If there is a winner, on the terminal, a tester can see if there are five ‘X’ or ‘O’ in a straight row.
To run this test, use:

``` bash
make test_2
```

``` bash
./bin/tests/test_2
```

#### Test 3:

**@Function: void player_move(int board_size, char board[][board_size], int player_name);**

The test is used to test the player_move(). Randomized coordinates will be given to the player_move() by test_3.c. The player should play a move only when the coordinates are between 0 and board_size-1. On the other instances, this test will show how the function will behave. 
To run this test, use:

``` bash
make test_3
```

``` bash
./bin/tests/test_3
```

#### Test 4:

When the board is of size 19, this test will show the function’s behaviour. 
To run this test, use:

``` bash
make test_4
```

``` bash
./bin/tests/test_4
```

#### Test 5:

When the board is of size 15, this test will show the function’s behaviour. 
To run this test, use:

``` bash
make test_5
```

``` bash
./bin/tests/test_5
```

#### Test 6:

When the board size is greater than 15 and less than 19, this test will use a random board size and show the function’s behaviour. 
To run this test, use:

``` bash
make test_6
```

``` bash
./bin/tests/test_6
```

#### Test 7:

When the board size is greater than 0 and less than 15, this test will use a random board size and show the function’s behaviour. 
To run this test, use:

``` bash
make test_7
```

``` bash
./bin/tests/test_7
```

#### Test 8:

When the board size is greater than 19, this test will use a random board size between 20 and 100, and show the function’s behaviour.  
To run this test, use:

``` bash
make test_8
```

``` bash
./bin/tests/test_8
```


#### Test 9:

When the board size is less than or equal to 0, this test will use a random board size between -100 and 0, and show the function’s behaviour.  
To run this test, use:

``` bash
make test_9
```

``` bash
./bin/tests/test_9
```

****



## More Details

For more details, please move to our wiki: https://github.com/Mangosata/Group_D_Gomoku/wiki

