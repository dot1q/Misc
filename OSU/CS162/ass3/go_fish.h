/*
 * go_fish.h
 *
 *  Created on: May 7, 2014
 *      Author: eecs162
 */
#include"card_games.h"
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>

#ifndef GO_FISH_H_
#define GO_FISH_H_

class go_fish: public card_games {
	struct player{
		int score;
		int player_id;
		std::string name;
		vector <cards> player_hand;
	};

public:
	go_fish();
	virtual ~go_fish();
	void play();
	void setup_players(player *playerObj, int players);
	int print_deck_size();
	void delete_card_from_deck(int deckIndex);
	void show_player_cards(int i, player *player);
	void take_turns(player *player, int num_of_players );
	void player_turn(player *player, int current_player, int num_of_players);
	void check_players_cards(player *player, int selected_card, int selected_player, int current_player);
	int check_for_case(player *player, int current_player);
};

#endif /* GO_FISH_H_ */
