#ifndef SCORE_H
#define SCORE_H

#include "player.h"
#include "playerwidget.h"
#include <list>
#include <string>
using namespace std;

class Score {

public:
    Score();
    ~Score();
    void addPlayer(string, PlayerWidget *);
    int getScore(string);
    void addPoints(string, int);
    bool nameExists(string);
    string getTitle();
    void setTitle(string);
    void zeroScores();
    string getWinner();

private:
    Player * getPlayer(string);
    string title;
    list<Player> playerList;
    list<Player>::iterator i;

};

#endif
