# Group_D_Gomoku

## Project Statement
Gomoku, also called Five in a Row, is an abstract strategy board game. It is traditionally played with Go pieces (black and white stones) on a Go board. It can be played using the 15×15 board or the 19×19 board. Players alternate turns to place a stone of their colour on an empty intersection. The winner is the first player to form an unbroken chain of five stones.

![Gomoku](https://upload.wikimedia.org/wikipedia/commons/thumb/d/db/Gomoku-game-3.svg/300px-Gomoku-game-3.svg.png)

## Basic Functions:
1.The main function is to achieve a two-player battle.

2.The board size should be 19*19. Each player will have different colored stones (for example player 1 will have black and player 2 will have blue). After each move, the program will check if there is a winner or not.

3.When the five stones of the same player practice a straight line vertically or horizontally or diagonally, that player wins and then exits the game. You can exit the game at any time during the game.


## Further Functions:
1.Background music: The music will be background long music, that would be around 2 to 5 minutes. Also, we will try to add action sounds (SFX). These will give sound feedback when a player or machine plays a move and when a party wins the match.

2.Man-machine battle: The purpose of this mode's implementation is to have the player play with trained agent by implementing the reinforcement learning


## Requirements

1. Implement the basic logic of Gomoku and finish man-man game mode in the console:
   - A two-dimension array with 19 rows and 19 columns representing the 19*19 board with the default value of 0.
   - Update any array element by inputting the value (E.g. 1 for black and 0 for white).
   - Once the array element is updated, restrict the array element to change for the whole game.
   - After two players (different colours) play chess separately, the system checks the position of the pieces.
   - After every move, check if there are five stones in row vertically or horizontally or diagonally.
   - If there are 5 stones in a row, end the game with the winner's name.


2. Build a graphic window included board, stones and buttons using GTK +3.0.
3. Apply the check winner logic in graphic version.

## How to use

We provide two versions of Gomoku. One is the console version, another one is the graphic version.

#### 1. Console Version

You can clone the console version using the following command:

```bash
git clone -b console_version https://github.com/Mangosata/Group_D_Gomoku.git
```

Then open a terminal in the project directory (the project folder should call Group_D_Gomoku) and  use the following command to go to the "src" folder:

``` bash
cd src
```

Finally, use this command to compile main.c:

```bash
gcc .\main.c .\game\game.c .\board\board.c -o main
```

Now, you will get a main.exe file under "src" directory, open it and play game! Have fun!