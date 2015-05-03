//Skrevet av Mads M Karlstad, s193949
#ifndef CLASS_HAND_H
#define CLASS_HAND_H

#include <vector>
#include <iostream>
#include "card.hpp"

class hand{
	std::vector<card> m_hand;

public:
	hand();
	~hand();
	std::string toString();
	int getSize();
	void clearHand();
	void addCard(card c);
	int handSum();
	card getCard(int i);
};

#endif