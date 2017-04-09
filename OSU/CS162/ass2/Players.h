/*
 * Players.h
 *
 *  Created on: Apr 21, 2014
 *      Author: Gregory Brewster
 */

#ifndef PLAYERS_H_
#define PLAYERS_H_
#include<vector>
using std::vector;
class Players {
public:
	Players();
	virtual ~Players();
	void setName(std::string newName);
	void addCard(int value);
	void setCard(int index, int value);
	void removeCard(int index);
	void setID(int id);
	void addScore();
	int getScore();
	int getID();
	int getSize();
	int getCard(int index);
	std::string getName();

private:
	//string playerName;
	vector<int> cards;
	int playerNumber;
	int score;
	std::string name;

};

#endif /* PLAYERS_H_ */

