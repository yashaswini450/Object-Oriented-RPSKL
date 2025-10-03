#ifndef KOREAN_GAME_H
#define KOREAN_GAME_H

#include "game.h"
#include "KoreanPlayer.h"

// KoreanGame inherits from Game to reuse registration logic
class KoreanGame:public Game{
private:

   // This method decides the winner based on the remaining hands 
   void remove_hand(char player1_hand, char player2_hand);

public:
  KoreanGame(const string& name);

  // Overloaded playGame method for the Korean variant
  void playGame(char type1_1, int strength1_1, char type1_2,int strength1_2,
    char type2_1, int strength2_1, char type2_2,int strength2_2, char player1_hand, char player2_hand);

};
#endif