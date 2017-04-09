/********************************************************************* 
 ** Program Filename: Connect4.cpp
 ** Author: Gregory Brewster
 ** Date: 4/9/14
 ** Description: Plays the game connect 4 between two players
 ** Input: columns for connect four
 ** Output: Winner
 *********************************************************************/
#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include"./header.h"

using namespace std;

/*
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
*/

int main(int argc, char * argv[]){
   Board gameBoard;
	for(int i=1; i<argc; i++){
		string arg = argv[i];
		if (arg == "-rows"){
			gameBoard.xSize = atoi(argv[i+1]);
			if (gameBoard.xSize < 4)
				gameBoard.xSize = 4;
		}
		else if(arg == "-cols"){
			gameBoard.ySize = atoi(argv[i+1]);
			if (gameBoard.ySize <4)
				gameBoard.ySize = 4;
		}
	}
//   gameBoard.xSize = atoi(argv[1]);
//   gameBoard.ySize = atoi(argv[2]);
//   checkInput(gameBoard, argc, argv[]);

   gameBoard.create();
   gameBoard.init();
   gameBoard.print();

   promptPlayers(gameBoard);

return 0;
}

void checkInput(Board& gameBoard, int& argc, char * argv[]){
	cout<<"Test Line"<<endl;

}

/********************************************************************* 
 ** Function: promptPlayers
 ** Description: This function runs until a winner has been selected
 ** Parameters: gameBoard
 ** Pre-Conditions: Class player is created for player1 and player1
 ** Post-Conditions: function is void
 *********************************************************************/ 
void promptPlayers(Board& gameBoard){
	bool winner = false;
	Player player1, player2;
	gameBoard.counter = 0;
	player1.name = "Player 1";
	player2.name = "Player 2";
	player1.plyrSymbl = '1';
	player2.plyrSymbl = '2';
	player1.win = false;
	player2.win = false;
	while(winner == false){
		cout<<"gameboard counter is: "<<gameBoard.counter<<endl;
		if(player1.win == true || player2.win == true){
			break;
		}else{
			player1.getInput(gameBoard, player1);
			gameBoard.print();
		}
		if(player1.win == true || player2.win == true){
			break;
		}else{
			player2.getInput(gameBoard, player2);
			gameBoard.print();
		}
		if(gameBoard.xSize * gameBoard.ySize == gameBoard.counter){
			break;
		}
	}
	if(player1.win == true)
		cout<<player1.name<<" Wins!"<<endl;
	else if(player2.win == true)
		cout<<player2.name<<" Wins!"<<endl;
	else
		cout<<"Nobody Wins!"<<endl;

}

/********************************************************************* 
 ** Function:checkWinner1 
 ** Description: Checks to see if a player has won by horizontal and vertical rows
 ** Parameters: Class gameBoard, Class player, int column, int y
 ** Pre-Conditions: classes gameBoard and player are populated, int column is current column, and y is current row
 ** Post-Conditions: returns winner if there is one
 *********************************************************************/ 
void checkWinner1(Board& gameBoard, Player& player, int column, int y){
	int counter = 0;
	//check up and down
	for(int i=0; i<gameBoard.ySize; i++){
		if(gameBoard.board[column][i] == player.plyrSymbl){	
			counter ++;
			if(counter == 4)
				//cout<<player.name<<" WINS (Vertical)"<<endl;
				player.win = true;
		}else{
			counter = 0;
		}
	}
	counter = 0;
	for(int j=0; j<gameBoard.xSize; j++){
		if(gameBoard.board[j][y] == player.plyrSymbl){
			counter++;
			if(counter == 4)
				//cout<<player.name<<" WINS (Horizontal)"<<endl;
				player.win = true;
		}else{
			counter = 0;
		}
	}

}

/********************************************************************* 
 ** Function: 
 ** Description: 
 ** Parameters: 
 ** Pre-Conditions: 
 ** Post-Conditions: 
 *********************************************************************/ 
void checkWinner2(Board& gameBoard, Player& player, int column, int y){
	bool breaker = false;
	bool breaker2 = false;
	int counter = 1;
	for(int i =1; i<gameBoard.ySize; i++){
		if(column+i < gameBoard.xSize && y-i < gameBoard.ySize ){
			if(gameBoard.board[column+i][y-i] == player.plyrSymbl){
				if(breaker == false)
					counter++;
			}else{
				breaker = true;
			}
			//cout<<"Point: "<<column+i+1<<" "<<y-i+1<<endl;
		}

		if(column-i >= 0 && y+i < gameBoard.ySize){
			if(gameBoard.board[column-i][y+i] == player.plyrSymbl){
				if(breaker2 == false)
					counter++;
			}else{
				breaker2 = true;
			}
			//cout<<"Point: "<<column-i+1<<" "<<y+i+1<<endl;
		}
	}
	if(counter >=4){
		//cout<<player.name<<" WINS!"<<endl;
		player.win = true;
	}

	breaker = false;
	breaker2 = false;
	counter = 1;	
	for(int i =1; i<gameBoard.ySize; i++){
		if(column+i < gameBoard.xSize && y+i < gameBoard.ySize ){
			if(gameBoard.board[column+i][y+i] == player.plyrSymbl){
				if(breaker == false)
					counter++;
			}else{
				breaker = true;
			}
			//cout<<"Point: "<<column+i+1<<" "<<y+i+1<<endl;
		}

		if(column-i >= 0 && y-i < gameBoard.ySize){
			if(gameBoard.board[column-i][y-i] == player.plyrSymbl){
				if(breaker2 == false)
					counter++;
			}else{
				breaker2 = true;
			}
			//cout<<"Point: "<<column-i+1<<" "<<y-i+1<<endl;
		}
	}
	if(counter >=4){
		//cout<<player.name<<" WINS!"<<endl;
		player.win = true;
	}
	
}

/********************************************************************* 
 ** Function: writeBoard
 ** Description: Writes value to board 2D array
 ** Parameters: Class gameBoard and player, int column and int y
 ** Pre-Conditions: All parameters have values from previous function, int error is zero
 ** Post-Conditions: Returns an error int
e*********************************************************************/ 
int writeBoard(Board& gameBoard, Player& player, int column, int y){
	int error = 0;
	if(y<0){
		cout<<"ERROR!!! Column "<<column+1<<" is full!"<<endl;
		return 1;
	}
	else if(gameBoard.board[column][y]==' '){
		gameBoard.board[column][y]=player.plyrSymbl;
		gameBoard.counter++;
		checkWinner1(gameBoard, player, column, y);
		checkWinner2(gameBoard, player, column, y);
	}else{
		y--;
		error = writeBoard(gameBoard, player, column, y);
	}
		
return error;
}

/*Get input for which user class was passed*/
void Player::getInput(Board& gameBoard, Player& player){
	bool error = false;
	do{
		string input;
		int column;
		cout<<name<<", please select a column between 1 and "<<gameBoard.xSize<<": ";
		cin>>input;
		column = atoi(input.c_str());
		if(column >= 1 && column <= gameBoard.xSize){
			error = writeBoard(gameBoard, player, column-1, gameBoard.ySize-1);
		}else{
			error = true;
		}
		//if there is an error, print it out and loop again
		if(error == true)
			cout<<"ERROR!!!1, Please input a correct number!"<<endl;
	}while(error == true);
}


/*Create a 2D dynamic array using the inputs*/
void Board::create(){

   cout<<"You have selected a: "<<xSize<<" By: "<<ySize<<" board."<<endl;
   board = new char *[xSize];
   for(int i = 0; i<xSize; i++)
         board[i] = new char [ySize];

}
/*Sets all values of board to " "*/
void Board::init(){
   for(int i=0; i<ySize; i++){
      for(int j=0; j<xSize; j++){
         board[j][i] = ' ';
      }
   }
}

/*Prints the board*/
void Board::print(){
   for(int a=0; a<xSize; a++)
      cout<<"| "<<a+1<<" ";
   cout<<"|"<<endl;
   for(int i =0; i<ySize; i++){
      for(int a=0; a<(xSize*4)+1; a++)
         cout<<'-';
      cout<<endl;
      for(int j=0; j<xSize; j++)
         cout<<"| "<<board[j][i]<<" ";
      cout<<"|"<<endl;
   }
   for(int a=0; a<(xSize*4)+1; a++)
      cout<<'-';
   cout<<endl;

}
