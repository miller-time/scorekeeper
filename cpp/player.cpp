#include <cstring.h>
#include "player.h"

Player::Player(char * name) {
    myname = new char[strlen(name)-1];
    strcpy(name, myname);
    myscore = 0;
}

Player::~Player() {
    delete [] myname;
}

int Player::getScore() {
    return myscore;
}

void Player::setScore(int points) {
    myscore += points;
}
