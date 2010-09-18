#ifndef SCOREKEEPER_H
#define SCOREKEEPER_H

#include "player.h"
#include <list>

class Scorekeeper {

public:
    Scorekeeper();
    ~Scorekeeper();
    void addPlayer();
    Player * getPlayer(char * name);

private:
    list<Player> PlayerList;

};

#endif
