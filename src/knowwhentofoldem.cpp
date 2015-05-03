//Skrevet av Mads M Karlstad, s193949
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
	int philsmoney = 1000;
	int carolsmoney = 1000;
	bool phildealer = false;
	bool caroldealer = false;
	bool userdealer = true;
	player* person = new player(name,1000,h,userdealer,false,false);

	string play = "y";
	string action = "c";

	while(play == "y"){
		deck* deckofcards = createDeck();
		holdem* game = new holdem(person,deckofcards,philsmoney,carolsmoney,userdealer,phildealer,caroldealer);
		AI* phil = game->getPhil();
		AI* carol = game->getCarol();
		vector<bool> activePlayers{true,true,true};

		//********************
		//* Starter spillet **
		//********************
		game->start();
		if(phil->getBank()<=0){
			phil->setFolded(true);
		}
		if(carol->getBank()<=0){
			carol->setFolded(true);
		}
		if(phil->getFolded() && carol->getFolded()){
			cout << "Congratulations! You beat the system, you are the poker champion!" << endl;
			play = "n";
		}
		if(person->getDealer()==true){
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
				}
			}
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
				}
			}
		}
		else if(phil->getDealer()==true){
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
				}
			}
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
				}
			}
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
		}
		else if(carol->getDealer()==true){
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
				}
			}
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
				}
			}

		}
		//*********************
		//* Starter the flop **
		//*********************
		if(game->allReady()){
			game->theFlop();
			game->reset();
		}
		while(!game->allReady()){
			if(person->getDealer()==true){
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					phil->setReady(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
					phil->setReady(true);
					
				}
			}
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					carol->setReady(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
					carol->setReady(true);
					
				}
			}
		}
		else if(phil->getDealer()==true){
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					phil->setReady(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
					phil->setReady(true);
					
				}
			}
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					carol->setReady(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
					carol->setReady(true);
					
				}
			}
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
		}
		else if(carol->getDealer()==true){
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					carol->setReady(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
					carol->setReady(true);
				}
			}
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					phil->setReady(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
					phil->setReady(true);
					
				}
			}

		}
		if(person->getBet() == game->getHighestBet() || person->getFolded()){
			person->setReady(true);
		}
		if(phil->getBet() == game->getHighestBet() || phil->getFolded()){
			phil->setReady(true);
		}
		if(carol->getBet() == game->getHighestBet() || carol->getFolded()){
			carol->setReady(true);
		}
		}
		//*********************
		//* Starter the turn **
		//*********************
		if(game->allReady()){
			game->theTurn();
			game->reset();
		}

		while(!game->allReady()){
			if(person->getDealer()==true){
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					phil->setReady(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
					phil->setReady(true);
					
				}
			}
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					carol->setReady(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
					carol->setReady(true);
					
				}
			}
		}
		else if(phil->getDealer()==true){
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					phil->setReady(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
					phil->setReady(true);
					
				}
			}
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					carol->setReady(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
					carol->setReady(true);
					
				}
			}
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
		}
		else if(carol->getDealer()==true){
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					carol->setReady(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
					carol->setReady(true);
				}
			}
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					phil->setReady(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
					phil->setReady(true);
					
				}
			}

		}
		if(person->getBet() == game->getHighestBet() || person->getFolded()){
			person->setReady(true);
		}
		if(phil->getBet() == game->getHighestBet() || phil->getFolded()){
			phil->setReady(true);
		}
		if(carol->getBet() == game->getHighestBet() || carol->getFolded()){
			carol->setReady(true);
		}
		}
		//*************************
		//* Starter fifth street **
		//*************************
		if(game->allReady()){
			game->fifthStreet();
			game->reset();
		}

		while(!game->allReady()){
			if(person->getDealer()==true){
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					phil->setReady(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
					phil->setReady(true);
					
				}
			}
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					carol->setReady(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
					carol->setReady(true);
					
				}
			}
		}
		else if(phil->getDealer()==true){
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					phil->setReady(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
					phil->setReady(true);
					
				}
			}
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					carol->setReady(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
					carol->setReady(true);
					
				}
			}
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
		}
		else if(carol->getDealer()==true){
			if(!carol->getFolded()){
				int c = carol->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(c<0){
					carol->setFolded(true);
					carol->setReady(true);
					activePlayers[2]=false;
					cout << "Carol folds" << endl;
				}
				else{
					if(c==0){
						cout << "Carol checks" << endl;
					}
					else{
						cout << "Carol sees the bet and raises $" << c << endl; 
					}
					game->takeBets(carol,c);
					carol->setReady(true);
				}
			}
			if(!person->getFolded()){
				cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
			if(!phil->getFolded()){
				int p = phil->getAction(deckofcards,game->getTable(),game->getHighestBet());
				if(p<0){
					phil->setFolded(true);
					phil->setReady(true);
					activePlayers[1]=false;
					cout << "Phil folds" << endl;
				}
				else{
					if(p==0){
						cout << "Phil checks" << endl;
					}
					else{
						cout << "Phil sees the bet and raises $" << p << endl; 
					}
					game->takeBets(phil,p);
					phil->setReady(true);
					
				}
			}

		}
			if(person->getBet() == game->getHighestBet() || person->getFolded()){
				person->setReady(true);
			}
			if(phil->getBet() == game->getHighestBet() || phil->getFolded()){
				phil->setReady(true);
			}
			if(carol->getBet() == game->getHighestBet() || carol->getFolded()){
				carol->setReady(true);
			}
		}
		if(person->getBet() < game->getHighestBet() && !person->getFolded()){
			cout << "Would you like to fold(F), call/check(C) or raise(R) the bet?" << endl;
				cin>>action;
				if(!cin.fail()){
					if(action=="f" || action=="F"){
        				person->setFolded(true);
        				activePlayers[0]=false;
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
							while(bet>person->getBank() || bet<0){
								cout << "You can't bet that much! Enter new bet" << endl;
								cin.clear();
								cin>>bet;
							}
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
		if(phil->getBet() < game->getHighestBet() && !phil->getFolded()){
			game->takeBets(phil, game->getHighestBet() - phil->getBet());
			phil->setReady(true);
		}
		if(carol->getBet() < game->getHighestBet() && !carol->getFolded()){
			game->takeBets(carol, game->getHighestBet() - carol->getBet());
			carol->setReady(true);
		}
		game->showFinalTable();
		game->crownWinner();
		game->newRound();
		game->switchRoles();
		userdealer = person->getDealer();
		phildealer = phil->getDealer();
		caroldealer = carol->getDealer();

		cout << "\nYou now have $" << person->getBank() << " worth of casino chips" << endl;
		cout << "\nWould you like to remain at the table?" << endl;
		cin >> play;
		if(play=="Y" || play=="Yes" || play=="yes" || play=="yup" || play=="yeah" || play=="ja"){
			play = "y";
		}
		if(person->getBank()<=0){
			cout << "\nYou are broke and cannot play anymore. Ending game." << endl;
			play = "n";
		}
		philsmoney = phil->getBank();
		carolsmoney = carol->getBank();
		delete deckofcards;
		delete game;
	}
	cout << "Thanks for playing Know When to Fold 'Em! We hope to see you again" << endl;
	delete person;
	delete h;
	return 0;
}