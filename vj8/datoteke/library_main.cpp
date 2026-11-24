// Vjezba 8, zadatak 4: napisite klase Item, Book, Film, Member i Library iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase

int main()
{
    Book dune("Dina", "Frank Herbert");
    Film dune_film("Dina", 155);
    Book odyssey("2001: Odiseja u svemiru", "Arthur C. Clarke");

    Library lib;
    lib.add(&dune);
    lib.add(&dune_film);
    lib.add(&odyssey);
    lib.print();

    Member ana("Ana");
    lib.lend(1, ana);
    std::cout << lib.lend(5, ana) << '\n';
    lib.print();
    ana.print();

    lib.take_back(ana, 0);
    lib.print();
    ana.print();
    return 0;
}

/*
Ocekivani ispis:

    knjiznica: Dina (Frank Herbert) Dina [155 min] 2001: Odiseja u svemiru (Arthur C. Clarke)
    0
    knjiznica: Dina (Frank Herbert) 2001: Odiseja u svemiru (Arthur C. Clarke)
    Ana: Dina [155 min]
    knjiznica: Dina (Frank Herbert) 2001: Odiseja u svemiru (Arthur C. Clarke) Dina [155 min]
    Ana:
*/
