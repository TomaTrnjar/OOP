#pragma once      // header se ukljucuje samo jednom, iako ga ukljucuje vise datoteka

#include <vector>
#include "Enemy.h"
#include "Weapon.h"

class Level {
    // data memberi

public:
    // konstruktor
    int enemy_count() const;
    int weapon_count() const;
};
