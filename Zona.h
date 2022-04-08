//
// Created by Zekrom on 23-Jan-21.
//

#ifndef MEH_ZONA_H
#define MEH_ZONA_H
#include "Monster.h"

class Monster;

enum class TypeOfZone {
    Monstru, FaraMonstru, Iesire, OutOfReach
};

enum class StatusOfZone {
    Undiscovered, Discovered
};

class Zona {
private:
    TypeOfZone Tip = TypeOfZone::OutOfReach;
    StatusOfZone Status = StatusOfZone::Undiscovered;
    Monster *Monstru_in_zona = nullptr;
public:
    void setTip(TypeOfZone tip);
    void setStatus(StatusOfZone status);
    void setMonstruInZona(Monster *monstruInZona);

    TypeOfZone getTip() const;
    StatusOfZone getStatus() const;

    Monster *getMonstruInZona() const;


};


#endif //MEH_ZONA_H
