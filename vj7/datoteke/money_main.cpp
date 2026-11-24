#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class Money {
	int cents;
public:
	Money(int euros = 0, int c = 0) {
		cents = euros * 100 + c;
	}
	int euros() const {
		return cents / 100;
	}
	int centi() const {
		return cents % 100;
	}
	Money& operator+=(const Money& other) {
		cents += other.cents;
		return *this;
	}
	bool operator<(const Money& other) const {
		return cents < other.cents;
	}
};

Money operator+(Money a, const Money& b) {
	a += b;
	return a;
}

std::ostream& operator<<(std::ostream& os, const Money& m) {
	os << m.euros() << '.';
	if (m.centi() < 10)
		os << '0';
	os << m.centi() << " EUR";
	return os;
}

std::istream& operator>>(std::istream& is, Money& m) {
	int e, c;
	char dot;
	if (is >> e >> dot >> c && dot == '.')
		m = Money(e, c);
	else
		is.setstate(std::ios::failbit);
	return is;
}

int main()
{
    Money a(1, 5);
    Money b(0, 95);
    cout << a << " + " << b << " = " << a + b << '\n';

    ifstream in("racun.txt");
    if (!in) {
        cout << "Datoteka racun.txt ne postoji\n";
        return 1;
    }

    string item;
    Money price;
    Money total;
    Money max_price;
    string max_item;
    int count = 0;
    while (in >> item >> price) {
        total += price;
        if (max_price < price) {
            max_price = price;
            max_item = item;
        }
        ++count;
    }
    if (!in.eof())
        cout << "Neispravan zapis: " << item << '\n';

    cout << "Stavki: " << count << '\n';
    cout << "Ukupno: " << total << '\n';
    cout << "Najskuplje: " << max_item << ' ' << max_price << '\n';
    return 0;
}
