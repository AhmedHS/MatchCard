#include <iostream>
#include"MatchGame.h"

using namespace std;

int main (){
	int players, rank;
	cout << "Welcome to MATCH" << endl << "How many players will be in the game?" << endl;
	cin >> players;
	cout << "Please enter the maximum card rank you would like to play with: " << endl;
	cin >> rank;
	while (4*rank < 6*players) { //Checks to see if there are enough cards to give each player 6 cards
		cout << "Not enough cards for all players, please enter an adequate rank: " << endl;
		cin >> rank;
	}
	MatchGame game(players,rank);
	cout << "Game Start" << endl;
	game.play();
	return 0;
}