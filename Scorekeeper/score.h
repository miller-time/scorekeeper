#ifndef SCORE_H
#define SCORE_H

#include "player.h"
#include <list>
#include <string>
using namespace std;

class Score {

public:
    Score();
    ~Score();
    void addPlayer(string);
    int getScore(string);
    void addPoints(string, int points);

private:
    Player getPlayer(string);
    string title;
    list<Player> PlayerList;
    list<Player>::iterator i;

};

#endif
