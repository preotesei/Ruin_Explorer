//
// Created by Zekrom on 23-Jan-21.
//

#ifndef MEH_MONSTER_H
#define MEH_MONSTER_H
#include <bits/stdc++.h>
#include "Hero.h"
#include "Utilities.h"
class Zona;

class Monster{
private:
    int I;
    int J;
    std::string MT;
    int HP;
    int eHP;
    int ATK;
    int NumberOfActions = 0;
    bool ProtectorAttack = false;
public:
    Monster(int i, int j, const std::string &mt, int hp, int atk);

    void setProtectorAttack(bool protectorAttack);

    std::string GetCoords() const;

    int getEhp() const;

    int getAtk() const;

    bool isProtectorAttack() const;

    void ProtectorReset(){
        ProtectorAttack = false;
    }

    void setEhp(int eHp);

    int getHp() const;

    void setAtk(int atk);

    const std::string &getMt() const;

    int getI() const;

    int getJ() const;

    int HowDamagedAmI();

    int getNumberOfActions() const;

    void setNumberOfActions(int numberOfActions);

    virtual void MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) = 0;
};

class SimpleMonster : public Monster{
public:
    SimpleMonster(int i, int j, const std::string &mt, int hp, int atk);

    void MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster,bool BattleHappened) override;

};

class PriestMonster : public Monster{
public:
    PriestMonster(int i, int j, const std::string &mt, int hp, int atk);

    void MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) override;
};

class ShamanMonster : public Monster{
public:
    ShamanMonster(int i, int j, const std::string &mt, int hp, int atk);

    void MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) override;
};

class SaboteurMonster : public Monster{
public:
    SaboteurMonster(int i, int j, const std::string &mt, int hp, int atk);

    void MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) override;
};

class CharlatanMonster : public Monster{
public:
    CharlatanMonster(int i, int j, const std::string &mt, int hp, int atk);

    void MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) override;
};

class ProtectorMonster : public Monster{
public:
    ProtectorMonster(int i, int j, const std::string &mt, int hp, int atk);

    void MonsterAction(Hero *&hero, std::vector<Monster *> &ExistingMonsters, std::vector<Monster *> &DiscoveredMonsters, Zona (*zona)[11], Monster* LastUsedMonster, bool BattleHappened) override;

};

class MonsterFactory{
public:
    static Monster *CreateMonster(const std::string &monsterDescription){
        std::stringstream ss(monsterDescription);
        int I, J, HP, ATK;
        std::string MT;
        ss >> I >> J >> MT >> HP >> ATK;

        if(MT == "SIMPLE"){
            return new SimpleMonster(I,J,MT,HP,ATK);
        }
        if(MT == "PRIEST"){
            return new PriestMonster(I,J,MT,HP,ATK);
        }
        if(MT == "SHAMAN"){
            return new ShamanMonster(I,J,MT,HP,ATK);
        }
        if(MT == "SABOTEUR"){
            return new SaboteurMonster(I,J,MT,HP,ATK);
        }
        if(MT == "CHARLATAN"){
            return new CharlatanMonster(I,J,MT,HP,ATK);
        }
        if(MT == "PROTECTOR"){
            return new ProtectorMonster(I,J,MT,HP,ATK);
        }

        return nullptr;
    }
};


#endif //MEH_MONSTER_H
