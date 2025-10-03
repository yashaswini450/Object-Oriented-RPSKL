#include "KoreanGame.h"
#include <iostream> 

KoreanGame::KoreanGame(const string& name):Game(name){}


void KoreanGame::remove_hand(char player1_hand, char player2_hand) {
    KoreanPlayer* p1 = dynamic_cast<KoreanPlayer*>(players[0]);
    KoreanPlayer* p2 = dynamic_cast<KoreanPlayer*>(players[1]);
    if (!p1 || !p2) return;

    // Determine which hand each player keeps for the final fight
    char p1_remaining_hand = (player1_hand == 'l') ? 'r' : 'l';
    char p2_remaining_hand = (player2_hand == 'l') ? 'r' : 'l';

    // std::cout << "[DEBUG] remove_hand: Final fight is P1's '" << p1_remaining_hand 
    //           << "' hand vs P2's '" << p2_remaining_hand << "' hand." << std::endl;


    // Get the two tools that will actually fight
    Tool& final_tool1 = p1->getHand(p1_remaining_hand);
    Tool& final_tool2 = p2->getHand(p2_remaining_hand);

    // Perform the single, decisive fight
    bool p1_wins = final_tool1.fight(final_tool2);
    bool is_tie = !p1_wins && !final_tool2.fight(final_tool1);

    // Set the final winner status on the players
    if (is_tie) {
        p1->setWinner(false);
        p2->setWinner(false);
    } else {
        p1->setWinner(p1_wins);
        p2->setWinner(!p1_wins);
    }
}

void KoreanGame::playGame(char type1_1, int strength1_1, char type1_2,int strength1_2,
    char type2_1, int strength2_1, char type2_2,int strength2_2, char player1_hand,char player2_hand){
   
    // Cast players to KoreanPlayer to access the two-handed choose method.
    KoreanPlayer* p1= dynamic_cast<KoreanPlayer*>(players[0]);
    KoreanPlayer* p2= dynamic_cast<KoreanPlayer*>(players[1]);

    if(!p1|| !p2) return;


    p1->choose('l',type1_1, strength1_1);
    p2->choose('l', type2_1,strength2_1);

    p1->choose('r',type1_2, strength1_2);
    p2->choose('r', type2_2,strength2_2);

    // The actual fight happens in remove_hand based on remaining hands.
    remove_hand(player1_hand, player2_hand);

    // registerWinner is now called based on the outcome of the final fight.
    registerWinner();
}
