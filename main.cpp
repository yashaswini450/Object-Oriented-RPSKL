#include<iostream>
#include "game.h"
#include <limits>
#include "KoreanGame.h"
#include "KoreanPlayer.h"
#include "player.h"
#include "rpskl.h"
#include <string>

void playVanillaGame(){
    string gameName, p1_name, p2_name;

    cout<<"Enter game: ";
    cin>> gameName;
    Game game(gameName);

    cout<<"Register Player1:";
    cin>>p1_name;
    Player p1(p1_name);

    cout<<"Register Player2:";
    cin>>p2_name;
    Player p2(p2_name);

    game.registerPlayer(p1);
    game.registerPlayer(p2);

    cout<< "... verifying registration... ";
    if(game.verifyRegistration()){
        cout<< "OK"<< endl;
    }else{
        cout<< "NOK" <<endl;
        cout<< "Registration failed. Players might have the same ID or are not unique."<<endl;
        return;
    }

    while(true){
        char type1, type2;
        int strength1, strength2;

        cout<< "Play with:";
        cin>> type1 >> strength1 >>type2>> strength2;

        game.playGame(type1,strength1, type2, strength2);
        // cout<< game.getWinnerName()<< " own!"<<endl;


        if (game.winner != nullptr) {
            std::cout <<"... "<< game.getWinnerName() << " own!" << std::endl;
        } else {
            std::cout << "... its a tie!" << std::endl;
        }

        cout <<"... double checking... ";
        if(game.doubleCheck()){
            cout<<"OK"<<endl;
            cout<< "Congratulations!"<<endl;
            break;
        }else{
            cout<< "NOK"<<endl;
        }

    }
}

void playKoreanGame(){
    string gameName, p1_name, p2_name;

    cout<<"Enter game: ";
    cin>>gameName;
    KoreanGame game(gameName);

    cout<<"Register Player1:";
    cin>>p1_name;
    KoreanPlayer p1(p1_name);

    cout<<"Register Player2:";
    cin>>p2_name;
    KoreanPlayer p2(p2_name);

    game.registerPlayer(p1);
    game.registerPlayer(p2);

    cout<< "... verifying registration... ";
    if(game.verifyRegistration()){
        cout<< "OK"<< endl;
    }else{
        cout<< "NOK" <<endl;
        return;
    }

    while(true){
        char t1_1, t1_2, t2_1, t2_2, h1, h2;
        int s1_1, s1_2, s2_1, s2_2;

        cout<< "Play with:";
        cin>> t1_1>> s1_1>> t1_2>>s1_2>> t2_1>> s2_1>>t2_2>>s2_2>> h1>> h2;
        game.playGame(t1_1,s1_1, t1_2, s1_2, t2_1, s2_1, t2_2,s2_2, h1, h2);
        
       // cout<< game.getWinnerName()<< " own!"<<endl;
        


        if (game.winner != nullptr) {
            std::cout << "... "<< game.getWinnerName() << " own!" << std::endl;
        } else {
            std::cout << "... its a tie!" << std::endl;
        }       


        cout <<"... double checking... ";
        if(game.doubleCheck()){
            cout<<"OK"<<endl;
            cout<< "Congratulations!"<<endl; 
            break;
        }else{
            cout<< "NOK"<<endl;
        }

    }
}

int main(){
    cout << "========================================" << endl;
    cout << "        WELCOME " << endl;
    cout << "========================================" << endl;
    cout << "Enter which game to play:" << endl;
    cout << "0. Vanilla" << endl;
    cout << "1. Minus One" << endl;
    cout << "Enter choice:";
    
    int choice;
    cin>> choice;


    if (choice == 0) {
        playVanillaGame();
    } else if (choice == 1) {
        playKoreanGame();
    } else {
        cout << "Invalid choice. Exiting." <<endl;
    }

    return 0;

}