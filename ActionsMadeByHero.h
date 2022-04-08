//
// Created by Zekrom on 23-Jan-21.
//

#ifndef MEH_ACTIONSMADEBYHERO_H
#define MEH_ACTIONSMADEBYHERO_H
#include <bits/stdc++.h>
#include "Hero.h"
#include "Monster.h"
#include "Zona.h"
#include "Utilities.h"
#include "BattleVsMobs.h"

class ActionsMadeByHero {
public:
    virtual bool MakeAction(int I, int J, Hero *&hero, std::vector <Monster *> &ExistingMonsters, std::vector <Monster *> &DiscoveredMonsters, Zona zona[11][11]) = 0;
};

class NormalAction : public ActionsMadeByHero{
public:
    NormalAction();

    bool MakeAction(int I, int J, Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona zona[11][11]) override;
};

class ActionFactory{
public:
    static ActionsMadeByHero *CreateAction(std::string ActionName){
        if(ActionName == "NORMAL"){
            return new NormalAction();
        }
        return nullptr;
    }
};


#endif //MEH_ACTIONSMADEBYHERO_H
