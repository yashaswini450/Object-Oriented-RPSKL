#include<cstring>
#include "player.h"
#include <stdexcept>

// Initialize the static ID counter
int Player::nextId=1;

Player:: Player(const string& n):name(n),tool(nullptr), winner(false){
   id= nextId++; // Assign a unique ID and increment the counter
}


Player:: ~Player(){
    delete tool; // Prevent memory leaks by deleting the dynamically allocated tool
}

Tool& Player:: choose(char type, int strength){
    delete tool;
    tool= nullptr;

    switch (type){
    case 'r': tool =new Rock(strength); break;
    case 'p': tool =new Paper(strength); break;
    case 's': tool =new Scissors(strength); break;
    case 'l': tool =new Lizard(strength); break;
    case 'k': tool =new Spock(strength); break;
    default: tool= new Rock(strength); break;
    }
    return *tool; // Return a reference to the newly created tool
}

int Player:: getId() const{
    return id;
}

const string& Player::getName() const{
    return name;
}

void Player::setName(const string& n){
    name=n;
}

bool Player::isWinner() const{
    return winner;
}

void Player::setWinner(bool w){
  winner=w;
}

Tool& Player::getLastUsedTool() const {
    if (!tool) {
        // This case should ideally not happen in the game flow, but it's good practice to handle null pointers to avoid crashes.
        throw std::runtime_error("Player has not chosen a tool yet.");
    }
    return *tool;
}