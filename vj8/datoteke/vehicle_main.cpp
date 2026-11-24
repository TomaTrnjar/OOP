// Vjezba 8, zadatak 3: napisite klase Vehicle, Car i Truck iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase

int main()
{
    // Car: ime, kilometri, osnovna potrosnja (l/100 km), eco nacin
    Car clio("Clio", 200, 6.0, false);
    Car yaris("Yaris", 200, 6.0, true);
    // Truck: ime, kilometri, osnovna potrosnja (l/100 km), teret u tonama
    Truck iveco("Iveco", 300, 20.0, 5);

    std::vector<Vehicle*> fleet = {&clio, &yaris, &iveco};

    double total = 0;
    for (Vehicle* v : fleet) {
        v->print();
        std::cout << '\n';
        total += v->fuel();
    }
    std::cout << "ukupno: " << total << " l\n";
    return 0;
}

/*
Ocekivani ispis:

    Clio: 12 l
    Yaris: 9.6 l
    Iveco: 90 l (teret 5 t)
    ukupno: 111.6 l
*/
