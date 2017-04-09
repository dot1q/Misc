/*********************************************************************
** Program Filename: driver.cpp
** Author: Gregory Brewster
** Date: 5/10/14
** Description: This program plays either poker or go fish
** Input: game input
*********************************************************************/

#include<iostream>
#include"card_games.h"
#include"poker.h"
#include"go_fish.h"


using namespace std;

char choose_game();

int main(){
	card_games * game;
	char game_choice;

	game_choice = choose_game();

	if(game_choice == 'p')
		game = new poker;
	else if(game_choice == 'g')
		game = new go_fish;

	game->play();

	return 0;
}

/*********************************************************************
** Function:choose_game
** Description:Prompts the user for input on which game object to create
** Parameters: none
** Pre-Conditions: choice is empty and error is false
** Post-Conditions: char has a value and is returned
*********************************************************************/
char choose_game(){
	char choice;
	bool error = false;
	do{
		cout<<"Which game would you like to play?(p: Poker, g: Go Fish): ";
		cin>>choice;
		if(choice == 'p' || choice == 'g')
			error = false;
		else{
			error = true;
			cout<<"ERROR!!!1, you did not enter p or g"<<endl;
		}
	}while (error == true);

	return choice;
}


