#include <string>
#include "player.h"
using namespace std;

Player::Player(string name) {
    myname = name;
    myscore = 0;
}

Player::~Player() {
}

string Player::getName() {
    return myname;
}

int Player::getScore() {
    return myscore;
}

void Player::addPoints(int points) {
    myscore += points;
}
