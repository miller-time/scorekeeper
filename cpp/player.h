#ifndef PLAYER_H
#define PLAYER_H

class Player {

public:
    Player(char *);
    ~Player();
    int getScore();
    void setScore(int);

private:
    char * myname;
    int myscore;

};

#endif
