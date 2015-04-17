#include "player.hpp"
#include <iostream>

using namespace std;

player::player(std::string n,int m,hand* _hand){
	name = n;
	money = m;
	playerhand = _hand;
}

void player::setHand(hand* h){
	playerhand = h;
}

int player::updateBank(int m){
	money = m;
	return money;
}

int player::getBank(){
	return money;
}

int player::handsum(){
	return playerhand->handSum();
}

void player::takeBet(int b){
	bet = bet + b;
	money = money - b;
}

std::string player::showHand(){
	std::string print = "";
	print += playerhand->toString();
	return print;
	
}

std::string player::getName(){
	return name;
}

hand* player::getHand(){
	return playerhand;
}

void player::setReady(bool _b){
	ready = _b;
}
void player::setBB(bool b){
	bigBlind = b;
}
void player::setSB(bool b){
	smallBlind = b;
}
void player::setDealer(bool b){
	dealer = b;
}
bool player::getReady(){
	return ready;
}
bool player::getBB(){
	return bigBlind;
}
bool player::getSB(){
	return smallBlind;
}
bool player::getDealer(){
	return dealer;
}

int player::getBet(){return bet;}

player::~player(){}