// Vjezba 5, zadatak 6: napisite klasu Coin iznad funkcije bonus.

#include <iostream>
using namespace std;

class Coin{
private:
    int vrijednost;
    static int brojac;
public:
    Coin(int v){
        vrijednost=v;
        brojac++;
    }
    ~Coin(){
        brojac--;
    }
    static int remaining(){
        return brojac;
    }
};

void bonus()               // bonus runda: tri novcica
{
    Coin c1(5);
    Coin c2(5);
    Coin c3(10);
    std::cout << Coin::remaining() << '\n';
}
int Coin::brojac=0;
int main()
{
    std::cout << Coin::remaining() << '\n';
    Coin gold(50);
    {
        Coin a(1);
        Coin b(1);
        std::cout << Coin::remaining() << '\n';
    }
    std::cout << Coin::remaining() << '\n';
    bonus();
    std::cout << Coin::remaining() << '\n';
    return 0;
}

/*
Ocekivani ispis:

    0
    3
    1
    4
    1
*/
