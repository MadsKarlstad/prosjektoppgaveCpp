EXEC = KnowWhenToFoldEm
SRC = knowwhentofoldem.cpp card.cpp deck.cpp hand.cpp player.cpp holdem.cpp

all:
	g++ -std=c++11 $(SRC) -o $(EXEC)

clean:
	$(RM) $(EXEC)