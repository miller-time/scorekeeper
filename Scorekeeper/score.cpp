#include <iostream>
#include <string>
#include "score.h"
#include "player.h"
#include "playerwidget.h"
using std::cout;

Score::Score()
{

}

Score::~Score()
{
    playerList.clear();
}

Player * Score::getPlayer(string name)
{
    for (i = playerList.begin(); i != playerList.end(); i++) {
        if ((*i).getName() == name)
            return &(*i);
    }
    return NULL;
}

void Score::addPlayer(string name, PlayerWidget * widget)
{
    playerList.push_back(Player(name, widget));
}

int Score::getScore(string name)
{
    return getPlayer(name)->getScore();
}

void Score::addPoints(string who, int points)
{
    getPlayer(who)->addPoints(points);
}

bool Score::nameExists(string name)
{
    for (i = playerList.begin(); i != playerList.end(); i++) {
        if ((*i).getName() == name)
            return true;
    }
    return false;
}

string Score::getTitle()
{
    return title;
}

void Score::setTitle(string t)
{
    title = t;
}

void Score::zeroScores()
{
    for (i = playerList.begin(); i != playerList.end(); i++) {
        ((*i).getWidget()->zeroScore());
        (*i).zeroScore();
    }
}

string Score::getWinner()
{
    int max = 0;
    string winner = "nobody...";
    for (i = playerList.begin(); i != playerList.end(); i++) {
        int score = (*i).getScore();
        if (score > max) {
            max = score;
            winner = (*i).getName();
        }
    }
    return winner;
}
