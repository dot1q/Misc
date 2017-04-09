/*
 * Cards.h
 *
 *  Created on: Apr 21, 2014
 *      Author: Gregory Brewster
 */

#ifndef CARDS_H_
#define CARDS_H_

class Cards {
public:
	Cards();
	virtual ~Cards();
	void setCards(int newSuit, int newDenomination);
	void setHolder(int newValue);
	int getSuit();
	int getDenomination();
	int getHolder();

private:
	int suit;
	int denomination;
	int holder;
};

#endif /* CARDS_H_ */

