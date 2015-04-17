#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "holdem.hpp"

using namespace std;

deck* createDeck(){
	
	deck* _deck = new deck();
	_deck->shuffle();
	return _deck;
}

int main(){
	srand((unsigned int)time(NULL));
	cout << endl;
	cout << endl;
	cout << endl;

	cout << " ___   _  _     _  _______  _______  _______ " << endl;
	cout << "|   | | || | _ | ||       ||       ||       |" << endl;
	cout << "|   |_| || || || ||____   ||    ___||    ___|" << endl;
	cout << "|      _||       | ____|  ||   |___ |   |___ " << endl;
	cout << "|     |_ |       || ______||    ___||    ___|" << endl;
	cout << "|    _  ||   _   || |_____ |   |    |   |___ " << endl;
	cout << "|___| |_||__| |__||_______||___|    |_______|" << endl;
	cout << endl;
	cout << "Know When to Fold 'Em©\nCreated by Mads Karlstad" << endl;
	cout << "\nSmall and large blinds will be withdrawn from your account automatically" << endl;
	cout << endl;

	deck* deckofcards = createDeck();

	cout << "Enter your name" << endl;
	string name;
	cin>>name;
	hand* h = new hand();
	player* person = new player(name,1000,h);
	holdem* game = new holdem(person,deckofcards);
	string play = "y";
	while(play == "y"){
		string action = "c";
		player* phil = game->getPhil();
		player* carol = game->getCarol();
		game->start();
		cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
		cin>>action;
		if(!cin.fail()){
			if(action=="f" || action=="F"){

			}
			else if(action=="c" || action=="C"){
				person->takeBet(game->getHighestBet() - person->getBet());
				game->showTable();
			}
			else if(action=="r" || action=="R"){
				int bet;
				cout << "How much would you like to bet?" << endl;
				cin>>bet;
				if(!cin.fail()){
					
				}
			}
			else{
				cout << "Enter a valid input! 'f','c' or 'r' " << endl;
				cin.clear();
				cin>>action;
			}
		}
		//game->theFlop();
		//game->showTable();
		break;
	}
	return 0;
}