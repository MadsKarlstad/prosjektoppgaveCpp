#ifndef CLASS_HOLDEM_H
#define CLASS_HOLDEM_H

#include <iostream>

#include "hand.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

class holdem{
	int pot,players,round;
	hand* table;
	hand* playerhand;
	player* user;
	deck* cards;
public:
	holdem(player* _user, deck* _cards);
	void start();
	void deal();
	void theFlop();
	void theTurn();
	void fifthStreet();
	void showTable();
	void crownWinner();
	int getPot();
	int getNumberOfPlayers();
	~holdem();
};

#endif