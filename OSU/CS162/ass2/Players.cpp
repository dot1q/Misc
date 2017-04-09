/*
 * Players.cpp
 *
 *  Created on: Apr 21, 2014
 *      Author: Gregory Brewster
 */
#include<iostream>
#include<vector>
#include<string>
#include "Players.h"

Players::Players() : playerNumber(999), name("NULL USER"), score(0) {
	// TODO Auto-generated constructor stub
}

Players::~Players() {
	// TODO Auto-generated destructor stub
}

void Players::setName(std::string newName) {
	name = newName;
}

std::string Players::getName(){
	return name;
}

void Players::addCard(int value){
	cards.push_back(value);
}

void Players::removeCard(int index){
	cards.erase(cards.begin()+index);
	vector<int>(cards).swap(cards);
}

void Players::setCard(int index, int value){
	cards[index] = value;
}

void Players::setID(int id){
	playerNumber = id;
}

int Players::getCard(int index){
	return cards[index];
}

int Players::getSize(){
	return cards.size();
}

int Players::getID(){
	return playerNumber;
}

int Players::getScore(){
	return score;
}

void Players::addScore(){
	score++;
}
