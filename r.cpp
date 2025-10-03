#include <iostream>
#include <string>
#include <limits>
#include "game.h"
#include "KoreanGame.h"
#include "player.h"
#include "KoreanPlayer.h"

void playVanillaGame() {
    std::string gameName, p1_name, p2_name;

    std::cout << "Enter game: ";
    std::getline(std::cin, gameName);
    Game game(gameName);

    std::cout << "Register Player1: ";
    std::getline(std::cin, p1_name);
    Player p1(p1_name);

    std::cout << "Register Player2: ";
    std::getline(std::cin, p2_name);
    Player p2(p2_name);

    game.registerPlayer(p1);
    game.registerPlayer(p2);

    std::cout << "verifying registration... ";
    if (game.verifyRegistration()) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "NOK" << std::endl;
        std::cout << "Registration failed. Players might have the same ID or are not unique." << std::endl;
        return;
    }

    while (true) {
        char type1, type2;
        int strength1, strength2;
        std::cout << "Play with: ";
        std::cin >> type1 >> strength1 >> type2 >> strength2;

        game.playGame(type1, strength1, type2, strength2);
        std::cout << game.getWinnerName() << " own!" << std::endl;

        std::cout << "double checking... ";
        if (game.doubleCheck()) {
            std::cout << "OK" << std::endl;
            std::cout << "Congratulations!" << std::endl;
            break; // End game
        } else {
            std::cout << "NOK" << std::endl;
            // Loop continues for another round
        }
    }
}

void playKoreanGame() {
    std::string gameName, p1_name, p2_name;
    
    std::cout << "Enter game: ";
    std::getline(std::cin, gameName);
    KoreanGame game(gameName);

    std::cout << "Register Player1: ";
    std::getline(std::cin, p1_name);
    KoreanPlayer p1(p1_name);

    std::cout << "Register Player2: ";
    std::getline(std::cin, p2_name);
    KoreanPlayer p2(p2_name);

    game.registerPlayer(p1);
    game.registerPlayer(p2);

    std::cout << "verifying registration... ";
    if (game.verifyRegistration()) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "NOK" << std::endl;
        return;
    }

    while (true) {
        char t1_1, t1_2, t2_1, t2_2, h1, h2;
        int s1_1, s1_2, s2_1, s2_2;
        
        std::cout << "Play with: ";
        std::cin >> t1_1 >> s1_1 >> t1_2 >> s1_2 >> t2_1 >> s2_1 >> t2_2 >> s2_2 >> h1 >> h2;
        
        game.playGame(t1_1, s1_1, t1_2, s1_2, t2_1, s2_1, t2_2, s2_2, h1, h2);
        std::cout << game.getWinnerName() << " own!" << std::endl;

        std::cout << "double checking... ";
        if (game.doubleCheck()) {
            std::cout << "OK" << std::endl;
            std::cout << "Congratulations!" << std::endl;
            break;
        } else {
            std::cout << "NOK" << std::endl;
        }
    }
}


int main() {
    std::cout << "=======================" << std::endl;
    std::cout << "WELCOME" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "Enter which game to play:" << std::endl;
    std::cout << "0. Vanilla" << std::endl;
    std::cout << "1. Minus One" << std::endl;
    std::cout << "Enter Choice: ";

    int choice;
    std::cin >> choice;

    // Clear the input buffer before switching to getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 0) {
        playVanillaGame();
    } else if (choice == 1) {
        playKoreanGame();
    } else {
        std::cout << "Invalid choice. Exiting." << std::endl;
    }

    return 0;
}