// Vjezba 7, zadatak 5: kopirajte Vec2 iz zadatka 1 i napisite klasu InRange.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// ovdje kopirajte Vec2 i operatore iz zadatka 1

// ovdje napisite struct Enemy

// ovdje napisite klasu InRange

int main()
{
    std::vector<Enemy> enemies = {
        {"Goblin", {2, 2}}, {"Troll", {6, 1}}, {"Bat", {3, 5}},
        {"Ghost", {0, 0}}, {"Slime", {7, 7}}
    };
    Vec2 player{3, 3};

    InRange near(player, 2);                                           // konstruktor, 2 je domet
    std::cout << near(enemies[0]) << ' ' << near(enemies[1]) << '\n';  // operator()

    /* ovdje pozovite count_if s funkcijskim objektom */
    int range = 2;

    /* ovdje pozovite count_if s lambdom */
    return 0;
}

/*
Ocekivani ispis:

    1 0
    2
    2
*/
