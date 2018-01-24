# MatchCard


A package that implements multiple data types (i.e List, Stack, Queue) to simulate a card game between multiple players.

## The Game

- The user specifies the number of players and maximum card rank
- A deck is made consisting of ALL (4 x the maximum card rank) the cards as specified by the user
- 6 different cards will then be taken from the deck pile and placed into the hand of each player.  
- 1 card will be taken from the deck pile and placed into a face-up pile.
- Every turn, a player will put down a card that shares either the same rank or the same suit.
- If a player doesn't have a matching card they draw a card from the deck
- When the deck pile is empty, it is repopulated with the faceup pile
- The player to place all their cards down first is the winner

## Compiling

Before running code please ensure "VC++ 2015.3 v140 toolset (x86,x64)" is installed.

## Example Output
'
Welcome to MATCH
How many players will be in the game?
2
Please enter the maximum card rank you would like to play with:
4
Face Up Card: 2 of Diamonds
Game Start

It is Player 1's turn
Player 1 did not find a match. They drew a card

It is Player 2's turn
Player 2 found a match! They played 2 of Hearts

It is Player 1's turn
Player 1 found a match! They played 2 of Clubs

It is Player 2's turn
Player 2 found a match! They played 2 of Spades

It is Player 1's turn
Player 1 found a match! They played 4 of Spades

It is Player 2's turn
Player 2 found a match! They played 4 of Diamonds

It is Player 1's turn
Player 1 found a match! They played 4 of Clubs

It is Player 2's turn
Player 2 did not find a match. They drew a card

It is Player 1's turn
Player 1 found a match! They played 4 of Hearts

It is Player 2's turn
Player 2 found a match! They played 3 of Hearts

It is Player 1's turn
Player 1 found a match! They played 3 of Clubs

It is Player 2's turn
Player 2 found a match! They played 3 of Diamonds

It is Player 1's turn
Player 1 found a match! They played 3 of Spades
Player 1 yells Last-card!

It is Player 2's turn
Player 2 found a match! They played Ace of Spades
Player 2 yells Last-card!

It is Player 1's turn
Player 1 found a match! They played Ace of Hearts
Player 1 has crushed their enemies in MATCH (not even close)
Press any key to continue . . .
'