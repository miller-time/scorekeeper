#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

/* 
 * Container class to hold a name and a score
 */
class Player {

public:
    Player(string);
    ~Player();
    string getName();
    int getScore();
    void addPoints(int);

private:
    string myname;
    int myscore;

};

#endif
