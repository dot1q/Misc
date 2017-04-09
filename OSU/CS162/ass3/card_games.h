/*
 * card_games.h
 *
 *  Created on: May 7, 2014
 *      Author: eecs162
 */
#include<vector>
#include<string>

using std::vector;

#ifndef CARD_GAMES_H_
#define CARD_GAMES_H_

int select_players();
std::string translateSuit(int value);
std::string translateDenomination(int value);
int check_card_input(int num_of_cards);
int check_target_player(int num_of_players, int current_player);

class card_games {

public:
	card_games();
	virtual ~card_games();
	virtual void play(){};
	void delete_card();
	void reset_cards();
	int get_size();

	void test2();
protected:
	struct cards{
		int id;
		int donom;
		int suit;
	};
	vector <cards> deck;
};

#endif /* CARD_GAMES_H_ */
