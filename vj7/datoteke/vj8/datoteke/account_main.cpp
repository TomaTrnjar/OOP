// Vjezba 8, zadatak 5: napisite klase Account, SavingsAccount i CurrentAccount iznad funkcija.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase

void end_by_value(Account a) { a.month_end(); }
void end_by_ref(Account& a) { a.month_end(); }

int main()
{
    // SavingsAccount: vlasnik, pocetno stanje, kamatna stopa
    SavingsAccount ana("Ana", 1000, 0.01);
    // CurrentAccount: vlasnik, pocetno stanje, dopusteni minus
    CurrentAccount marko("Marko", 100, 500);

    std::vector<Account*> accounts = {&ana, &marko};

    for (Account* a : accounts)
        std::cout << a->withdraw(300) << ' ';
    std::cout << '\n';
    for (Account* a : accounts)
        a->print();

    end_by_value(ana);
    ana.print();
    end_by_ref(ana);
    ana.print();
    return 0;
}

/*
Ocekivani ispis:

    1 1
    Ana: 700
    Marko: -200
    Ana: 700
    Ana: 707
*/
