// Vjezba 5, zadatak 5: napisite klasu Ticket iznad main.

#include <iostream>
#include <string>
using namespace std;
class Ticket{
private:
    string naziv;
    int id;
    static int br;
public:
    Ticket(string naziv){
        br++;
        this->naziv=naziv;
        id=br;
    }
    static int issued(){
        return br;
    }
    int get_id(){
        return id;
    }
};
    int Ticket::br = 0;
int main()
{

    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    1 2 3
    3
*/
