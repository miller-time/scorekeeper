#include <string>
#include "score.h"
#include "player.h"

Score::Score() {
}

Score::~Score() {
    PlayerList.clear();
}

Player Score::getPlayer(string name) {
    for(i=PlayerList.begin(); i!=PlayerList.end(); i++) {
        if ((*i).getName()==name)
            return (*i);
    }
}

void Score::addPlayer(string name) {
    PlayerList.push_back(Player(name));
}

int Score::getScore(string name) {
    return getPlayer(name).getScore();
}

void Score::addPoints(string who, int points) {
    getPlayer(who).addPoints(points);
}
