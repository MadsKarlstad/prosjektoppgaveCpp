#ifndef CLASS_HOLDEM_H
#define CLASS_HOLDEM_H

#include <iostream>

#include "hand.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"

class holdem{
	int pot=0,players;
	int smallBlind = 25;
	int bigBlind = 50;
	int highestBet = 0;
	hand* table;
	hand* playerhand;
	hand* philshand;
	hand* carolshand;
	player* user;
	player* phil;
	player* carol;
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
	void takeBets();
	void switchRoles();
	int getHighestBet();
	player* getPhil();
	player* getCarol();
	~holdem();
};

#endif