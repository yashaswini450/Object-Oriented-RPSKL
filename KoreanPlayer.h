#ifndef KOREAN_PLAYER_H
#define KOREAN_PLAYER_H

#include "player.h"

// KoreanPlayer inherits from Player to reuse ID, name, etc.
class KoreanPlayer: public Player{
private:
   Tool* tool_right; // Tool for the right hand

public:
   KoreanPlayer(const string& name);

   virtual ~KoreanPlayer();
   using Player::choose;

   // Overloaded choose method to select a tool for a specific hand ('l' or 'r')
   Tool& choose(char leftOrRight, char type, int strength);

   // Helper to get a reference to a tool on a specific hand
   Tool& getHand(char leftOrRight);
};
#endif