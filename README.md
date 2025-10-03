Overview

This project implements the Object-Oriented version of Rock–Paper–Scissors-Spock-Lizard (RPSKL) along with a Korean variant, developed in C++.
It demonstrates key OOP concepts such as classes, inheritance, polymorphism, and abstraction through a modular design with separate header and implementation files.

Features

Supports Rock–Paper–Scissors rules.

Player hierarchy with base and derived classes (Player, KoreanPlayer).

Game hierarchy (Game, KoreanGame) to showcase inheritance.

Polymorphism for handling different player/game types.

Modular structure with .h and .cpp files.

Makefile for easy compilation.

📂 Project Structure
.
├── rpskl.h
├── rpskl.cpp
├── player.h
├── player.cpp
├── KoreanPlayer.h
├── KoreanPlayer.cpp
├── game.h
├── game.cpp
├── KoreanGame.h
├── KoreanGame.cpp
├── main.cpp
└── Makefile


player.h / player.cpp → Base Player class (with derived KoreanPlayer).

game.h / game.cpp → Base Game class (with derived KoreanGame).

rpskl.h / rpskl.cpp → Core logic for RPSK moves and rules.

main.cpp → Entry point to run the game.

Makefile → Automates compilation and builds the executable.

⚙️ Build & Run

Clone this repository:

git clone https://github.com/your-username/Object-Oriented-RPSKL.git
cd Object-Oriented-RPSKL


Compile using the Makefile:

make


This generates an executable (e.g., rpskl).

Run the game:

./rpskl


To clean build files:

make clean
