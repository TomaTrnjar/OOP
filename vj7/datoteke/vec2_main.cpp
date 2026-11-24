// Vjezba 7, zadatak 1: napisite strukturu Vec2 i operatore iznad main.

#include <iostream>

// ovdje napisite Vec2 i operatore

int main()
{
    Vec2 player{2, 3};
    Vec2 right{1, 0};
    Vec2 down{0, 1};

    player += right;
    std::cout << player << '\n';
    player += 2 * down;
    std::cout << player << '\n';
    Vec2 target = player + right * 3 - down;
    std::cout << target << '\n';

    Vec2 enemy{6, 4};
    std::cout << (target == enemy) << ' ' << (player != enemy) << '\n';
    std::cout << player << " -> " << target << '\n';
    return 0;
}

/*
Ocekivani ispis:

    (3, 3)
    (3, 5)
    (6, 4)
    1 1
    (3, 5) -> (6, 4)
*/
