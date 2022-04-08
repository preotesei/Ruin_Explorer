//
// Created by Zekrom on 23-Jan-21.
//

#ifndef MEH_HERO_H
#define MEH_HERO_H


class Hero {
private:
    int HP;
    int eHP;
    int MP;
    int eMP;
    int ATK;
    bool alive = true;
public:
    Hero(int hp, int mp, int atk);

    int getEhp() const;

    int getAtk() const;

    void setEhp(int eHp);

    int getEmp() const;
};


#endif //MEH_HERO_H
