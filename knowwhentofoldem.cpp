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
	cout << "\nSmall and big blinds will be withdrawn from your account automatically" << endl;
	cout << endl;

	cout << "Enter your name" << endl;
	string name;
	cin>>name;
	
	hand* h = new hand();
	player* person = new player(name,1000,h);
	deck* deckofcards = createDeck();
	holdem* game = new holdem(person,deckofcards);


	
	string play = "y";
	string action = "c";

	while(play == "y"){
		
		AI* phil = game->getPhil();
		AI* carol = game->getCarol();
		vector<bool> activePlayers{true,true,true};

		game->start();
		
		if(person->getDealer()==true){
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        			person->setFolded(true);
        			activePlayers[0]=false;
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else
				game->takeBets(phil,p);
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else
				game->takeBets(carol,c);
		}
		else if(phil->getDealer()==true){
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,p);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< p << endl;
			}
			
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
		}
		else if(carol->getDealer()==true){
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< c << endl;
			}
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,c);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
		}

		
		//Starter the flop
		if(game->allReady()){
			game->theFlop();
			game->reset();
		}

		while(!game->allReady()){
		if(person->getDealer()==true){
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					//game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,p);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< c << endl;
			}
		}
		else if(phil->getDealer()==true){
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,p);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< c << endl;
			}
			
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					//game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
		}
		else if(carol->getDealer()==true){
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< c << endl;
			}
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					//game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,p);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
		}
		}		
		
		//Starter the turn
		if(game->allReady()){
			game->theTurn();
			game->reset();
		}

		while(!game->allReady()){
					if(person->getDealer()==true){
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					//game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,p);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< c << endl;
			}
		}
		else if(phil->getDealer()==true){
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,p);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< c << endl;
			}
			
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					//game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
		}
		else if(carol->getDealer()==true){
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< c << endl;
			}
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					//game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,p);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
		}
		}
		
		//Starter fifth street
		if(game->allReady()){
			game->fifthStreet();
			game->reset();
		}


		while(!game->allReady()){
					if(person->getDealer()==true){
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					//game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,p);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< c << endl;
			}
		}
		else if(phil->getDealer()==true){
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,p);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< c << endl;
			}
			
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					//game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
		}
		else if(carol->getDealer()==true){
			int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(c<0){
				carol->setFolded(true);
				activePlayers[2]=false;
				cout << "Carol folds" << endl;
			}
			else{
				game->takeBets(carol,c);
				cout << "Carol sees the bet an raises $"<< c << endl;
			}
			cout << "Would you like to fold(F), call(C) the bet of " << game->getHighestBet() << " ,or raise(R)?" << endl;
			cin>>action;
			if(!cin.fail()){
				if(action=="f" || action=="F"){
        		
				}
				else if(action=="c" || action=="C"){
					game->takeBets(person, game->getHighestBet() - person->getBet());
					person->setReady(true);
					game->showTable();
				}
				else if(action=="r" || action=="R"){
					int bet;
					cout << "How much would you like to bet?" << endl;
					cin>>bet;
					if(!cin.fail()){
						game->takeBets(person, bet);
						person->setReady(true);
					}
				}
				else{
					cout << "Enter a valid input! 'f','c' or 'r' " << endl;
					cin.clear();
					cin>>action;
				}
			}
			int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
			if(p<0){
				phil->setFolded(true);
				activePlayers[1]=false;
				cout << "Phil folds" << endl;
			}
			else{
				game->takeBets(phil,p);
				cout << "Phil sees the bet an raises $"<< p << endl;
			}
		}
		}

		game->crownWinner();



		game->newRound();
		game->switchRoles();

		cout << "\nWould you like to play another round, sire?" << endl;
		cin >> play;

		

		//break;
	}
	delete deckofcards;
	delete h;
	delete person;
	delete game;
	return 0;
}