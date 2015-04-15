#ifndef CLASS_PLAYER_H
#define CLASS_PLAYER_H

#include <iostream>

#include "hand.hpp"
#include "card.hpp"

class player{
	std::string name;
	int money;

public:
	hand* playerhand;
	bool ready = false;
	bool bigBlind = false;
	bool smallBlind = false;
	bool dealer = false;

	player(std::string _name,int _money);
	void setHand(hand* _hand);
	int updateBank(int _money);
	std::string showHand();
	std::string getName();
	int handsum();
	~player();

};

#endif