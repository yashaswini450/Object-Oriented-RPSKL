#include "rpskl.h"
#include <iostream>

Tool::Tool(int s , char t): strength(s), type(t), winner(false){}

int Tool::getStrength() const{
   return strength;
}

char Tool::getType() const{
   return type;
}

bool Tool::isWinner() const{
   return winner;
}

void Tool:: setWinner(bool w){
   this->winner=w;
}

// Determines the outcome based on the type matchup returns 1 if type1 wins, -1 if type2 wins, 0 for a tie.
int compareTypes(char type1, char type2){
   if(type1==type2) return 0;//tie
   
   switch(type1){
      case 'r': return (type2== 's'|| type2=='l') ? 1:-1;
      case 'p': return (type2== 'r'|| type2=='k') ? 1:-1;
      case 's': return (type2== 'p'|| type2=='l') ? 1:-1;
      case 'k': return (type2== 's'|| type2=='r') ? 1:-1;
      case 'l': return (type2== 'p'|| type2=='k') ? 1:-1;
   }
   return 0;
}


bool genericFight(Tool& self, Tool& opponent) {
   // First, determine the winner based on type
   int typeResult = compareTypes(self.getType(), opponent.getType());
   
   // Determine temporary strength for 'self' based on the rules
   double selfTempStrength = self.getStrength();
   if (typeResult== -1) {
       selfTempStrength /= 2.0;
   } else if (typeResult==1) {
       selfTempStrength *= 2.0;
   }

   // The winner is the one with the higher temporary strength
   bool result = selfTempStrength > opponent.getStrength();

   // std::cout << "[DEBUG] genericFight: " << self.getType() 
   //            << "(" << self.getStrength() << ") vs " 
   //            << opponent.getType() << "(" << opponent.getStrength() 
   //            << "). Result: " << std::boolalpha << result << std::endl;

    return result;
}

Rock::Rock(int s): Tool(s, 'r'){}
bool Rock::fight(Tool& opponent){return genericFight(*this, opponent);}

Paper::Paper(int s): Tool(s, 'p'){}
bool Paper::fight(Tool& opponent){return genericFight(*this, opponent);}

Scissors::Scissors(int s): Tool(s, 's'){}
bool Scissors::fight(Tool& opponent){return genericFight(*this, opponent);}

Spock::Spock(int s): Tool(s, 'k'){}
bool Spock::fight(Tool& opponent){return genericFight(*this, opponent);}

Lizard::Lizard(int s): Tool(s, 'l'){}
bool Lizard::fight(Tool& opponent){return genericFight(*this, opponent);}