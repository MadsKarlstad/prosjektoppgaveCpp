#include "holdem.hpp"
#include <iostream>

using namespace std;

//Initialiserer
holdem::holdem(player* _user, deck* _cards,int p, int c){
	user = _user;
	cards = _cards;
	philshand = new hand();
	carolshand = new hand();
	phil = new AI("Phil",p,philshand);
	carol = new AI("Carol",c,carolshand);
	user->setDealer(true);
	phil->setSB(true);
	carol->setBB(true);
}

//Starter spillet
void holdem::start(){

	table = new hand();

	if(phil->getDealer()!=true){
		if(phil->getSB()==true){
			phil->takeBet(smallBlind);
		}
		else if(phil->getBB()==true){
			phil->takeBet(bigBlind);
		}
	}
	if(carol->getDealer()!=true){
		if(carol->getSB()==true){
			carol->takeBet(smallBlind);
		}
		else if(carol->getBB()==true){
			carol->takeBet(bigBlind);
		}
	}
	if(user->getDealer()!=true){
		if(user->getSB()==true){
			user->takeBet(smallBlind);
		}
		else if(user->getBB()==true){
			user->takeBet(bigBlind);
		}
	}

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
	cout << " \\          "<< user->getBet() <<"                              /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "             Your hand:" << userhand << endl;
	cout << "             "<<user->getName()<<", Bank: " << user->getBank() << endl;
}

//deler kort til alle spillerene
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

//Legger ut the flop (de 3 første kortene)
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
	phil->calcHandRank(table);
	carol->calcHandRank(table);
}

//Legger ut the turn (det fjerde kortet)
void holdem::theTurn(){
	table->addCard(cards->hit());

	std::string userhand = user->showHand();
	cout << "\n    Phil, Bank: "<< phil->getBank() <<"      Carol, Bank: " << carol->getBank() << endl;
	cout << "   _______________________________________" << endl;
	cout << "  /  "<< phil->getBet() <<"                  "<<carol->getBet()<<"               \\  " << endl;
	cout << " /                                         \\" << endl;
	cout << "|                                          |" << endl;
	cout << "|               "<<table->toString()<<"             |" << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << " \\          "<< user->getBet() <<"                              /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "             Your hand:" << userhand << endl;
	cout << "             "<<user->getName()<<", Bank: " << user->getBank() << endl;
	phil->calcHandRank(table);
	carol->calcHandRank(table);
}

//Legger ut the fifth street (de femte og siste kortet)
void holdem::fifthStreet(){
	table->addCard(cards->hit());

	std::string userhand = user->showHand();
	std::string philhand = phil->showHand();
	std::string carolhand = carol->showHand();
	cout << "\n    Phil, Bank: "<< phil->getBank() <<"      Carol, Bank: " << carol->getBank() << endl;
	cout << "    Phils hand: "<<philhand << "             Carols hand: " << carolhand << endl;
	cout << "   _______________________________________" << endl;
	cout << "  /  "<< phil->getBet() <<"                  "<<carol->getBet()<<"               \\  " << endl;
	cout << " /                                         \\" << endl;
	cout << "|                                          |" << endl;
	cout << "|            "<<table->toString()<<"            |" << "  Pot: $"<< pot << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << " \\          "<< user->getBet() <<"                              /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "             Your hand:" << userhand << endl;
	cout << "             "<<user->getName()<<", Bank: " << user->getBank() << endl;
	phil->calcHandRank(table);
	carol->calcHandRank(table);
}

//Viser bordet (uten kort på bordet)
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

void holdem::showFinalTable(){
	std::string userhand = user->showHand();
	std::string philhand = phil->showHand();
	std::string carolhand = carol->showHand();
	cout << "\n    Phil, Bank: "<< phil->getBank() <<"      Carol, Bank: " << carol->getBank() << endl;
	cout << "    Phils hand: "<<philhand << "             Carols hand: " << carolhand << endl;
	cout << "   _______________________________________" << endl;
	cout << "  /  "<< phil->getBet() <<"                  "<<carol->getBet()<<"               \\  " << endl;
	cout << " /                                         \\" << endl;
	cout << "|                                          |" << endl;
	cout << "|            "<<table->toString()<<"            |" << "  Pot: $"<< pot << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << " \\          "<< user->getBet() <<"                              /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "             Your hand:" << userhand << endl;
	cout << "             "<<user->getName()<<", Bank: " << user->getBank() << endl;
	phil->calcHandRank(table);
	carol->calcHandRank(table);
}

//Tar et bet fra brukeren
void holdem::takeBets(player* p, int b){
	p->takeBet(b);
	if(p->getBet() > highestBet){
		highestBet=p->getBet();
	}
	pot = pot + b;
}

//Tar bet fra AIene
void holdem::takeAIBets(){
	phil->takeBet(highestBet - phil->getBet());
	pot = pot + (highestBet - phil->getBet());

	cout << "Phil calls" << endl;
	phil->setReady(true);
	carol->takeBet(highestBet - carol->getBet());
	pot = pot + (highestBet - carol->getBet());
	cout << "Carol calls" << endl;
	carol->setReady(true);
}

//bytter rollene, dvs hvem som er dealer, small blind og big blind
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

//Sjekker om alle er klare til å gå videre
bool holdem::allReady(){
	if(user->getReady()==true && phil->getReady()==true && carol->getReady()==true){
		return true;
	}
	else
		return false;
}

//Setter spillerene til ikke klare
void holdem::reset(){
	//highestBet=0;
	phil->setReady(false);
	carol->setReady(false);
	user->setReady(false);
}

//Tilbakestiller
void holdem::newRound(){
	highestBet=0;
	pot=0;
	phil->setReady(false);
	carol->setReady(false);
	user->setReady(false);
	phil->setFolded(false);
	carol->setFolded(false);
	user->setFolded(false);	

	user->resetBet();
	phil->resetBet();
	carol->resetBet();

	table->clearHand();
	playerhand->clearHand();
	philshand->clearHand();
	carolshand->clearHand();

}

void holdem::calcPotOdds(AI* ai){
	double p = 0.00 + pot;
	double h = highestBet + 0.00;
	ai->calcPO(p,h);
}

AI* holdem::getPhil(){return phil;}

AI* holdem::getCarol(){return carol;}

hand* holdem::getTable(){return table;}

int holdem::getPot(){return pot;}

int holdem::getHighestBet(){return highestBet;}

int holdem::getNumberOfPlayers(){return players;}

void holdem::crownWinner(){
	int u = user->calcHandRank(table);
	int p = phil->calcHandRank(table);
	int c = carol->calcHandRank(table);

	std::string userhand = user->showHand();
	std::string philhand = phil->showHand();
	std::string carolhand = carol->showHand();
	cout << "\n    Phil, Bank: "<< phil->getBank() <<"      Carol, Bank: " << carol->getBank() << endl;
	cout << "    Phils hand: "<<philhand << "             Carols hand: " << carolhand << endl;
	cout << "   _______________________________________" << endl;
	cout << "  /  "<< phil->getBet() <<"                  "<<carol->getBet()<<"               \\  " << endl;
	cout << " /                                         \\" << endl;
	cout << "|                                          |" << endl;
	cout << "|            "<<table->toString()<<"            |" << "  Pot: $"<< pot << endl;
	cout << "|                                          |" << endl;
	cout << "|                                          |" << endl;
	cout << " \\          "<< user->getBet() <<"                              /" << endl;
	cout << "  \\_______________________________________/" << endl;
	cout << "             Your hand:" << userhand << endl;
	cout << "             "<<user->getName()<<", Bank: " << user->getBank() << endl;
	phil->calcHandRank(table);
	carol->calcHandRank(table);

	cout << "Your hand score: " << u << endl;
	cout << "Phil hand score: " << p << endl;
	cout << "Carol hand score: " << c << endl;
	cout << "Your highcard: " << user->getHigh() << endl;
	cout << "Phils highcard: " << phil->getHigh() << endl;
	cout << "Carols highcard: " << user->getHigh() << endl;

	if(user->getFolded()){
		u = 0;
	}
	if(phil->getFolded()){
		p=0;
	}
	if(carol->getFolded()){
		c=0;
	}

	if(u>p && u>c){
		cout << "You win!" << endl;
		user->updateBank(pot);
	}
	else if(p>u && p>c){
		cout << "Phil wins!" << endl;
		phil->addWins();
		phil->updateBank(pot);
	}
	else if(c>u && c>p){
		cout << "Carol wins!" << endl;
		carol->addWins();
		carol->updateBank(pot);
	}
	else if(u==p && u==c){
		if(user->getHigh()>phil->getHigh() && user->getHigh()>carol->getHigh()){
			cout << "High card, you win!" << endl;
			user->updateBank(pot);
		}
		else if(phil->getHigh()>user->getHigh() && phil->getHigh()>carol->getHigh()){
			cout << "Phil wins on high card" << endl;
			phil->addWins();
			phil->updateBank(pot);
		}
		else if(carol->getHigh()>user->getHigh() && carol->getHigh()>phil->getHigh()){
			cout << "Carol wins on high card" << endl;
			carol->addWins();
			carol->updateBank(pot);
		}
		else{
			cout << "Tie between all of you" << endl;
			user->updateBank(pot/3);
			user->updateBank(pot/3);
			user->updateBank(pot/3);
		}
	}
	else if(u==p){
		if(user->getHigh()>phil->getHigh()){
			cout << "High card, you win!" << endl;
			user->updateBank(pot);
		}
		else if(phil->getHigh()>user->getHigh()){
			cout << "Phil wins on high card!" << endl;
			phil->addWins();
			phil->updateBank(pot);
		}
	}
	else if(u==c){
		if(user->getHigh()>carol->getHigh()){
			cout << "High card, you win!" << endl;
			user->updateBank(pot);
		}
		else if(carol->getHigh()>user->getHigh()){
			cout << "Carol wins on high card!" << endl;
			carol->addWins();
			carol->updateBank(pot);
		}
	}
	else if(p==c){
		if(carol->getHigh()>phil->getHigh()){
			cout << "Carol wins on high card!" << endl;
			carol->addWins();
			carol->updateBank(pot);
		}
		else if(phil->getHigh()>carol->getHigh()){
			cout << "Phil wins on high card!" << endl;
			phil->addWins();
			phil->updateBank(pot);
		}
	}
	else if(u==p){
		cout << "Tie between you and phil" << endl;
		user->updateBank(pot/2);
		phil->updateBank(pot/2);
	}
	else if(u==c){
		cout << "Tie between you and carol" << endl;
		user->updateBank(pot/2);
		carol->updateBank(pot/2);
	}
	else if(p==c){
		cout << "Tie between phil and carol" << endl;
		phil->updateBank(pot/2);
		carol->updateBank(pot/2);
	}
}

holdem::~holdem(){}