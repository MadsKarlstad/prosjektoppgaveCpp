#include "hand.hpp"

using namespace std;

hand::hand(){

}

void hand::clearHand(){
	while(!m_hand.empty()){
		m_hand.pop_back();
	}
}

std::string hand::toString(){
	std::string print = m_hand[0].toString();
	for(int i=1;i<m_hand.size();i++){
		print += ", " + m_hand[i].toString();
	}
	return print;
}

card hand::getCard(int index){
	return m_hand[index];
}

int hand::getSize(){
	return m_hand.size();
}

void hand::addCard(card c){
	m_hand.push_back(c);
}

int hand::handSum(){
	int sum=0;
	for(int i=0;i<m_hand.size();i++){
		sum += m_hand[i].get_value();
	}
	return sum;
}

hand::~hand(){}