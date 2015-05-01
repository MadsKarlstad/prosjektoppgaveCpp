#include "player.hpp"
#include <iostream>

using namespace std;

player::player(std::string n,int m,hand* _hand){
	name = n;
	money = m;
	playerhand = _hand;
}

void player::setHand(hand* h){
	playerhand = h;
}

int player::updateBank(int m){
	money = money + m;
	return money;
}

int player::getBank(){
	return money;
}

int player::handsum(){
	return playerhand->handSum();
}

void player::takeBet(int b){
	bet = bet + b;
	money = money - b;
}

void player::resetBet(){
	bet=0;
}

std::string player::showHand(){
	std::string print = "";
	print += playerhand->toString();
	return print;
}
std::string player::getName(){
	return name;
}
hand* player::getHand(){
	return playerhand;
}
void player::setReady(bool _b){
	ready = _b;
}
void player::setBB(bool b){
	bigBlind = b;
}
void player::setSB(bool b){
	smallBlind = b;
}
void player::setDealer(bool b){
	dealer = b;
}
bool player::getReady(){
	return ready;
}
bool player::getBB(){
	return bigBlind;
}
bool player::getSB(){
	return smallBlind;
}
bool player::getDealer(){
	return dealer;
}
int player::getBet(){
	return bet;
}

int player::calcHandRank(hand* table){
	card temp = playerhand->getCard(0);
	card temp2 = playerhand->getCard(1);
	if(temp.get_rank()==1){
		highcard=14;
	}
	else if(temp2.get_rank()==1){
		highcard=14;
	}
	else if(temp.get_rank()>temp2.get_rank()){
		highcard=temp.get_rank();
	}
	else
		highcard=temp2.get_rank();

	
	int mycards[13] = {0};
	for(int i=0;i<table->getSize();i++){
		card temp = table->getCard(i);
		if(mycards[temp.get_rank()-1] >= 1){
			mycards[temp.get_rank()-1]++;
			//break;
		}
		else{
			mycards[temp.get_rank()-1]=1;
		}
	}
	for(int j=0;j<playerhand->getSize();j++){
		card temp = playerhand->getCard(j);
		if(mycards[temp.get_rank()-1] > 0){
			mycards[temp.get_rank()-1]++;
		}
		else{
			mycards[temp.get_rank()-1] = 1;
		}
	}


	//Royal straight flush
	if(mycards[0]>0 && mycards[9]>0 && mycards[10]>0 && mycards[11]>0 && mycards[12]>0){
		handRank = 11;
		return handRank;
	}
	//Four of a kind
	for(int i=0;i<13;i++){
		if(mycards[i] == 4){
			handRank = 9;
			return handRank;
		}
	}
	//Full house
	bool three = false;
	bool two = false;
	for(int i=0;i<13;i++){
		if(mycards[i] == 3){
			three = true;
		}
		else if(mycards[i] == 2){
			two = true;
		}
		if(three==true && two==true){
			handRank = 8;
			return handRank;
		}
	}
	//Flush
	for(int i=0;i<13;i++){
		

	}
	//Straight

	//Three of a kind
	for(int i=0;i<13;i++){
		if(mycards[i] == 3){
			handRank = 5;
			return handRank;
		}
	}

	//Two pairs
	bool pairone = false;
	bool pairtwo = false;
	for(int i=0;i<13;i++){
		if(mycards[i] == 2 && pairone == false){
			pairone = true;
		}
		else if(mycards[i] == 2 && pairone == true){
			pairtwo = true;
		}
		if(pairone == true && pairtwo == true){
			handRank = 4;
			return handRank;
		}
	}

	//Pair
	for(int i=0;i<13;i++){
		if(mycards[i] == 2){
			handRank = 3;
			return handRank;
		}
	}

	//Else nothing

	

	return handRank;
}

void player::setFolded(bool b){folded=b;}

int player::getHigh(){
	return highcard;
}

bool player::getFolded(){return folded;}

int player::getHandRank(){
	return handRank;
}

player::~player(){}