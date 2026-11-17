// Vjezba 6, zadatak 4: napisite klasu Board iznad main.

#include <iostream>

// ovdje napisite klasu Board

int main()
{
    Board b(4, 8, '#');
    b.set(1, 2, '@');
    Board copy = b;          // copy konstruktor
    copy.set(2, 5, '*');
    copy.set(0, 0, '!');     // rub se ne mijenja
    b.print();
    copy.print();
    std::cout << copy.rows() << ' ' << copy.cols() << ' '
              << copy.get(2, 5) << '\n';
    return 0;
}

/*
Ocekivani ispis:

    ########
    # @    #
    #      #
    ########
    ########
    # @    #
    #    * #
    ########
    4 8 *
*/
