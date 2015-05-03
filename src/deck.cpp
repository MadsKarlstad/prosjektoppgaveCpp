//Skrevet av Mads M Karlstad, s193949
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

//Tar et kort fra kortstokken og returnerer det
card deck::hit(){
	card c(m_deck.back().get_suit(),m_deck.back().get_rank());
	m_deck.pop_back();
	return c;
}

//Stokker kortene
void deck::shuffle(){
	//std::random_shuffle(&m_deck[0], &m_deck[51]);
	for(int i=0;i<52;i++){
		int randomcard = rand() % 52;
		card temp=m_deck[i];
		m_deck[i] = m_deck[randomcard];
		m_deck[randomcard] = temp;
	}
}

//En toString for kortstokken for å sjekke at alle kortene er på plass
std::string deck::toString(){
	std::string print = "";
	for(int i=0;i<m_deck.size();i++){
		card c = m_deck[i];
		print+=c.toString();
	}
	return print;
}

int deck::getSize(){
	return m_deck.size();
}

deck::~deck(){}