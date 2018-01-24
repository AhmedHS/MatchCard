#include "MatchPlayer.h"

MatchPlayer::MatchPlayer() {} //default constructor
MatchPlayer::MatchPlayer(int playerNum, OrderedList<MatchCard> playerHand) {
	num = playerNum;
	hand = playerHand;
}
MatchPlayer::~MatchPlayer(){} //default destructor
int MatchPlayer::cardMatchRank(MatchCard card) {
	for (int x = 0; x < hand.getLength(); x++) { //searches the player's hand for a card with an identical rank
		if (hand.retrieve(x + 1).getRank() == card.getRank()) {
			return x + 1; //returns the list index where the matching card is located
		}
	}
	return -1;
}
int MatchPlayer::cardMatchSuit(MatchCard card) {
	for (int x = 0; x < hand.getLength(); x++) { //searches the player's hand for a card with an identical rank
		if (hand.retrieve(x + 1).getSuit() == card.getSuit()) {
			return x + 1; //returns the list index where the matching card is located
		}
	}
	return -1;
}
ostream& operator<<(ostream& os, const MatchPlayer &c) {
	os << "Player " << c.getNum();
	return os;
}