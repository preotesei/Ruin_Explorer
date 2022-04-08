//
// Created by Zekrom on 23-Jan-21.
//

#include "Utilities.h"

bool Utilities::BlockStatus(Zona zona[11][11], int I, int J) {
    for(int j = J-1; j < J+2 ; ++j){
        if((zona[I-1][j].getMonstruInZona() != nullptr && zona[I-1][j].getStatus() == StatusOfZone:: Discovered)
        || (zona[I+1][j].getMonstruInZona() != nullptr && zona[I+1][j].getStatus() == StatusOfZone:: Discovered) ){
            return true;
        }
    }
    if((zona[I][J-1].getMonstruInZona() != nullptr && zona[I][J-1].getStatus() == StatusOfZone:: Discovered)
    || (zona[I][J+1].getMonstruInZona() != nullptr && zona[I][J+1].getStatus() == StatusOfZone:: Discovered)){
        return true;
    }
    return false;
}

void Utilities::Printer(Hero *hero, std::vector<Monster *> DiscoveredMonsters) {
    std::cout << hero->getEhp() << " " << hero->getEmp() << " " << hero->getAtk() << "\n";
    for(auto &el : DiscoveredMonsters){
        std::cout << el->getMt() << " " << el->getEhp() << " " << el->getAtk() << "\n";
    }
    std::cout << "\n";
}

void Utilities::RemoveAMonster(int I, int J, std::vector<Monster *> &MonsterVector) {
    for(int k = 0 ; k < MonsterVector.size() ; ++k){
        if(MonsterVector[k]->getI() == I && MonsterVector[k]->getJ() == J){
            MonsterVector.erase(MonsterVector.begin() + k);
        }
    }
}

void Utilities::MonsterActions(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) {
    for(int i = 0 ; i < DiscoveredMonsters.size() ; ++i){
        if(DiscoveredMonsters[i]->getMt() == "SABOTEUR" && DiscoveredMonsters[i]->getNumberOfActions() == 3){
            DiscoveredMonsters[i]->MonsterAction(hero,ExistingMonsters,DiscoveredMonsters,zona,LastUsedMonster,BattleHappened);
            i--;
        }
        else{
            DiscoveredMonsters[i]->MonsterAction(hero,ExistingMonsters,DiscoveredMonsters,zona,LastUsedMonster, BattleHappened);
        }
    }
}

void Utilities::CheckAndRemove(int I, int J, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11]) {
    if(zona[I][J].getMonstruInZona()->getEhp() <= 0){
        zona[I][J].setTip(TypeOfZone::FaraMonstru);
        zona[I][J].setMonstruInZona(nullptr);
        //std::cout << "Test: " << DiscoveredMonsters.size() << "\n";
        Utilities::RemoveAMonster(I, J, DiscoveredMonsters);
        Utilities::RemoveAMonster(I, J, ExistingMonsters);
    }
}




