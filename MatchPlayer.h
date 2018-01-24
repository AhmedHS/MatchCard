#include <iostream>
#include "MatchCard.h"
#include "OrderedList.h"

using namespace std;
class MatchPlayer
{
public:
	MatchPlayer();
	MatchPlayer(int playerNum, OrderedList<MatchCard> playerHand);
	~MatchPlayer();
	int cardMatchRank(MatchCard card); //Used to find a card in the player's hand with a matching rank
	int cardMatchSuit(MatchCard card);//Used to find a card in the player's hand with a matching suit
	inline void setNum(int input) { num = input; }
	inline int getNum(void) const { return num; }

	OrderedList<MatchCard> hand;
private:
	int num; //stores the number of the player, i.e Player 1, Player 2
	friend ostream& operator<<(ostream& os, const MatchPlayer &c); //Outputs the player's name
};
