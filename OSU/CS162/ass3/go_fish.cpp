/*********************************************************************
** Program Filename:go_fish.cpp
** Author: Gregory Brewster
** Date: 5/10/14
** Description: Plays go fish
** Input: amount of players, target players, card selection, player names, card selection
** Output: winner, cards, score
*********************************************************************/

#include "go_fish.h"
using namespace std;

go_fish::go_fish() {
	// TODO Auto-generated constructor stub
}

go_fish::~go_fish() {
	// TODO Auto-generated destructor stub
}

/*********************************************************************
** Function: play
** Description: function from virtual function that plays the game
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: void
*********************************************************************/
void go_fish::play(){
	cout<<"Go Fish Selected!---\nLets get started! Please enter the number of players for this game: ";
	int players = select_players();
	//create player objects
	player *playerObj = new player[players];
	setup_players(playerObj, players);
}
/*********************************************************************
** Function: setup_players
** Description: goes through each player and sets up information about them
** Parameters: player object, and amount of players
** Pre-Conditions: players must be two or more
** Post-Conditions: void
*********************************************************************/
void go_fish::setup_players(player *player, int players){
	string name;
	for(int i=0; i<players; i++){
		player[i].player_id = i+1;
		cout<<"Please enter player "<<i+1<<"'s name: ";
		cin>>name;
		player[i].name = name;
		player[i].score = 0;
		for(int j=0; j<7; j++){
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

//test function that shows player cards
void go_fish::show_player_cards(int i ,player *player){
	for(unsigned int j=0; j<player[i].player_hand.size(); j++){
		cout<<translateDenomination(player[i].player_hand[j].donom)<<" of "<<translateSuit(player[i].player_hand[j].suit)<<endl;
	}
}

//delteds card from deck and then resizes vector
void go_fish::delete_card_from_deck(int deckIndex){
	deck.erase(deck.begin()+deckIndex);
	vector<cards>(deck).swap(deck);
	//std::cout<<"temp deck size is "<<deck.size()<<std::endl;
}

/*********************************************************************
** Function: check_for_case
** Description: checks for card match, and deletes card if match is present
** Parameters: player object, current_player
** Pre-Conditions: current_player must be a non negative number
** Post-Conditions: returns some int value
*********************************************************************/
int go_fish::check_for_case(player *player, int current_player){
	int counter =0, denom;
	for(unsigned int i=0; i<player[current_player].player_hand.size(); i++){
		//set denom to whatever index i is, in case something matches base for loop
		denom = player[current_player].player_hand[i].donom;
		for(unsigned int j=0; j<player[current_player].player_hand.size(); j++){
			if(player[current_player].player_hand[i].donom == player[current_player].player_hand[j].donom)
				counter ++;
		}
		if(counter == 4){
			for(unsigned int j=0; j<player[current_player].player_hand.size(); j++){
				if(player[current_player].player_hand[j].donom == denom){
					//delete the proper cards
					player[current_player].player_hand.erase(player[current_player].player_hand.begin()+j);
					vector<cards>(player[current_player].player_hand).swap(player[current_player].player_hand);
					j--;

				}
			}
			player[current_player].score++;
			cout<<player[current_player].name<<"'s score is now "<<player[current_player].score<<endl;
			return 0;
		}else{
			counter = 0;
		}
	}
	return 1;
}

//prints the deck size
int go_fish::print_deck_size(){
	return deck.size();
}
/*********************************************************************
** Function: player_turn
** Description: shows players card and prompts for target card and player, then executes check_cards
** Parameters: player object, current_player, num_of_players
** Pre-Conditions: previous function must set these parameters to valid
** Post-Conditions: void
*********************************************************************/

void go_fish::player_turn(player *player, int current_player, int num_of_players){
	cout<<"\nHere are your cards, "<<player[current_player].name<<" \n----------------------------"<<endl;
		for(unsigned int i=0; i<player[current_player].player_hand.size(); i++){
			cout<<i+1<<") "<<translateDenomination(player[current_player].player_hand[i].donom)<<" of "<<translateSuit(player[current_player].player_hand[i].suit)<<endl;
		}
	int selected_card = check_card_input(player[current_player].player_hand.size());
	cout<<"Which player would you like to ask?"<<endl;
		for(int i=0; i<num_of_players; i++){
			cout<<i+1<<") "<<player[i].name<<endl;
		}
	int selected_player= check_target_player(num_of_players, current_player+1);
	//cout<<"Selected card denomination is "<<selected_card<<endl;
	//cout<<"Selected target player is "<<selected_player<<endl;
	check_players_cards(player, selected_card, selected_player, current_player);
}

/*********************************************************************
** Function: check_players_cards
** Description: checks players card against opponents cards
** Parameters: player array, selected_card, selected_player, current_player
** Pre-Conditions: selected_card, selected_player and current_player must have proper values
** Post-Conditions: void
*********************************************************************/

void go_fish::check_players_cards(player *player, int selected_card, int selected_player, int current_player){
	int counter = 0;
	for(unsigned int i=0; i<player[selected_player].player_hand.size(); i++){
		if(player[current_player].player_hand[selected_card].donom == player[selected_player].player_hand[i].donom){
			cout<<"Found a match!"<<endl;
			//add card to current player
			player[current_player].player_hand.push_back(cards());
			int test = player[current_player].player_hand.size();
			player[current_player].player_hand[test-1]=player[current_player].player_hand[selected_card];
			//delete card off of target player
			player[selected_player].player_hand.erase(player[selected_player].player_hand.begin()+i);
			vector<cards>(player[selected_player].player_hand).swap(player[selected_player].player_hand);
			counter ++;
		}
	}
	if(counter == 0){
		if(deck.size() == 0){
			cout<<"No more cards left in deck!"<<endl;
		}else{
		cout<<"Go fish!"<<endl;
		player[current_player].player_hand.push_back(cards());
		int deck_selection = rand() % deck.size();
		player[current_player].player_hand[player[current_player].player_hand.size()-1]=deck[deck_selection];
		delete_card_from_deck(deck_selection);
		}
	}
}

/*********************************************************************
** Function: take turns
** Description: cycles through all players and breaks if a winner is found
** Parameters: player object and num_of_players
** Pre-Conditions: player array just be populated and num_of_players must be higher than 0
** Post-Conditions: void
*********************************************************************/

void go_fish::take_turns(player *player, int num_of_players){
	bool winner = false;
	do{
			//loops through every player in an attempt to see if there is a winner
			for(int i = 0; i<num_of_players; i++){
					if(winner == false){
						player_turn(player, i, num_of_players);
						int returned = check_for_case(player, i);
						if(player[i].player_hand.size()==0){
							winner = true;
						}
					}
			}
	}while(winner == false);
	cout<<"Game over!"<<endl;
}
