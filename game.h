#ifndef GAME_H
#define GAME_H

#include "player.h"
#include <string>
using namespace std;

class Game{
protected:
   Player* players[2]; // Pointers to the two players in the game
   int playerCount;
   int nextPlayerIndex; // Used to alternate turns for the choose() method

   // Assigns the winning player as the game's winner
   virtual void registerWinner();

public:
   string name;
   string time;
   Player* winner;

   // Constructor to initialize the game
   Game(const string& n);

   // Virtual destructor for polymorphism
   virtual ~Game();

   // Registers a player for the game, max 2 players
   void registerPlayer(Player &p);

   // Checks if two unique players are registered 
   bool verifyRegistration();

   // Returns a reference to the player whose turn it is 
   Player& choose();

   // Executes a single round of the game
   void playGame(char type1, int strength1, char type2, int strength2);

   // Verifies that the winner/loser state is consistent
   bool doubleCheck();

   // Displays game details
   void show() const;

   // Helper to get the winner's name
   string getWinnerName() const;
};
#endif