#include<iostream>
#include<cstdlib>
#include<stdlib.h>

using namespace std;
//Define Classes
class Board
{
public:
   void create();
   void print();
   void init();
   int xSize;
   int ySize;
   char **board;
   int counter;
};

class Player
{
public:
   void getInput(Board& gameBoard, Player& player);
   string name;
   char plyrSymbl;
   bool win;
};

//Defining Functions
void promptPlayers(Board& gameBoard);
int writeBoard(Board& gameBoard, Player& player, int column, int y);
void checkWinner1(Board& gameBoard, Player& player, int column, int y);
void checkWinner2(Board& gameBoard, Player& player, int column, int y);

