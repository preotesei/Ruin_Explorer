//
// Created by Zekrom on 23-Jan-21.
//

#include "BattleVsMobs.h"

void BattleVsMobs::Battle(Hero *&hero, Monster *monster, std::vector<Monster *> &DiscoveredMonsters, std::vector<Monster *> &ExistingMonsters, Zona (*zona)[11]) {
    hero->setEhp(hero->getEhp() - monster->getAtk());
    monster->setEhp(monster->getEhp() - hero->getAtk());
    Utilities::CheckAndRemove(monster->getI(),monster->getJ(),ExistingMonsters,DiscoveredMonsters,zona);
}

void BattleVsCharlatan::Battle(Hero *&hero, Monster *monster, std::vector<Monster *> &DiscoveredMonsters, std::vector<Monster *> &ExistingMonsters, Zona (*zona)[11]) {
    if(DiscoveredMonsters.size() > 1){
        int maxim = -1;
        for(int i = 0 ; i < DiscoveredMonsters.size() ; ++i){
            if (monster->GetCoords() != DiscoveredMonsters[i]->GetCoords()) {
                if(maxim < DiscoveredMonsters[i]->getEhp()){
                    maxim = DiscoveredMonsters[i]->getEhp();
                }
            }
        }
        for(int i = 0 ; i < DiscoveredMonsters.size() ; ++i){
            if (monster->GetCoords() != DiscoveredMonsters[i]->GetCoords()) {
                if(maxim == DiscoveredMonsters[i]->getEhp()){
                    hero->setEhp(hero->getEhp() - monster->getAtk());
                    DiscoveredMonsters[i]->setEhp(DiscoveredMonsters[i]->getEhp() - 2*hero->getAtk());
                    Utilities::CheckAndRemove(DiscoveredMonsters[i]->getI(),DiscoveredMonsters[i]->getJ(),ExistingMonsters,DiscoveredMonsters,zona);
                    break;
                }
            }
        }
    }
    else{
        BattleVsMobs *x = new BattleVsMobs();
        x->Battle(hero, monster, DiscoveredMonsters, ExistingMonsters, zona);
    }
}
