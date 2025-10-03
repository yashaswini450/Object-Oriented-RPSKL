#ifndef RPSKL_H
#define RPSKL_H

// Abstract base class for all tools
class Tool{
protected: 
  int strength; // The base strength of the tool
  char type; // The type identifier ('r', 'p', 's', 'k', 'l') 

private:
  bool winner;// Flag to indicate if this tool won its last fight 

public:
  // Constructor initializes strength and type.
  Tool(int s , char t);

  // Virtual destructor to ensure proper cleanup of derived classes
  virtual ~Tool(){}

  // Pure virtual fight method makes Tool an abstract class and compares this tool against an opponent's tool.
  virtual bool fight(Tool& opponent)=0;

  //Getters and Setters
  int getStrength() const;
  char getType() const;
  bool isWinner() const;
  void setWinner(bool w);

};

// Represents the Rock tool
class Rock: public Tool{
public:

 // Constructor initializes Rock with a given strength 
  Rock(int s);

  // Implements the fighting logic for Rock 
  virtual bool fight(Tool& opponent) override;
};

// Represents the Paper tool
class Paper: public Tool{
    public:

     // Constructor initializes Paper with a given strength
      Paper(int s);

      // Implements the fighting logic for Paper 
      virtual bool fight(Tool& opponent) override;
};

// Represents the Scissors tool
class Scissors: public Tool{
    public:

     // Constructor initializes Scissors with a given strength
      Scissors(int s);

      // Implements the fighting logic for Scissors
      virtual bool fight(Tool& opponent) override;
};

// Represents the Spock tool
class Spock: public Tool{
    public:

     // Constructor initializes Spock with a given strength
      Spock(int s);

      // Implements the fighting logic for Spock
      virtual bool fight(Tool& opponent) override;
};

// Represents the Lizard tool
class Lizard: public Tool{
    public:
     // Constructor initializes Lizard with a given strength 
      Lizard(int s);

      // Implements the fighting logic for Lizard
      virtual bool fight(Tool& opponent) override;
};
#endif