#ifndef CLASS_PLAYER_H
#define CLASS_PLAYER_H

#include <iostream>

#include "hand.hpp"
#include "card.hpp"

class player{
	std::string name;
	int money;
	int bet=0;
	hand* playerhand;
	bool ready;
	bool bigBlind;
	bool smallBlind;
	bool dealer;
public:


	player(std::string _name,int _money,hand* _hand);
	void setHand(hand* _hand);
	int updateBank(int _money);
	int getBank();
	std::string showHand();
	std::string getName();
	void takeBet(int b);
	void setReady(bool b);
	void setBB(bool b);
	void setSB(bool b);
	void setDealer(bool b);
	bool getReady();
	bool getBB();
	bool getSB();
	bool getDealer();
	int getBet();
	int handsum();
	hand* getHand();
	~player();

};

#endif