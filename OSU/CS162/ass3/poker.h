/*
 * poker.h
 *
 *  Created on: May 7, 2014
 *      Author: eecs162
 */
#include<iostream>
#include"card_games.h"
#include<stdlib.h>
#include<vector>
#include<string>

#ifndef POKER_H_
#define POKER_H_

using std::vector;

/*
 * Class Poker
 */

class poker: public card_games{
	struct player{
		int score;
		int player_id;
		std::string name;
		vector <cards> player_hand;
	};

public:
	poker();
	virtual ~poker();
	void setup_players(player *playerObj, int players);
	void play();
	int print_deck_size();
	void delete_card_from_deck(int deckIndex);
	void show_player_cards(int i, player *player);
	void take_turns(player *player, int num_of_players );
	void recycle_cards(player* player, int current_player);
	void of_a_kind(player* player, int current_player);
	void flush(player* player, int current_player);
	void reset_players(player *player, int num_of_players);
};


#endif /* POKER_H_ */
