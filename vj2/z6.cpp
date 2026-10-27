
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string ime;
    string JMBAG;
    int godina;
    int ECTS;
    double prosjek;
};

void ispisi(Student& s) {
    cout << s.ime << " | " << s.JMBAG
         << " | Godina: " << s.godina
         << " | ECTS: " << s.ECTS
         << " | Prosjek: " << s.prosjek << endl;
}

void povecaj_godinu(Student& s) {
    s.godina++;
}

void filter_students(
    Student s[], int n,
    void (*action)(Student&),
    bool (*cond)(const Student&)
) {
    for (int i = 0; i < n; i++) {
        if (cond(s[i])) {
            action(s[i]);
        }
    }
}

int main() {
    Student studenti[] = {
        {"Stipe", "001", 1, 30, 4.2},
        {"Trpimir", "002", 1, 0, 3.2},
        {"Benjamin", "003", 2, 50, 3.8},
        {"Abdul", "004", 3, 45, 4.5},
        {"Ana", "005", 1, 15, 3.6}
    };

    int n = sizeof(studenti) / sizeof(studenti[0]);

    cout << "Studenti 1. godine s barem jednim "
            "polozenim ispitom:\n";

    filter_students(studenti, n, ispisi,
        [](const Student& s) {
            return s.godina == 1 && s.ECTS > 0;
        }
    );

    cout << "\nStudenti s prosjekom vecim od 3.5:\n";

    filter_students(studenti, n, ispisi,
        [](const Student& s) {
            return s.prosjek > 3.5;
        }
    );

    filter_students(studenti, n, povecaj_godinu,
        [](const Student& s) {
            return s.ECTS >= 45;
        }
    );

    cout << "\nStudenti nakon povecanja godine studija:\n";

    for (int i = 0; i < n; i++) {
        ispisi(studenti[i]);
    }

    return 0;
}
