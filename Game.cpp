//
// Created by Zekrom on 23-Jan-21.
//

#include "Game.h"
#include "Utilities.h"
#include "BattleVsMobs.h"

void Game::addHero(const std::string &heroDescription) {
    std::stringstream ss(heroDescription);
    int HP, MP, ATK;
    ss >> HP >> MP >> ATK;
    hero = new Hero(HP,MP,ATK);
}

void Game::addExit(const std::string &exitDescription) {
    std::stringstream ss(exitDescription);
    int I, J;
    ss >> I >> J;
    zona[I][J].setTip(TypeOfZone::Iesire);
}

void Game::addMonster(const std::string &monsterDescription) {
    Monster *Temp = MonsterFactory::CreateMonster(monsterDescription);
    ExistingMonsters.push_back(Temp);
    zona[Temp->getI()][Temp->getJ()].setMonstruInZona(Temp);
    zona[Temp->getI()][Temp->getJ()].setTip(TypeOfZone::Monstru);
}

void Game::start() {
    for(int i = 0 ; i < 10 ; ++i){
        for(int j = 0 ; j < 10 ; ++j){
            if(zona[i][j].getTip() != TypeOfZone::Monstru && zona[i][j].getTip() != TypeOfZone::Iesire){
                zona[i][j].setTip(TypeOfZone::FaraMonstru);
            }
        }
    }
}

bool Game::doAction(const std::string &actionDescription) {
    std::stringstream ss(actionDescription);
    int I, J;
    std::string Action;
    ss >> I >> J >> Action;
    ActionsMadeByHero *ActionMade = ActionFactory::CreateAction(Action);
    return ActionMade->MakeAction(I,J,hero,ExistingMonsters,DiscoveredMonsters,zona);
}

Game::Game() {

}

void Game::readAbilities(const std::string &filename) {

}
