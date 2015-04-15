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
	cout << "#     # #               #  #####   ######## #######" << endl;
	cout << "#   #   #               # #     #  #        #" << endl;
	cout << "# #     #               #        # #        #" << endl;
	cout << "##       #             #         # ####     #####" << endl;
	cout << "# #       #     #     #         #  #        #" << endl;
	cout << "#   #      #   # #   #         #   #        #" << endl;
	cout << "#    #      # #   # #        #     #        #" << endl;
	cout << "#     #      #     #       ####### #        #######" << endl;
	cout << endl;
	cout << "Know When to Fold 'Em©\nCreated by Mads Karlstad" << endl;
	cout << endl;	

	deck* deckofcards = createDeck();

	cout << "Enter your name" << endl;
	string name;
	cin>>name;
	player* person = new player(name,1000);
	//player* phil = new player("Phil",1000);
	//player* carol = new player("Carol",1000);
	//hand* playerhand = new hand();
	//person->setHand(playerhand);

	holdem* game = new holdem(person,deckofcards);
	game->start();
	//game->theFlop();
	//game->showTable();
}