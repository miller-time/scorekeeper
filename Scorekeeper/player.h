#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "playerwidget.h"
using namespace std;

class Player {

public:
    Player(string, PlayerWidget *);
    ~Player();
    string getName();
    int getScore();
    void addPoints(int);
    PlayerWidget * getWidget();
    void zeroScore();

private:
    string myname;
    int myscore;
    PlayerWidget * mywidget;

};

#endif
