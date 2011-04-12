#include <iostream>
#include <string>
#include "player.h"
using namespace std;

Player::Player(string name, PlayerWidget * widget) {
    myname = name;
    myscore = 0;
    mywidget = widget;
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

PlayerWidget * Player::getWidget()
{
    return mywidget;
}

void Player::zeroScore()
{
    myscore = 0;
}
