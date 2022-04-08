//
// Created by Zekrom on 22-Jan-21.
//

#ifndef COLOCVIUPOO_GAME_H
#define COLOCVIUPOO_GAME_H
#include <bits/stdc++.h>
#include "Hero.h"
#include "Monster.h"
#include "Zona.h"
#include "ActionsMadeByHero.h"

class Game {
    Hero *hero;
    std::vector <Monster *> ExistingMonsters;
    std::vector <Monster *> DiscoveredMonsters;
    Zona zona[11][11];
public:
    Game();

    void readAbilities(std::string const& filename);
    void addHero(std::string const& heroDescription);
    void addExit(std::string const& exitDescription);
    void addMonster(std::string const& monsterDescription);
    void start();
    bool doAction(std::string const& actionDescription);
};

#endif //COLOCVIUPOO_GAME_H
