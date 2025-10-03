#include "game.h"
#include <iostream>
#include <string>

Game::Game(const string& n): playerCount(0), nextPlayerIndex(0),name(n), winner(nullptr){
   players[0]=nullptr;
   players[1]=nullptr;
}

void Game::registerPlayer(Player &p){
    if(playerCount<2){
        players[playerCount++]=&p; // Store a pointer to the player
    }
}

Game::~Game(){}

Player& Game::choose(){
    Player& currPlayer= *players[nextPlayerIndex]; // Alternate players for the next call
    nextPlayerIndex= (nextPlayerIndex+1)%2;
    return currPlayer;
} 

bool Game::verifyRegistration(){
    return (playerCount==2 && players[0]->getId() != players[1]->getId());
}


void Game::registerWinner() {
    // This is a debug line to confirm the player statuses before we choose a winner.
    // std::cout << "[DEBUG] registerWinner: p1 winner? " << std::boolalpha << players[0]->isWinner() 
    //           << ", p2 winner? " << std::boolalpha << players[1]->isWinner() << std::endl;

    // Reset the game's winner before checking
    this->winner = nullptr;

    // Check the player flags (which were set in playGame) to find the winner
    if (players[0]->isWinner()) {
        this->winner = players[0];
    } else if (players[1]->isWinner()) {
        this->winner = players[1];
    }
}

bool Game::doubleCheck() {
    // If there's no winner (it was a tie), the check fails.
    if (this->winner == nullptr) {
        return false;
    }

    // Identify the winning and losing players
    Player* p_winner = this->winner;
    Player* p_loser = (p_winner->getId() == players[0]->getId()) ? players[1] : players[0];

    // Condition 1: The winning player's flag is true.
    bool f = p_winner->isWinner();

    // Condition 2: The losing player's flag is false.
    bool s = p_loser->isWinner();

    // The XOR operation `true ^ false` results in `true`.
    // This confirms a valid win/loss state and returns true (OK).
    return f ^ s;
}

string Game::getWinnerName() const{
    if(winner){
        return winner->getName();
    }
    return "its a tie!";
}

void Game::show() const{
    cout<< "Game: "<<name<<endl;
    if(playerCount>0) cout<<"Player 1: "<< players[0]->getName()<<endl;
    if(playerCount>1) cout<<"Player 2: "<< players[1]->getName()<<endl;
    
    if(winner){
        cout<<"Winner: "<<winner->getName()<<endl;
    }else{
        cout<<"Winner: No winner yet or it's a tie"<<endl;
    }
}

void Game:: playGame(char type1, int strength1,char type2 , int strength2){

//     choose().choose(type1, strength1).fight(choose().choose(type2, strength2));
//     registerWinner();
    Player& p1 = choose();
    Player& p2 = choose();

    Tool& tool1 = p1.choose(type1, strength1);
    Tool& tool2 = p2.choose(type2, strength2);

    bool p1_wins = tool1.fight(tool2);
    // A 'false' return can mean a loss or a tie. We check the reverse to be sure.
    bool is_tie = !p1_wins && !tool2.fight(tool1);

    // std::cout << "[DEBUG] playGame: p1_wins=" << std::boolalpha << p1_wins 
    // << ", is_tie=" << std::boolalpha << is_tie << std::endl;


    // Set the winner status on the Player objects based on the outcome
    if (is_tie) {
        p1.setWinner(false);
        p2.setWinner(false);
    } else {
        p1.setWinner(p1_wins);
        p2.setWinner(!p1_wins);
    }
    
    registerWinner();
}