//
// Created by Zekrom on 23-Jan-21.
//

#ifndef MEH_UTILITIES_H
#define MEH_UTILITIES_H
#include "Zona.h"
#include "Hero.h"
#include "Monster.h"

class Zona;
class Monster;

class Utilities {
public:
    static bool BlockStatus(Zona zona[11][11], int I, int J);
    static void Printer(Hero *hero, std::vector <Monster *> DiscoveredMonsters);
    static void RemoveAMonster(int I, int J, std::vector <Monster *> &MonsterVector);
    static void MonsterActions(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened);
    static void CheckAndRemove(int I, int J, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11]);
};


/*
 *                 if(zona[I][J].getMonstruInZona()->getEhp() <= 0){
                    zona[I][J].setTip(TypeOfZone::FaraMonstru);
                    zona[I][J].setMonstruInZona(nullptr);
                    //std::cout << "Test: " << DiscoveredMonsters.size() << "\n";
                    Utilities::RemoveAMonster(I, J, DiscoveredMonsters);
                    Utilities::RemoveAMonster(I, J, ExistingMonsters);
                }
 */

#endif //MEH_UTILITIES_H
