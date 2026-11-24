// Vjezba 8, zadatak 6: u programu je 6 gresaka. Tri javlja kompajler, a tri se vide tek u ispisu.
// Ispravite ih tako da program ispise ocekivani ispis s dna datoteke.

#include <iostream>
#include <string>
#include <vector>

class Notification {
    std::string recipient;
public:
    Notification(const std::string& r) : recipient(r) {}
    ~Notification() { std::cout << "~Notification\n"; }
    void send() const { std::cout << "obavijest za " << recipient << '\n'; }
};

class Email : public Notification {
    std::string subject;
public:
    Email(const std::string& r, const std::string& s) : subject(s) {}
    ~Email() { std::cout << "~Email\n"; }
    void send() const { std::cout << "email za " << recipient << ": " << subject << '\n'; }
};

class Sms : Notification {
    std::string text;
public:
    Sms(const std::string& r, const std::string& t) : Notification(r), text(t) {}
    void send() const { std::cout << "SMS za " << recipient << ": " << text << '\n'; }
};

void send_twice(Notification n)
{
    n.send();
    n.send();
}

int main()
{
    std::vector<Notification*> inbox;
    inbox.push_back(new Email("Ana", "Kolokvij u petak"));
    inbox.push_back(new Sms("Marko", "Kasnim 10 min"));

    for (Notification* n : inbox)
        n->send();
    std::cout << "---\n";
    send_twice(*inbox[1]);
    std::cout << "---\n";

    for (Notification* n : inbox)
        delete n;
    return 0;
}

/*
Ocekivani ispis:

    email za Ana: Kolokvij u petak
    SMS za Marko: Kasnim 10 min
    ---
    SMS za Marko: Kasnim 10 min
    SMS za Marko: Kasnim 10 min
    ---
    ~Email
    ~Notification
    ~Notification
*/
