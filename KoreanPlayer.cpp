#include "KoreanPlayer.h"
#include <iostream>

 // The base 'tool' pointer from Player class will represent the left hand.
KoreanPlayer:: KoreanPlayer(const string& name): Player(name),tool_right(nullptr){}

KoreanPlayer::~KoreanPlayer(){
    delete tool_right; // tool_left (base class 'tool') is deleted by Player destructor
}

Tool& KoreanPlayer:: choose(char leftOrRight, char type, int strength){
    // std::cout << "[DEBUG] " << getName() << " chose " << type << "(" << strength 
    // << ") for hand '" << leftOrRight << "'" << std::endl;

    
    Tool** hand_to_use= nullptr;
    
    if(leftOrRight =='l'|| leftOrRight=='1'){
       hand_to_use= &tool;
    }else{
        hand_to_use =&tool_right;
    }

    delete *hand_to_use;
    *hand_to_use= nullptr;

    switch(type){
       case 'r': *hand_to_use= new Rock(strength); break;
       case 'p': *hand_to_use= new Paper(strength); break;
       case 's': *hand_to_use= new Scissors(strength); break;
       case 'k': *hand_to_use= new Spock(strength); break;
       case 'l': *hand_to_use= new Lizard(strength); break;
    }
    return **hand_to_use;
}

Tool& KoreanPlayer::getHand(char leftOrRight){
   if(leftOrRight=='l'||leftOrRight=='1'){
    return *tool; // left hand
   }else{
     return *tool_right; // right hand
    }
}