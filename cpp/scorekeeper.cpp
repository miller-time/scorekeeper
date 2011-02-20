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

Player Scorekeeper::getPlayer(string name) {
    for(i=PlayerList.begin(); i!=PlayerList.end(); i++) {
        if ((*i).getName()==name)
            return (*i);
    }
}

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

void Scorekeeper::showScore() {
  cout << setiosflags(ios::left);
  cout << title << endl;
  for(i=PlayerList.begin(); i!=PlayerList.end(); i++) {
    cout << setw(10) << (*i).getName() << "\t";
    cout << (*i).getScore() << "\n";
  }
}

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

void Scorekeeper::startGame() {
    getPlayers();
    string cont;
    string opts[3] = {"","addplayer","exit"};
    do {
        showScore();
        addPoints();
        cout << "'addplayer', 'exit', or just Enter to continue.. ";
        getline(cin, cont);
    }while(opts[1].compare(cont) && opts[2].compare(cont));
    if (!opts[1].compare(cont)) 
        startGame();
    else if (!opts[2].compare(cont)) {
        showScore();
        announceWinner();
    }else {
        cout << "Fail!\n";
        exit(EXIT_SUCCESS);
    }
}

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
