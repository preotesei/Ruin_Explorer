//
// Created by Zekrom on 23-Jan-21.
//

#include "ActionsMadeByHero.h"


bool NormalAction::MakeAction(int I, int J, Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11]) {

    if(zona[I][J].getStatus() == StatusOfZone::Undiscovered && Utilities::BlockStatus(zona,I,J) == 0){
        zona[I][J].setStatus(StatusOfZone::Discovered);
        if(zona[I][J].getMonstruInZona() != nullptr){
            DiscoveredMonsters.push_back(zona[I][J].getMonstruInZona());
        }
        Utilities::MonsterActions(hero,ExistingMonsters,DiscoveredMonsters,zona,nullptr, false);
        if(hero->getEhp() <= 0){
            std::cout << "Jocul s-a terminat. Eroul este mort.";
            return false;
        }
        Utilities::Printer(hero, DiscoveredMonsters);
    }
    else if(zona[I][J].getStatus() == StatusOfZone::Discovered){
            if(zona[I][J].getTip() == TypeOfZone::Iesire){
                std::cout << "Jocul s-a terminat. Eroul a scapat.";
                return false;
            }
            else if(zona[I][J].getTip() == TypeOfZone::Monstru){
                Monster* Temp = zona[I][J].getMonstruInZona();
               // std::cout << "I: " << I << "   J: " << J << "      " << zona[I][J].getMonstruInZona()->getMt()  << "\n";
                BattleWithSomething *x = BattleVsWithSomethingFactory::CreateBattlefield(zona[I][J].getMonstruInZona()->getMt());
                x->Battle(hero, zona[I][J].getMonstruInZona(), DiscoveredMonsters, ExistingMonsters, zona);


                Utilities::MonsterActions(hero,ExistingMonsters,DiscoveredMonsters,zona,Temp, true);

                for(int f = 0 ; f < DiscoveredMonsters.size() ; ++f){
                    DiscoveredMonsters[f]->ProtectorReset();
                }

                if(hero->getEhp() <= 0){
                    std::cout << "Jocul s-a terminat. Eroul este mort.";
                    return false;
                }
                Utilities::Printer(hero, DiscoveredMonsters);
            }
    }
    return true;
}

NormalAction::NormalAction() {}
