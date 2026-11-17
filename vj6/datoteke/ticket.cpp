
#include <iostream>
#include <string>
using namespace std;

class Ticket {
private:
    string naziv;
    int id;
    static int br;

public:
    Ticket(string naziv) {
        br++;
        this->naziv = naziv;
        id = br;
    }

    Ticket(const Ticket& t) = delete;

    static int issued() {
        return br;
    }

    int get_id() const {
        return id;
    }
};

int Ticket::br = 0;

void print(const Ticket& t) {
    cout << t.get_id() << '\n';
}

int main()
{
    cout << Ticket::issued() << '\n';

    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");

    cout << t1.get_id() << ' '
         << t2.get_id() << ' '
         << t3.get_id() << '\n';

    cout << Ticket::issued() << '\n';

    print(t1);

    // Ticket t4 = t1; // GRESKA: kopiranje je zabranjeno

    return 0;
}

