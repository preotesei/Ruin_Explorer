//
// Created by Zekrom on 23-Jan-21.
//

#include "Monster.h"

std::string Monster::GetCoords() const {
    std::stringstream ss;
    ss << I << " " << J;
    std::string String1;
    std::string String2;
    ss >> String1;
    ss >> String2;
    return (String1 + " " + String2);
}

Monster::Monster(int i, int j, const std::string &mt, int hp, int atk) : I(i), J(j), MT(mt), HP(hp), ATK(atk) {}

int Monster::getEhp() const {
    return eHP;
}

int Monster::getAtk() const {
    return ATK;
}

void Monster::setEhp(int eHp) {
    eHP = eHp;
}

const std::string &Monster::getMt() const {
    return MT;
}

int Monster::getI() const {
    return I;
}

int Monster::getJ() const {
    return J;
}

int Monster::HowDamagedAmI() {
    return HP - eHP;
}

int Monster::getHp() const {
    return HP;
}

void Monster::setAtk(int atk) {
    ATK = atk;
}

int Monster::getNumberOfActions() const {
    return NumberOfActions;
}

void Monster::setNumberOfActions(int numberOfActions) {
    NumberOfActions = numberOfActions;
}

void Monster::setProtectorAttack(bool protectorAttack) {
    ProtectorAttack = protectorAttack;
}

bool Monster::isProtectorAttack() const {
    return ProtectorAttack;
}

SimpleMonster::SimpleMonster(int i, int j, const std::string &mt, int hp, int atk) : Monster(i, j, mt, hp, atk) { this->setEhp(this->getHp()); }

void SimpleMonster::MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) { }

PriestMonster::PriestMonster(int i, int j, const std::string &mt, int hp, int atk) : Monster(i, j, mt, hp, atk) { this->setEhp(this->getHp()); }

void PriestMonster::MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) {
    int maxim = -1;
    for(int i = 0 ; i < DiscoveredMonsters.size() ; ++i){
        if(this->GetCoords() != DiscoveredMonsters[i]->GetCoords()){
            if(maxim < DiscoveredMonsters[i]->HowDamagedAmI()){
                maxim = DiscoveredMonsters[i]->HowDamagedAmI();
            }
        }
    }
    for(int i = 0 ; i < DiscoveredMonsters.size() ; ++i) {
        if(this->GetCoords() != DiscoveredMonsters[i]->GetCoords()) {
            if(maxim == DiscoveredMonsters[i]->HowDamagedAmI()){
                int Heal = DiscoveredMonsters[i]->getEhp() + this->getAtk();
                if(Heal > DiscoveredMonsters[i]->getHp()){
                    DiscoveredMonsters[i]->setEhp(DiscoveredMonsters[i]->getHp());
                }
                else{
                    DiscoveredMonsters[i]->setEhp(Heal);
                    zona[DiscoveredMonsters[i]->getI()][DiscoveredMonsters[i]->getJ()].setMonstruInZona(DiscoveredMonsters[i]);
                }
                break;
            }

        }
    }
}

ShamanMonster::ShamanMonster(int i, int j, const std::string &mt, int hp, int atk) : Monster(i, j, mt, hp, atk) { this->setEhp(this->getHp()); }

void ShamanMonster::MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) {
    int maxim = INT_MAX;
    for(int i = 0 ; i < DiscoveredMonsters.size() ; ++i) {
        if (this->GetCoords() != DiscoveredMonsters[i]->GetCoords()) {
            if(maxim > DiscoveredMonsters[i]->getAtk()){
                maxim = DiscoveredMonsters[i]->getAtk();
            }
        }
    }
    for(int i = 0 ; i < DiscoveredMonsters.size() ; ++i) {
        if (this->GetCoords() != DiscoveredMonsters[i]->GetCoords()) {
            if(maxim == DiscoveredMonsters[i]->getAtk()){
                DiscoveredMonsters[i]->setAtk(maxim + this->getAtk());
                zona[DiscoveredMonsters[i]->getI()][DiscoveredMonsters[i]->getJ()].setMonstruInZona(DiscoveredMonsters[i]);
                break;
            }
        }
    }
}

SaboteurMonster::SaboteurMonster(int i, int j, const std::string &mt, int hp, int atk) : Monster(i, j, mt, hp, atk) { this->setEhp(this->getHp()); }

void SaboteurMonster::MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) {
    this->setNumberOfActions(this->getNumberOfActions() + 1);
    if(this->getNumberOfActions() == 4){
        hero->setEhp(hero->getEhp()-2*this->getAtk());
        zona[this->getI()][this->getJ()].setTip(TypeOfZone::FaraMonstru);
        zona[this->getI()][this->getJ()].setMonstruInZona(nullptr);
        Utilities::RemoveAMonster(this->getI(),this->getJ(),DiscoveredMonsters);
        Utilities::RemoveAMonster(this->getI(),this->getJ(),ExistingMonsters);
    }
}

CharlatanMonster::CharlatanMonster(int i, int j, const std::string &mt, int hp, int atk) : Monster(i, j, mt, hp, atk) { this->setEhp(this->getHp()); }

void CharlatanMonster::MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) { }

ProtectorMonster::ProtectorMonster(int i, int j, const std::string &mt, int hp, int atk) : Monster(i, j, mt, hp, atk) { this->setEhp(this->getHp()); }

void ProtectorMonster::MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) {
    if(BattleHappened){
        for(int i = 0 ; i < DiscoveredMonsters.size() ; ++i){
            if(DiscoveredMonsters[i]->getMt() == "PROTECTOR" && LastUsedMonster->GetCoords() != DiscoveredMonsters[i]->GetCoords()){
                if(DiscoveredMonsters[i]->isProtectorAttack() == false){
                    hero->setEhp(hero->getEhp() - DiscoveredMonsters[i]->getAtk());
                    DiscoveredMonsters[i]->setProtectorAttack(true);
                }
            }
        }
    }
}

