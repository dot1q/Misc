/*********************************************************************
** Program Filename: card_games.cpp
** Author: Gregory Brewster
** Date: 5/10/14
** Description: This is the game class file. Which has functions used by both poker and go fish
*********************************************************************/

#include<iostream>
#include "card_games.h"
#include<cstdlib>
using namespace std;

card_games::card_games() {
	// TODO Auto-generated constructor stub
	int counter=0;
	for(int i=1; i<=4; i++){
		for(int j=1; j<=13; j++){
			deck.push_back(cards());
			deck[counter].id = counter+1;
			deck[counter].suit = i;
			deck[counter].donom = j;
			counter++;
		}
	}
}

void card_games::reset_cards(){
	deck.clear();
	deck.resize(0);
	int counter=0;
	for(int i=1; i<=4; i++){
		for(int j=1; j<=13; j++){
			deck.push_back(cards());
			deck[counter].id = counter+1;
			deck[counter].suit = i;
			deck[counter].donom = j;
			counter++;
		}
	}

}

card_games::~card_games() {
	// TODO Auto-generated destructor stub
}

/*********************************************************************
** Function: check_card_input
** Description: checks if the inputed value is valid within set parameters
** Parameters: int num_of_cards
** Pre-Conditions: input is empty and error are false
** Post-Conditions: atoi of input is returned
*********************************************************************/

int check_card_input(int num_of_cards){
	string input;
	bool error = false;
	do{
		cout<<"Which card will you ask for?(1 - "<<num_of_cards<<")";
		cin>>input;
		//if inputed value is greater than 0 or less than the amount of cards in their hand
		if(atoi(input.c_str()) >=1 && atoi(input.c_str()) <=num_of_cards){
			error = false;
		}else{
			cout<<"ERROR, please enter a value between 1 and "<<num_of_cards<<endl;
			error = true;
		}
	}while(error == true);
	return atoi(input.c_str())-1;
}

/*********************************************************************
** Function: check_target_player
** Description: checks if player is not current player and is proper value
** Parameters: int num_of_players, int current_player
** Pre-Conditions: error is false, string is empty
** Post-Conditions: atoi of input is returned
*********************************************************************/
int check_target_player(int num_of_players, int current_player){
	bool error = false;
	string input;
	do{
		cin>>input;
		if(atoi(input.c_str()) != current_player && atoi(input.c_str()) >=1 && atoi(input.c_str()) <= num_of_players){
			error = false;
		}else if(atoi(input.c_str()) == current_player){
			error = true;
			cout<<"You cannot select your own name! Try again!: ";
		}else{
			cout<<"Error, you typed an invalid number! Try again!: ";
			error = true;
		}
	}while(error == true);
	return atoi(input.c_str())-1;
}

/*********************************************************************
** Function: select_players
** Description: prompts user for input then checks if it is valid
** Parameters: none
** Pre-Conditions:string is empty and error is false
** Post-Conditions: atoi of input is returned
*********************************************************************/
int select_players(){
	string input;
	bool error = false;
	do{
		cin>>input;
		if(atoi(input.c_str()) >=2 && atoi(input.c_str()) <=6)
			error = false;
		else{
			error = true;
			cout<<"ERROR! You did not enter a value between 2 and 6. Try again"<<endl;
		}
	}while(error == true);
return atoi(input.c_str());
}

/*********************************************************************
** Function: translateSuit
** Description: translates the suit from int into string
** Parameters: int value
** Pre-Conditions: int value has a value, and string suit is empty
** Post-Conditions: string suit is populated and returned
*********************************************************************/
string translateSuit(int value){
	string suit;
	switch(value){
	case 1:
		suit="Hearts";
		break;
	case 2:
		suit="Diamonds";
		break;
	case 3:
		suit="Spades";
		break;
	case 4:
		suit="Clubs";
		break;
	}
	return suit;
}

/*********************************************************************
** Function: translateDenomination
** Description: translates the int value to a string
** Parameters: int value
** Pre-Conditions: string denom is empty
** Post-Conditions: denom is populated and returned
*********************************************************************/
string translateDenomination(int value){
	string denom;
	switch(value){
	case 1:
		denom="Ace";
		break;
	case 2:
		denom="2";
		break;
	case 3:
		denom="3";
		break;
	case 4:
		denom="4";
		break;
	case 5:
		denom="5";
		break;
	case 6:
		denom="6";
		break;
	case 7:
		denom="7";
		break;
	case 8:
		denom="8";
		break;
	case 9:
		denom="9";
		break;
	case 10:
		denom="10";
		break;
	case 11:
		denom="Jack";
		break;
	case 12:
		denom="Queen";
		break;
	case 13:
		denom="King";
		break;
	}
	return denom;
}
