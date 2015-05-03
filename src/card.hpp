//Skrevet av Mads M Karlstad, s193949
#ifndef CLASS_CARD_H
#define CLASS_CARD_H

#include <iostream>

class card{
	friend class deck;
	int suit;
	int rank;
	std::string _suit;
	std::string _rank;

public:
	card(int _suit,int _rank);
	std::string toString();
	int get_suit();
	int get_rank();
	int get_value();
	~card();

};

#endif