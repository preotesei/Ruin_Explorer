#include <iostream>
#include "Game.h"
using namespace std;
int main()
{
    Game * game = new Game();

    string abilities_filename;
    cin >> abilities_filename;

    game->readAbilities(abilities_filename);

    string line;
    getline(cin, line);
    getline(cin, line);
    game->addHero(line);

    getline(cin, line);
    game->addExit(line);

    int n;
    cin >> n;
    getline(cin, line);

    for (int i = 1; i <= n; ++i)
    {
        getline(cin, line);
        game->addMonster(line);
    }

    game->start();

    do{
        getline(cin, line);
    }while (game->doAction(line));


    return 0;
}