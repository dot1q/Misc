/*********************************************************************
** Program Filename: poker.cpp
** Author: Gregory Brewster
** Date: 5/10/14
** Description: Plays the game poker
** Input: player names number of players
** Output: cards and score
*********************************************************************/

#include "poker.h"
using namespace std;

poker::poker() {
	// TODO Auto-generated constructor stub
}

poker::~poker() {
	// TODO Auto-generated destructor stub
}

/*********************************************************************
** Function: play
** Description: this is the function created from the virtual function, prompts to setup players
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: void
*********************************************************************/
void poker::play(){
	cout<<"Poker Selected!---\nLets get started! Please enter the number of players for this game: ";
	int players = select_players();
	//create player objects
	player *playerObj = new player[players];
	setup_players(playerObj, players);

}

/*********************************************************************
** Function: setup_players
** Description: sets up players with five cards and starts turns
** Parameters: player and amount of players.
** Pre-Conditions: Amount of players should be under 7
** Post-Conditions: void
*********************************************************************/
void poker::setup_players(player *player, int players){
	string name;
	for(int i=0; i<players; i++){
		player[i].player_id = i+1;
		player[i].score = 0;
		cout<<"Please enter player "<<i+1<<"'s name: ";
		cin>>name;
		player[i].name = name;
		for(int j=0; j<5; j++){
			int deck_selection = rand() % deck.size();
			player[i].player_hand.push_back(cards());
			int size = player[i].player_hand.size()-1;
			player[i].player_hand[size]=deck[deck_selection];
			//player[i].add_card_from_deck(deck_selection);
			delete_card_from_deck(deck_selection);
		}
		//show_player_cards(i, player);
	}
	cout<<"Cards remaining in deck: "<<print_deck_size()<<endl;;
	take_turns(player, players);
}
void poker::show_player_cards(int i ,player *player){
	for(unsigned int j=0; j<player[i].player_hand.size(); j++){
		cout<<translateDenomination(player[i].player_hand[j].donom)<<" of "<<translateSuit(player[i].player_hand[j].suit)<<endl;
	}
}

/*********************************************************************
** Function: delete_card_from_deck
** Description: function deletes a card from the deck
** Parameters: int deckIndex
** Pre-Conditions: deckIndex should be 0 to 51
** Post-Conditions: void
*********************************************************************/
void poker::delete_card_from_deck(int deckIndex){
	deck.erase(deck.begin()+deckIndex);
	vector<cards>(deck).swap(deck);
	//std::cout<<"temp deck size is "<<deck.size()<<std::endl;
}

//returns the deck size;
int poker::print_deck_size(){
	return deck.size();
}

/*********************************************************************
** Function: take_turns
** Description: takes turns for each player and stops once turn limit has been reached
** Parameters: player, int num_of_players
** Pre-Conditions: num_of_players must be a non negative number
** Post-Conditions: void
*********************************************************************/
void poker::take_turns(player *player, int num_of_players){
	cout<<"How many turns would you like to have? ";
	int turns;
	cin>>turns;
	for(int j=0; j<turns; j++){
		cout<<"Starting turn "<<j+1<<endl;
		//loops through every player in an attempt to see if there is a winner
		for(int i = 0; i<num_of_players; i++){
				recycle_cards(player, i);
				//check cards
				of_a_kind(player, i);
				flush(player, i);

		}
		reset_cards();
		reset_players(player, num_of_players);
	}
	cout<<"Game over!"<<endl;
	for(int i=0; i<num_of_players; i++){
		cout<<"Score for player "<<player[i].name<< " is "<<player[i].score<<endl;
	}
}

/*********************************************************************
** Function: reset_players
** Description: resets player cards and assigns 5 new ones
** Parameters: player and int num_of_players
** Pre-Conditions: num_of_players cannot be below 0
** Post-Conditions: void
*********************************************************************/
void poker::reset_players(player *player, int num_of_players){
	for(int i=0; i<num_of_players; i++){
		player[i].player_hand.clear();
		player[i].player_hand.resize(0);
		for(int j=0; j<5; j++){
			int deck_selection = rand() % deck.size();
			player[i].player_hand.push_back(cards());
			int size = player[i].player_hand.size()-1;
			player[i].player_hand[size]=deck[deck_selection];
			delete_card_from_deck(deck_selection);
		}

	}
}

/*********************************************************************
** Function: recycle_cards
** Description: recycles a card if a user selects to discard a card
** Parameters: player and int current_player
** Pre-Conditions: current player should be between 0 and 5
** Post-Conditions: void
*********************************************************************/
void poker::recycle_cards(player* player, int current_player){
	int cards_to_recycle = 0;
	cout<<"\nHere are your cards, "<<player[current_player].name<<" \n----------------------------"<<endl;
	for(unsigned int i=0; i<player[current_player].player_hand.size(); i++){
		cout<<translateDenomination(player[current_player].player_hand[i].donom)<<" of "<<translateSuit(player[current_player].player_hand[i].suit)<<endl;
	}
	cout<<"How many would you like to exchange on the deck?(0-4)"<<endl;
	cin>>cards_to_recycle;
	//loops for how many cards the users wants to replace
	for(int j=0; j<cards_to_recycle; j++){
		//loops and displays all the remaining cards
		for(unsigned int i=0; i<player[current_player].player_hand.size(); i++){
			cout<<i+1<<") "<<translateDenomination(player[current_player].player_hand[i].donom)<<" of "<<translateSuit(player[current_player].player_hand[i].suit)<<endl;
		}
		int discard;
		cin>>discard;
		player[current_player].player_hand.erase(player[current_player].player_hand.begin()+discard-1);
		vector<cards>(player[current_player].player_hand).swap(player[current_player].player_hand);
	}
	for(int i=0; i<cards_to_recycle; i++){
		int deck_selection = rand() % deck.size();
		player[current_player].player_hand.push_back(cards());
		int size = player[current_player].player_hand.size()-1;
		player[current_player].player_hand[size]=deck[deck_selection];
		//player[i].add_card_from_deck(deck_selection);
		delete_card_from_deck(deck_selection);
	}
	show_player_cards(current_player, player);

}

/*********************************************************************
** Function:of_a_kind
** Description: checks for 3 and 4 of a kind
** Parameters: player and int current_player
** Pre-Conditions: current player must be between 0-5
** Post-Conditions: void
*********************************************************************/
void poker::of_a_kind(player* player, int current_player){
	for(unsigned int i=0; i<player[current_player].player_hand.size(); i++){
		int counter = 0;
		for(unsigned int j=0; j<player[current_player].player_hand.size(); j++){
			if(player[current_player].player_hand[i].donom == player[current_player].player_hand[j].donom){
				counter ++;
			}
		}
		if(counter == 3){
			player[current_player].score = player[current_player].score + 10;
			cout<<"10 points added to "<<player[current_player].name<<endl;
		}
		else if (counter == 4){
			player[current_player].score = player[current_player].score + 30;
			cout<<"30 points added to "<<player[current_player].name<<endl;
		}
	}
}

/*********************************************************************
** Function: flush
** Description: checks a player for a flush
** Parameters: player object, int current_player
** Pre-Conditions: current player must be between 0-5
** Post-Conditions: void
*********************************************************************/
void poker::flush(player* player, int current_player){
	int counter =0;
	for(unsigned int i=0; i<player[current_player].player_hand.size(); i++){
		if(player[current_player].player_hand[0].suit == player[current_player].player_hand[i].suit){
			counter++;
		}
	}
	if(counter == 5){
		player[current_player].score = player[current_player].score + 20;
		cout<<"20 points added to "<<player[current_player].name<<endl;
	}
}

