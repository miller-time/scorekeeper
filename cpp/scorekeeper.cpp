#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "scorekeeper.h"
#include "player.h"
using namespace std;

Scorekeeper::Scorekeeper(string t) {
    title = t;
}

Scorekeeper::~Scorekeeper() {
    PlayerList.clear();
}

// find a player by their name
Player Scorekeeper::getPlayer(string name) {
    for(i=PlayerList.begin(); i!=PlayerList.end(); i++) {
        if ((*i).getName()==name)
            return (*i);
    }
}

// initialize the players list by asking for a series of names
void Scorekeeper::getPlayers() {
    string name;
    do {
        cout << "Enter player name: ";
        getline(cin, name);
        if (name.compare("")) {
            PlayerList.push_back(Player(name));
        }
    }while(name.compare(""));
}

// display all players names and scores
void Scorekeeper::showScore() {
  cout << setiosflags(ios::left);
  cout << title << endl;
  for(i=PlayerList.begin(); i!=PlayerList.end(); i++) {
    cout << setw(10) << (*i).getName() << "\t";
    cout << (*i).getScore() << "\n";
  }
}

// ask for an update for each player's points
void Scorekeeper::addPoints() {
    string score;
    int points;
    for(i=PlayerList.begin(); i!=PlayerList.end(); i++) {
        cout << "Update score for " << (*i).getName() << ": ";
        getline (cin, score);
        stringstream ss(score);
        if ((ss >> points).fail())
            points = 0;
        (*i).addPoints(points);
    }
}

// control loop
void Scorekeeper::startGame() {
    // initialize the player list
    getPlayers();
    string cont;
    // these are string literals that will be used for figuring out what to do next
    string opts[3] = {"","addplayer","exit"};
    // this is the main loop, and just continues when anything other than "addplayer" or "exit" are typed
    do {
        showScore();
        addPoints();
        cout << "'addplayer', 'exit', or just Enter to continue.. ";
        getline(cin, cont);
    }while(opts[1].compare(cont) && opts[2].compare(cont));
    // if "addplayer" is typed, this function is recursively called
    if (!opts[1].compare(cont)) 
        startGame();
    // if "exit" is typed, the game is wrapped up, and the program exits
    else if (!opts[2].compare(cont)) {
        showScore();
        announceWinner();
    }
    // harsh error if a command is typed incorrectly...
    else {
        cout << "Fail!\n";
        exit(EXIT_SUCCESS);
    }
}

// as the name suggests... 
void Scorekeeper::announceWinner() {
    int highest = 0;
    string winner;
    for(i=PlayerList.begin(); i!=PlayerList.end(); i++) {
        int s = (*i).getScore();
        if (s >= highest) {
            highest = s;
            winner = (*i).getName();
        }
    }
    cout << "THE WINNER IS " << winner << "!!!\n";
}
