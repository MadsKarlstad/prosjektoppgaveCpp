#include "deck.hpp"

#include <algorithm>
#include <random>

using namespace std;

deck::deck(){
	for(int i=1;i<5;i++){
		for(int j=1;j<14;j++){
			card c(i,j);
			m_deck.push_back(c);
		}
	}
}

card deck::hit(){
	card c(m_deck.back().get_suit(),m_deck.back().get_rank());
	m_deck.pop_back();
	return c;
}

void deck::shuffle(){
	auto engine = std::default_random_engine{};
	std::shuffle(std::begin(m_deck),std::end(m_deck),engine);
}

void deck::toString(){
	for(int i=0;i<m_deck.size();i++){
		card c = m_deck[i];
		c.toString();
	}
}

int deck::getSize(){
	return m_deck.size();
}

deck::~deck(){}