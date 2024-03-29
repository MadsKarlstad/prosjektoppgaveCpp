//Skrevet av Mads M Karlstad, s193949
#ifndef CLASS_DECK_H
#define CLASS_DECK_H

#include <vector>
#include <iostream>
#include "card.hpp"

class deck{
	std::vector<card> m_deck;

public:
	deck();
	~deck();
	card hit();
	void shuffle();
	std::string toString();
	int getSize();
};

#endif