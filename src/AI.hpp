//Skrevet av Mads M Karlstad, s193949

#ifndef CLASS_AI_H
#define CLASS_AI_H

#include <iostream>

#include "player.hpp"
#include "card.hpp"
#include "deck.hpp"

class AI : public player{
	
	double PO;
	double RR;
	double HS;
	int wins;
public:
	AI(std::string _name,int _money,hand* _hand,bool d,bool bb, bool sb);

	void calcPO(double pot, double highestbet);
	void calcRR();
	void calcHS(deck* d, hand* table);
	void addWins();
	int getWins();
	double getRR();
	double getPO();
	double getHS();
	int getAction(deck* d, hand* table, int highestbet);

	~AI();

};

#endif