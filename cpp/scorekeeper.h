#ifndef SCOREKEEPER_H
#define SCOREKEEPER_H

#include "player.h"
#include <list>
#include <string>
using namespace std;

/*
 * Controller class to keep track of how the game is going
 * with a list of Player instances.
 */
class Scorekeeper {

public:
    Scorekeeper(string);
    ~Scorekeeper();
    Player getPlayer(string name);
    void getPlayers();
    void showScore();
    void addPoints();
    void startGame();
    void announceWinner();

private:
    string title;
    list<Player> PlayerList;
    list<Player>::iterator i;

};

#endif
