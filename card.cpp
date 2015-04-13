#include "card.hpp"
#include <iostream>

using namespace std;
//♠ ♥ ♦ ♣ Klasse for kort
card::card(int s,int r){
	suit = s;
	rank = r;
	if(s==1){_suit = "♠";}
	else if(s==2){_suit = "♥";}
	else if(s==3){_suit="♦";}
	else{_suit="♣";}

	if(r==1){_rank="A";}
	else if(r==11){_rank="J";}
	else if(r==12){_rank="Q";}
	else if(r==13){_rank="K";}
	else{_rank=std::to_string(r);}
}

int card::get_suit(){
	return suit;
}

int card::get_rank(){
	int sum;
	if(rank==11 || rank==12 || rank==13){
		sum = 10;
	}
	else{sum=rank;}
	return sum;
}

std::string card::toString(){
	std::string print = "";
	print = _rank + _suit;
	return print;
}

card::~card(){}