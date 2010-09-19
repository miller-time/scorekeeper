#include <iostream>
#include "scorekeeper.h"
using namespace std;

int main() {
    string game_title;
    cout << "Enter name of game: ";
    getline (cin, game_title);
    Scorekeeper test = Scorekeeper(game_title);
    test.startGame();
    return 0;
}
