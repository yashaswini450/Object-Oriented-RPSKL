#ifndef PLAYER_H
#define PLAYER_H

#include<string>
#include "rpskl.h"
using namespace std;


class Player{
protected:
  string name;
  int id;
  Tool* tool;
  bool winner;

  static int nextId;

public:
 
 // Constructor:sets name and assigns a unique ID
  Player(const string& n);

  // Dynamically creates a tool for the player to us
  virtual Tool& choose(char type, int strength);

  // Virtual destructor to handle potential derived classes and memory leaks
  virtual ~Player();

  //Getters and Setters
  int getId() const;
  const string& getName() const;
  void setName(const string& n);
  bool isWinner() const;
  void setWinner(bool w);
  Tool& getLastUsedTool() const;

  
};
#endif