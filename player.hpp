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
	bool bigBlind=false;
	bool smallBlind=false;
	bool dealer=false;
	bool folded=false;
	//En int som rangerer hånden til spilleren
	int handRank;
	int highcard;
public:
	player(std::string _name,int _money,hand* _hand);
	void setHand(hand* _hand);
	int updateBank(int _money);
	int getBank();
	std::string showHand();
	std::string getName();
	void takeBet(int b);
	void resetBet();
	void setReady(bool b);
	void setBB(bool b);
	void setSB(bool b);
	void setDealer(bool b);
	bool getReady();
	bool getBB();
	bool getSB();
	bool getDealer();
	void setFolded(bool b);
	bool getFolded();
	int getBet();
	int handsum();
	hand* getHand();
	int calcHandRank(hand* table);
	int getHandRank();
	int getHigh();
	~player();
};

#endif