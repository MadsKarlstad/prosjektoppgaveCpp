#include "player.hpp"
#include <iostream>

using namespace std;

player::player(std::string n,int m){
	name = n;
	money = m;
}

void player::setHand(hand* h){
	playerhand = h;
}

int player::updateBank(int m){
	money = m;
	return money;
}

int player::handsum(){
	return playerhand->handSum();
}

std::string player::showHand(){
	std::string print = "";
	print += playerhand->toString();
	return print;
	
}

std::string player::getName(){
	return name;
}

player::~player(){}