//
// Created by Zekrom on 23-Jan-21.
//

#include "Zona.h"

void Zona::setTip(TypeOfZone tip) {
    Tip = tip;
}

TypeOfZone Zona::getTip() const {
    return Tip;
}

void Zona::setStatus(StatusOfZone status) {
    Status = status;
}

StatusOfZone Zona::getStatus() const {
    return Status;
}

void Zona::setMonstruInZona(Monster *monstruInZona) {
    Monstru_in_zona = monstruInZona;
}

Monster *Zona::getMonstruInZona() const {
    return Monstru_in_zona;
}

