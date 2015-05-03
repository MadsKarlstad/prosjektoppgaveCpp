#include "AI.hpp"
#include <iostream>

using namespace std;

AI::AI(std::string n,int m,hand* _hand,bool d,bool bb, bool sb) : player(n,m,_hand,d,bb,sb){
	
}
//Enkel metode for å gjøre action til en AI
int AI::getAction(deck* d, hand* table, int highestbet){
	int fold = -1;
	int call = 1;
	int check = 0;
	bool bluff;
	int raisebet;
	int betNeeded = highestbet - getBet();

	if(getHandRank()==11){
		raisebet = rand() % 1000;
		setReady(true);
		return raisebet + betNeeded;
	}
	else if(getHandRank()==10){
		raisebet = rand() % 700;
		setReady(true);
		return raisebet + betNeeded;
	}
	else if(getHandRank()==9){
		raisebet = rand() % 70;
		setReady(true);
		return raisebet + betNeeded;
	}
	else if(getHandRank()==8){
		raisebet = rand() % 60;
		setReady(true);
		return raisebet + betNeeded;
	}
	else if(getHandRank()==5){
		raisebet = rand() % 40;
		setReady(true);
		return raisebet + betNeeded;
	}
	else if(getHandRank()==4){
		raisebet = rand() % 35;
		setReady(true);
		return raisebet + betNeeded;
	}
	else if(getHandRank()==3){
		raisebet = rand() % 25;
		setReady(true);
		return raisebet + betNeeded;
	}
	else if(getHandRank()==0){
		if(getHigh()>10){
			int b = rand() % 100;
			if(b>70){
				raisebet = rand() % 20;
				setReady(true);
				return raisebet + betNeeded;
			}
			else{
				takeBet(raisebet);
				setReady(true);
				return betNeeded;
			}
		}
		else if(getHigh()<=10){
			setReady(true);
			return fold;
		}
	}
	if(betNeeded < -1){
		betNeeded =0;
	}
	if(betNeeded+getBet() > getBank()){
		betNeeded = getBank();
	}
	if(betNeeded>getBank()){
		betNeeded = getBank();
	}
	setReady(true);
	return betNeeded;
}
//Regner ut Pot Odds (Ubrukt metode)
void AI::calcPO(double pot, double highestbet){
	double need = 0.00 + (highestbet - getBet());
	PO = need/(need + pot);
}
//Regner ut Rate of return (Ubrukt metode)
void AI::calcRR(){
	RR = HS/PO;
}
//Regner ut Hand strength (Ubrukt metode)
void AI::calcHS(deck* d, hand* table){
	hand* h1 = new hand();
	hand* h2 = new hand();
	hand* aiHand = getHand();
	hand* tablepointer = table;
	

	for(int i = 0;i<101;i++){
		deck* d_ = new deck();
		d_->shuffle();
		h1->addCard(d_->hit());
		h2->addCard(d_->hit());
		h1->addCard(d_->hit());
		h2->addCard(d_->hit());
		while(table->getSize() < 5){
			tablepointer->addCard(d_->hit());
		}
		delete d_;
		//game->crownWinner() //Må legges til
		//if(win==true) wins +=1
	}
	delete tablepointer;
	HS = wins/100;
}

//Ubrukt metode
void AI::addWins(){wins++;}

int AI::getWins(){return wins;}

double AI::getRR(){return RR;}
double AI::getPO(){return PO;}
double AI::getHS(){return HS;}

AI::~AI(){}