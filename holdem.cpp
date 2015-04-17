#include "holdem.hpp"
#include <iostream>

using namespace std;

holdem::holdem(player* _user, deck* _cards){
	user = _user;
	cards = _cards;
	philshand = new hand();
	carolshand = new hand();
	phil = new player("Phil",1000,philshand);
	carol = new player("Carol",1000,carolshand);
}

void holdem::start(){
	table = new hand();

	user->setDealer(true);
	phil->setSB(true);
	carol->setBB(true);
	phil->takeBet(smallBlind);
	carol->takeBet(bigBlind);
	highestBet = bigBlind;
	pot = smallBlind + bigBlind;
	deal();
	std::string userhand = user->showHand();
	cout << "\n    Phil, Bank: "<< phil->getBank() <<"      Carol, Bank: " << carol->getBank() << endl;
	cout << "   _______________________________________" << endl;
	cout << "  /  "<< phil->getBet() <<"                  "<<carol->getBet()<<"               \\  " << endl;
	cout << " /                                         \\" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << " \\                                         /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "             Your hand:" << userhand << endl;
	cout << "             "<<user->getName()<<", Bank: " << user->getBank() << endl;
}

void holdem::deal(){
	playerhand = user->getHand();
	playerhand->addCard(cards->hit());
	playerhand->addCard(cards->hit());
	philshand->addCard(cards->hit());
	philshand->addCard(cards->hit());
	carolshand->addCard(cards->hit());
	carolshand->addCard(cards->hit());
	//user->setHand(playerhand);
}

void holdem::theFlop(){
	table->addCard(cards->hit());
	table->addCard(cards->hit());
	table->addCard(cards->hit());

	std::string userhand = user->showHand();
	std::string p = phil->showHand();
	std::string c = carol->showHand();
	cout << "\n    Phil, Bank: "<< phil->getBank() <<"      Carol, Bank: " << carol->getBank() << endl;
	cout << "   _______________________________________" << endl;
	cout << "  /  "<< phil->getBet() <<"                  "<<carol->getBet()<<"               \\  " << endl;
	cout << " /                                         \\" << endl;
	cout << "|                                          |" << endl;
	cout << "|               "<<table->toString()<<"                 |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << " \\          "<< user->getBet() <<"                              /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "             Your hand:" << userhand << endl;
	cout << "             "<<user->getName()<<", Bank: " << user->getBank() << endl;
}



void holdem::theTurn(){
	table->addCard(cards->hit());

	std::string userhand = user->showHand();
	cout << "\n    Phil, Bank: "<< phil->getBank() <<"      Carol, Bank: " << carol->getBank() << endl;
	cout << "   _______________________________________" << endl;
	cout << "  /                                       \\  " << endl;
	cout << " /                                         \\" << endl;
	cout << "|                                          |" << endl;
	cout << "|               "<<table->toString()<<"             |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << " \\                                         /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "             Your hand:" << userhand << endl;
	cout << "             "<<user->getName()<<", Bank: " << user->getBank() << endl;
}

void holdem::fifthStreet(){
	table->addCard(cards->hit());

	std::string userhand = user->showHand();
	cout << "\n    Phil, Bank: "<< phil->getBank() <<"      Carol, Bank: " << carol->getBank() << endl;
	cout << "   _______________________________________" << endl;
	cout << "  /                                       \\  " << endl;
	cout << " /                                         \\" << endl;
	cout << "|                                          |" << endl;
	cout << "|            "<<table->toString()<<"            |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << " \\                                         /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "             Your hand:" << userhand << endl;
	cout << "             "<<user->getName()<<", Bank: " << user->getBank() << endl;
}

void holdem::showTable(){
	std::string userhand = user->showHand();
	cout << "\n    Phil, Bank: "<< phil->getBank() <<"      Carol, Bank: " << carol->getBank() << endl;
	cout << "   _______________________________________" << endl;
	cout << "  /  "<< phil->getBet() <<"                  "<<carol->getBet()<<"               \\  " << endl;
	cout << " /                                         \\" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << " \\          "<< user->getBet() <<"                             /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "             Your hand:" << userhand << endl;
	cout << "             "<<user->getName()<<", Bank: " << user->getBank() << endl;
	}

void holdem::takeBets(){

}

void holdem::crownWinner(){

}

void holdem::switchRoles(){
	if(user->getDealer()==true){
		user->setDealer(false);
		user->setSB(true);
		phil->setSB(false);
		phil->setBB(true);
		carol->setDealer(true);
		carol->setBB(true);
	}
	else if(user->getSB()==true){
		user->setSB(false);
		phil->setBB(false);
		carol->setDealer(false);
		user->setBB(true);
		phil->setDealer(true);
		carol->setSB(true);
	}
	else if(user->getBB()==true){
		user->setBB(false);
		phil->setDealer(false);
		carol->setSB(false);
		user->setDealer(true);
		phil->setSB(true);
		carol->setBB(true);
	}
}

player* holdem::getPhil(){return phil;}

player* holdem::getCarol(){return carol;}

int holdem::getPot(){return pot;}

int holdem::getHighestBet(){return highestBet;}

int holdem::getNumberOfPlayers(){return players;}

holdem::~holdem(){}