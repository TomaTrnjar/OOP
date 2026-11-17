// Vjezba 6, zadatak 5: napisite klase Enemy i Level iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase Enemy i Level

int main()
{
    Level cave(5, 10);
    cave.add(Enemy("Gnome", 1, 1));
    std::cout << cave.add(Enemy("Troll", 8, 3))
              << cave.add(Enemy("Bat", 12, 2)) << '\n';
    cave.step(1, 1);
    cave.print();
    cave.step(1, 1);
    cave.print();
    return 0;
}

/*
Ocekivani ispis:

    10
    Gnome (2, 2) 100
    Troll (9, 4) 100
    Gnome (3, 3) 100
    Troll (9, 4) 100
*/
