//
// Created by Zekrom on 23-Jan-21.
//

#ifndef MEH_BATTLEVSMOBS_H
#define MEH_BATTLEVSMOBS_H
#include "Hero.h"
#include "Monster.h"

class BattleWithSomething{
public:
    virtual void Battle(Hero *&hero, Monster *monster, std::vector<Monster *> &DiscoveredMonsters, std::vector<Monster *> &ExistingMonsters, Zona (*zona)[11]) = 0;
};

class BattleVsMobs : public BattleWithSomething {
public:
    void Battle(Hero *&hero, Monster *monster, std::vector<Monster *> &DiscoveredMonsters, std::vector<Monster *> &ExistingMonsters, Zona (*zona)[11]) override;
};

class BattleVsCharlatan : public BattleWithSomething{
public:
    void Battle(Hero *&hero, Monster *monster, std::vector<Monster *> &DiscoveredMonsters, std::vector<Monster *> &ExistingMonsters, Zona (*zona)[11]) override;
};



class BattleVsWithSomethingFactory{
public:
    static BattleWithSomething *CreateBattlefield(std::string MT){
        if(MT == "CHARLATAN"){
            return new BattleVsCharlatan();
        }
        else{
            return new BattleVsMobs();
        }
    }
};

#endif //MEH_BATTLEVSMOBS_H
