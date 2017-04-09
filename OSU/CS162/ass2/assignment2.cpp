/****************************************************** 
** Program: go_fish.cpp 
** Author: Gregory Brewster 
** Date: 04/25/2014 
** Description:This program will play the game Go Fish 
** Input: card numbers and players
** Output: winners and cards
******************************************************/
#include<iostream>
#include<string>
#include<cstdlib>
#include"Players.h"
#include"Cards.h"
#include"header.h"
#include<vector>

using namespace std;


int main(){
	Cards *cards = new Cards[52];
	vector<int>deck;

	//Set up cards
	setCards(cards);
	setDeck(deck);

	//Get number of players
	int amountOfPlayers = getPlayers();
	Players *player = new Players[amountOfPlayers];
	setupPlayers(cards, player, amountOfPlayers, deck);

	//play game
	takeTurns(cards, player, amountOfPlayers, deck);
	//print the cards
	//printCards(cards);

	return 0;
}

/********************************************************************* 
 ** Function: promptCards 
 ** Description: prompts the user to select one of his cards
 ** Parameters: Cards *cards,Players *player, int playerAmount, int currentPlayer
 ** Pre-Conditions: All parameters have values
 ** Post-Conditions: the selected int is returned
 *********************************************************************/
int promptCards(Cards *cards,Players *player, int playerAmount, int currentPlayer){
	bool error = false;
	string choice;
	do{
		cout<<"You may ask for one of the following cards."<<endl;
		for(int i=0; i<player[currentPlayer].getSize(); i++){
			cout<<i+1<<") "<<translateDenomination(cards[player[currentPlayer].getCard(i)].getDenomination())<<endl;
		}
		cin>>choice;
		if((atoi(choice.c_str())>=1) && (atoi(choice.c_str())<=player[currentPlayer].getSize())){
			error = false;
			return atoi(choice.c_str())-1;
		}else{
			error = true;
		}
	}while(error == true);
	cout<<"\n\n\n"<<endl;
}

/********************************************************************* 
 ** Function: promptUser
 ** Description: prompts the user to select a target player
 ** Parameters: Players *player, int playerAmount, int currentPlayer
 ** Pre-Conditions: all parameters have values
 ** Post-Conditions: the player int is returned
 *********************************************************************/
int promptUser(Players *player, int playerAmount, int currentPlayer){
	bool error = false;
	string choice;
	do{
		//cout<<"Current player is: "<<currentPlayer<<endl;
		cout<<"Which user would you like to ask?: "<<endl;
		for(int i=1; i<playerAmount+1; i++){
			if(i != currentPlayer){
				cout<<player[i-1].getID()<<") "<<player[i-1].getName()<<endl;
			}
		}
		cin>>choice;
		if(((atoi(choice.c_str())>=1) && (atoi(choice.c_str())<=(playerAmount))) && (atoi(choice.c_str())!=currentPlayer)){
			error = false;
			return atoi(choice.c_str())-1;
		}else{
			cout<<"ERROR!!! Try again dude."<<endl;
			error = true;
		}
	}while(error == true);
}

void displayCards(Cards *cards, Players *player, int player2){
	for(int i=0; i<player[player2].getSize(); i++){
		int cardValue = player[player2].getCard(i);
		//cout<<player[player2].getCard(i)<<endl;
		cout<<translateDenomination(cards[cardValue].getDenomination())<<" of "<<translateSuit(cards[cardValue].getSuit())<<endl;
	}
}

/********************************************************************* 
 ** Function: checkPlayer
 ** Description: this function checks the current player against the target player for a simliar card
 ** Parameters: Cards *cards, Players *player, int cCard, int cPlayer, int tPlayer, vector<int>& deck
 ** Pre-Conditions: All parameters are set
 ** Post-Conditions: None
 *********************************************************************/
void checkPlayer(Cards *cards, Players *player, int cCard, int cPlayer, int tPlayer, vector<int>& deck){
	int currentPlayer = player[cPlayer].getCard(cCard);
	bool matchFound = false;
//	cout<<"The denomination for the current player is "<<cards[currentPlayer].getDenomination()<<endl;
	for(int i=0; i<player[tPlayer].getSize(); i++){
		int targetPlayer = player[tPlayer].getCard(i);
//		cout<<"The denomination for traget player is "<<cards[targetPlayer].getDenomination()<<endl;
//		int currentPlayer = player[cPlayer].getCard(cCard);
		//if(cards[player[tPlayer].getCard(i)].getDenomination() == cards[player[cPlayer].getCard(cCard)].getDenomination()){
		if((cards[targetPlayer].getDenomination()) == (cards[currentPlayer].getDenomination())){
			cout<<"Found a match from "<<player[tPlayer].getName()<<"\n\n"<<endl;
			player[tPlayer].removeCard(i);
			player[cPlayer].addCard(targetPlayer);
			i--;
			matchFound = true;
		}
	}
	if(matchFound == false){
		cout<<"GO FISH!!!\n\n"<<endl;
		goFish(player, cPlayer, deck);
	}
	winner(cards, player, cPlayer);
}

/********************************************************************* 
 ** Function: winner
 ** Description: This funciton checks if a player has four of a kind of card
 ** Parameters: Cards *cards, Players *player, int cPlayer
 ** Pre-Conditions: current player is the current player to check
 ** Post-Conditions: none
 *********************************************************************/
void winner(Cards *cards, Players *player, int cPlayer){
	int counter =0, permacounter =0, fourOfKind;
	for(int i=0; i<player[cPlayer].getSize(); i++){
		for(int j=0; j<player[cPlayer].getSize(); j++){
			if(cards[player[cPlayer].getCard(i)].getDenomination() == cards[player[cPlayer].getCard(j)].getDenomination()){
				counter++;
				//cout<<"found a dup"<<endl;
			}
		}
		if(counter == 4){
			//cout<<"YOU GOT A SET!!!"<<endl;
			//cout<<"I is: "<<i<<endl;
			permacounter = 0;
			permacounter = 4;
			fourOfKind = cards[player[cPlayer].getCard(i)].getDenomination();
		}
		counter = 0;
	}

		if(permacounter == 4){

                        //cout<<"fourofakind is: "<<fourOfKind<<endl;
                        for(int j=0; j<player[cPlayer].getSize(); j++){
                                if((fourOfKind) == (cards[player[cPlayer].getCard(j)].getDenomination())){
                                        //cout<<"Deleting card "<<cards[player[cPlayer].getCard(j)].getDenomination()<<endl;
                                        player[cPlayer].removeCard(j);
                                        j--;
                                }
			}
			player[cPlayer].addScore();

			cout<<player[cPlayer].getName()<<" got four "<<fourOfKind<<"'s, and score is "<<player[cPlayer].getScore()<<endl;
		
	}
}

/********************************************************************* 
 ** Function: goFish
 ** Description: this function assigns a new card to a user from the deck
 ** Parameters: the deck vector and current player
 ** Pre-Conditions: vector is a pointer to deck in main
 ** Post-Conditions: none
 *********************************************************************/
void goFish(Players *player, int cPlayer, vector<int>& deck){
	if(deck.size() >0){
		int cardIndex = rand() % deck.size();
		int cardValue = deck[cardIndex];
		player[cPlayer].addCard(cardValue);

	        for(int x=0; x<deck.size(); x++){
        		if(deck[x] == cardValue)
        			deck.erase(deck.begin()+x);
		        }
	        vector<int>(deck).swap(deck);
	}else{
		cout<<"NO more cards! :("<<endl;
	}

}

/********************************************************************* 
 ** Function: takeTurns
 ** Description: This function constantly checks for a winner and loops until winner is found prompting users for turns
 ** Parameters: Cards *cards, Players *player,int playerNum, vector<int>& deck
 ** Pre-Conditions: playerNum must have the total number of players
 ** Post-Conditions: none
 *********************************************************************/
void takeTurns(Cards *cards, Players *player,int playerNum, vector<int>& deck){
	bool winner = false;
	int choosenPlayer, choosenCard;
	while(winner == false){
		for(int i=0; i<playerNum; i++){
			for(int j=0; j<playerNum; j++){
				if(player[j].getSize() <1){
					winner = true;
					cout<<player[j].getName()<<" wins, with a score of "<<player[j].getScore()<<endl;
					break;
				}
			}
		if(winner == false){
			cout<<"Starting turn for "<<player[i].getName()<<", Score: "<<player[i].getScore()<<endl; 
			choosenPlayer = promptUser(player, playerNum, player[i].getID());
			//cout<<"!!!Targeted Player is "<<choosenPlayer<<endl;
			choosenCard = promptCards(cards, player, playerNum, i);
			//cout<<"!!!Targeted Card is "<<choosenCard<<endl;
			checkPlayer(cards, player, choosenCard, i, choosenPlayer, deck);
			cout<<"Here are your current cards: \n"<<endl;
			displayCards(cards, player,i);
			cout<<"\n\n\n\n\n\n\n"<<endl;
			//prompt user for input
		}
		}//end for loop
	}//end while loop
}

/********************************************************************* 
 ** Function: setupPlayers
 ** Description: Function sets players name and default cards from deck
 ** Parameters: Cards *cards, Players *player, int playerAmount, vector<int>& deck
 ** Pre-Conditions: playerAmount must be total player objects created
 ** Post-Conditions: None, it is void
 *********************************************************************/
void setupPlayers(Cards *cards, Players *player, int playerAmount, vector<int>& deck){
	for(int i=0; i<playerAmount; i++){
		int cardIndex =0, cardValue =0;
		string name = "null player";
		cout<<"Please enter :the name for player "<<i+1<<": ";
		cin>>name;
		player[i].setName(name);
		player[i].setID(i+1);
		for(int j=0; j<7; j++){
			cardIndex = rand() % deck.size();
//			cout<<deck[cardIndex]<<endl;
//			cout<<translateSuit(cards[cardValue].getSuit())<<endl;
			cardValue = deck[cardIndex];
			//cout<<translateDenomination(cards[cardValue].getDenomination())<<" of "<<translateSuit(cards[cardValue].getSuit())<<endl;
			player[i].addCard(cardValue);
				for(int x=0; x<deck.size(); x++){
					if(deck[x] == cardValue)
						deck.erase(deck.begin()+x);
				}
			vector<int>(deck).swap(deck);
		}
	}
	cout<<"\n\n\n\n\n"<<endl;
}


void setDeck(vector<int>& deck){
	for(int i=0; i<52; i++){
		deck.push_back(i);
	}
}

/********************************************************************* 
 ** Function: getPlayers
 ** Description: this function takes inital input from user
 ** Parameters: none, all information is stored in objects
 ** Pre-Conditions: none nothing is set
 ** Post-Conditions: none it is void
 *********************************************************************/
int getPlayers(){
	string numberOfPlayers;
	bool error = false;
	
	cout<<"\n\n\n\n\n\nWelcome to Go fish. Before we get started playing, we will need to do a bit of setting up."<<endl;
	do{
		cout<<"Please enter the amount of players that will be playing(2-6): ";
		cin>>numberOfPlayers;

		if(atoi(numberOfPlayers.c_str()) >= 2 && atoi(numberOfPlayers.c_str()) <=6){
			//Number is valid
			error = false;

		}else{
			//Number is not valid
			error = true;
			cout<<"Error! You did not enter a proper number \n Please try again..."<<endl;
		}

	}while(error == true);
	return atoi(numberOfPlayers.c_str());

}

void setCards(Cards *cards){
	int counter = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<13; j++){
			cards[counter].setCards((i+1),(j+1));
			counter++;
		}
	}


}

void printCards(Cards *cards){
	for(int i=0; i<52; i++){
		cout<<"Card "<<i+1<<" is suit "<<cards[i].getSuit()<<" with the denomination of "<<cards[i].getDenomination()<<" and is assigned to player "<<cards[i].getHolder()<<endl;
	}

}


string translateSuit(int value){
	//cout<<"tranlsate code is: "<<value<<endl;
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

string translateDenomination(int value){
	string denomination;
	switch(value){
		case 1:
			denomination="Ace";
			break;
		case 2:
			denomination="2";
			break;
		case 3:
			denomination="3";
			break;
		case 4:
			denomination="4";
			break;
		case 5:
			denomination="5";
			break;
		case 6:
			denomination="6";
			break;
		case 7:
			denomination="7";
			break;
		case 8:
			denomination="8";
			break;
		case 9:
			denomination="9";
			break;
		case 10:
			denomination="10";
			break;
		case 11: 
			denomination="Jack";
			break;
		case 12:
			denomination="Queen";
			break;
		case 13:
			denomination="King";
			break;
	}
	return denomination;
}

