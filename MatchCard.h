#pragma once
#include <iostream>

// User defined Suit and Denomination types (user-defined integers) 
enum Suit { SPADES = 1, HEARTS = 2, CLUBS = 3, DIAMONDS = 4 };

class MatchCard
{
public:
	MatchCard(); //default constructor
	MatchCard(Suit suit, int numRank); // constructor with some default values
	~MatchCard(); // destructor
	inline void setSuit(Suit input) { m_suit = input; }
	inline Suit getSuit(void) const { return m_suit; }
	inline void setRank(int input) { m_rank = input; }
	inline int getRank(void) const { return m_rank; }

private:
	Suit m_suit; // private storage of suit
	int m_rank;
	friend std::ostream& operator<<(std::ostream& os, const MatchCard &c);
};

// global operator functions comparing suits of two cards
// The cards a and b are passed by reference
inline bool operator<(const MatchCard& a, const MatchCard& b) {
	return (a.getSuit()<b.getSuit());
}
inline bool operator>(const MatchCard& a, const MatchCard& b) {
	return (a.getSuit()>b.getSuit());
}

// checks equality of suits and ranks for two MatchCards
inline bool operator==(const MatchCard& a, const MatchCard& b) { 
	return ( (a.getSuit() == b.getSuit()) && (a.getRank() == b.getRank()) );
}

