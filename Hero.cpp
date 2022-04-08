//
// Created by Zekrom on 23-Jan-21.
//

#include "Hero.h"

Hero::Hero(int hp, int mp, int atk) : HP(hp), MP(mp), ATK(atk) { eHP = HP; eMP = MP; }

int Hero::getEhp() const {
    return eHP;
}

int Hero::getAtk() const {
    return ATK;
}

void Hero::setEhp(int eHp) {
    eHP = eHp;
}

int Hero::getEmp() const {
    return eMP;
}
