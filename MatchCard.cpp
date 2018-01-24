
#include "MatchCard.h"

MatchCard::MatchCard() {
	m_suit = SPADES;
	m_rank = 1;
}
MatchCard::MatchCard(Suit suit, int numRank){
	m_suit = suit;
	m_rank = numRank;
}

// destructor
MatchCard::~MatchCard()
{
}

std::ostream& operator<<(std::ostream& os, const MatchCard &c) {
	int suit = c.getSuit();
	int rank = c.getRank();
	if (rank == 1) os << "Ace";
	else os << rank;
	switch (suit) {
	case 1:
		os << " of Spades";
		break;
	case 2:
		os << " of Hearts";
		break;
	case 3:
		os << " of Clubs";
		break;
	default:
		os << " of Diamonds";
	}
	return os;
}