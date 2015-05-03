//Skrevet av Mads M Karlstad, s193949
#include "hand.hpp"

using namespace std;

hand::hand(){

}

//Fjerner elementene i hånden
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

//Returnerer et kort ut i fra gitt indeks
card hand::getCard(int index){
	return m_hand[index];
}

//Returnerer størrelsen på hånden
int hand::getSize(){
	return m_hand.size();
}

//Legger til et kort til hånden
void hand::addCard(card c){
	m_hand.push_back(c);
}

//Returnerer summen av kortene på hånden (Trengs ikke i poker, men kjekt for gjenbruk av klassen)
int hand::handSum(){
	int sum=0;
	for(int i=0;i<m_hand.size();i++){
		sum += m_hand[i].get_value();
	}
	return sum;
}

hand::~hand(){}