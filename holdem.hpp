#ifndef CLASS_HOLDEM_H
#define CLASS_HOLDEM_H

#include <iostream>

#include "hand.hpp"
#include "card.hpp"
#include "deck.hpp"
#include "player.hpp"
#include "AI.hpp"

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
	AI* phil;
	AI* carol;
	deck* cards;


	double potOdds;
	double RR;
	double HS;
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
	void takeBets(player* p, int b);
	void takeAIBets();
	void switchRoles();
	bool allReady();
	int getHighestBet();

	//Bestemmer hva AI skal gjøre ut i fra pot odds, return rate og hand strength
	void calcPotOdds(AI* ai);
	void calcHandStrength();
	void calcReturnRate();
	int AIaction();
	
	void reset();
	void newRound();
	AI* getPhil();
	AI* getCarol();
	hand* getTable();
	~holdem();
};

#endif