#include "holdem.hpp"
#include <iostream>

using namespace std;

holdem::holdem(player* _user, deck* _cards){
	user = _user;
	cards = _cards;
}

void holdem::start(){
	table = new hand();
	//theFlop();
	//showTable();
}
void holdem::deal(){
	hand* playerhand = user->playerhand;
	playerhand->addCard(cards->hit());
	playerhand->addCard(cards->hit());
}
void holdem::theFlop(){
	table->addCard(cards->hit());
	table->addCard(cards->hit());
	table->addCard(cards->hit());
}
void holdem::theTurn(){

}
void holdem::fifthStreet(){

}
void holdem::showTable(){
	cout << "\n         Phil                  Carol     " << endl;
	cout << "   _______________________________________" << endl;
	cout << "  /                                       \\  " << endl;
	cout << " /                                         \\" << endl;
	cout << "|                                          |" << endl;
	cout << "|               "<<table->toString()<<"                 |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << " \\                                         /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "                    "<<user->getName() << endl;
}
void holdem::crownWinner(){

}
int holdem::getPot(){
	return pot;

}
int holdem::getNumberOfPlayers(){
	return players;
}

holdem::~holdem(){}