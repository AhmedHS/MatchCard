#define DEFAULT_HAND 6
#include <iostream>
#include <ctime>
#include "Stack.h"
#include "Queue.h"
#include "MatchCard.h"
#include "MatchPlayer.h"

using namespace std;
class MatchGame
{
public:
	MatchGame(int players, int rank);
	~MatchGame();
	void play();

	//Variables
	Stack<MatchCard>faceUpCards; //cards on the deck that players can see
	Queue<MatchCard>faceDownCards; //cards on the deck that are face down, to be used to repopulate the deck
	MatchPlayer *playerList;
	MatchCard *deck; //used to store the original cards
	List<MatchCard> deckPileShuffle; //used to shuffle the cards
	Queue<MatchCard> deckPile; //Used as the pile of cards available for players to draw
private:
	int playerLength; //storing the number of players in the game
};
