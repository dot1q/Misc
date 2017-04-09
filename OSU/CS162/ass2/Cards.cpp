/*
 * Cards.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: Gregory Brewster
 */

#include "Cards.h"

Cards::Cards() : suit(0), denomination(0), holder(0){
}

Cards::~Cards() {
	// TODO Auto-generated destructor stub
}

void Cards::setCards(int newSuit, int newDenomination) {
	suit = newSuit;
	denomination = newDenomination;
}
void Cards::setHolder(int newValue){
	holder = newValue;
}

int Cards::getSuit(){
	return suit;
}

int Cards::getDenomination(){
	return denomination;
}
int Cards::getHolder(){
	return holder;
}

