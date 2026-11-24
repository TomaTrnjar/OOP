// Vjezba 7, zadatak 3: kopirajte klasu IntStack iz vjezbe 6 iznad main i dopunite je.

#include <iostream>
#include <utility>

// ovdje napisite klasu IntStack

int main()
{
    IntStack a;
    a.push(10);
    a.push(20);
    a.push(30);

    IntStack b = a;              // ispis: copy konstruktor
    b = a;                       // ispis: copy assignment
    IntStack c = std::move(a);   // ispis: move konstruktor
    b = std::move(c);            // ispis: move assignment

    std::cout << a.size() << ' ' << c.size() << ' ' << b.size() << ' ' << b.top() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    copy konstruktor
    copy assignment
    move konstruktor
    move assignment
    0 0 3 30
*/
