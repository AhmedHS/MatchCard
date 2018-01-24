#include "MatchGame.h"
MatchGame::MatchGame(int players, int rank) {
	playerLength = players;
	playerList = new MatchPlayer[players];
	deck = new MatchCard[4 * rank];
	for (int i = 0; i < players; i++) { //populates the list of players with playerIDs so they can be referenced later i.e Player 1
		playerList[i].setNum(i + 1);
	}
	int suitController = 2; //used to alternate between the suits of the cards when they are being created
	//Creates all cards of the deck (4x rank) cards
	for (int i = 0; i < 4 * rank; i++) {
		Suit cardType;
		if (suitController % 2 == 0 && i % 2 == 0) //suitController = even i = even
			cardType = DIAMONDS;
		else if (suitController % 2 != 0 && i % 2 == 0) //suitController = odd i = even
			cardType = SPADES;
		else if (suitController % 2 == 0 && i % 2 != 0)//suitController = even i = odd
			cardType = HEARTS;
		else if (suitController % 2 != 0 && i % 2 != 0)//suitController = odd i = odd
			cardType = CLUBS;
		if (suitController == 1 && i % 2 == 0) { suitController = 2; }
		else if (suitController == 2 && i % 2 == 0) { suitController = 1; }
		deck[i].setRank((i / 4) + 1); //(i/4) +1 is used to ensure that 4 cards of each rank are made
		deck[i].setSuit(cardType);
		deckPileShuffle.append(MatchCard(cardType, (i / 4) + 1));
	}
	srand(time(NULL));
	//Randomizing the deck pile
	for (int i = 4 * rank; i > 1; i--) { //Starts from the last elements and swaps it out with any element before it in the array
		int x = rand() % (i + 1); // picks a random index from 0 to i
		//Swaps the index i with the randomly selected index
		deckPileShuffle.swap(x+1, i);
	}
	for (int i = 0; i < 4*rank; i++) { //populates the deck pile with the shuffled cards
		deckPile.enqueue(deckPileShuffle.popBack());
	}
	//Distributing cards from deck piles to players' hands
	for (int i = 0; i < players * 6; i++) {
			playerList[i%players].hand.insert(deckPile.dequeue());
	}
	faceUpCards.push(deckPile.dequeue()); //places one card into the face up pile
	cout << "Face Up Card: " << faceUpCards.peek() << endl;
}
MatchGame::~MatchGame() {
	delete[] playerList;
	delete[] deck;
}

void MatchGame::play() {
	bool finished = false;
	while (!finished) {
		for (int i = 0; i < playerLength; i++) {//Computes each player's turn
			cout << "\nIt is " << playerList[i]<< "'s turn" << endl;
			bool found = false; //used to track whether a matching card was found
			int index = playerList[i].cardMatchRank(faceUpCards.peek());
			if ( index != -1) {
				cout << playerList[i] << " found a match! They played " << playerList[i].hand.retrieve(index) << endl;
				faceUpCards.push(playerList[i].hand.remove(index)); //removes the card from the player's hand and adds it to the face up cards
				found = true;
			}
			if (!found) { 
				index = playerList[i].cardMatchSuit(faceUpCards.peek()); //will only search for another card if a matching card has not been found yet
				if (index != -1) {
					cout << playerList[i] << " found a match! They played " << playerList[i].hand.retrieve(index) << endl;
					faceUpCards.push(playerList[i].hand.remove(index)); //removes the matching card from the player's hand and adds it to the face up cards
					found = true;
				}
			}
			if (!found) { //if no card with the same rank OR suit has been found
				if (!(deckPile.isEmpty())) { //checks if the deck still has cards in it
					playerList[i].hand.insert(deckPile.dequeue());
					cout << playerList[i] << " did not find a match. They drew a card" << endl;
				}
				else {
					MatchCard temp = faceUpCards.peek(); //Saves the top card in the face up cards pile
					for (int x = 1; x <= faceUpCards.size();x++) {
						if (x != 1)// will not enqueue the top card, which is to remain in the face up cards pile
							faceDownCards.enqueue(faceUpCards.pop());
						else
							faceUpCards.pop();
					}
					while (!(faceDownCards.isEmpty())) { //repopulates the deck pile with the face down cards pile
						deckPile.enqueue(faceDownCards.dequeue());
					}
					faceUpCards.push(temp); //places the saved card back into the face up cards pile
					cout << "The deck has been repopulated\n" << endl;
				}
			}
			if (playerList[i].hand.getLength() == 1) {
				cout << playerList[i] << " yells Last-card!" << endl;
			}
			else if (playerList[i].hand.getLength() == 0) {
				finished = true; //ends the game
				cout << playerList[i] << " has crushed their enemies in MATCH (not even close)" << endl;
				break;
			}
		}
	}
}