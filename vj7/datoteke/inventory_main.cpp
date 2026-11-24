#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Inventory {
	vector<string> items;
	size_t kapacitet;
public:
	Inventory(size_t kap) {
		kapacitet = kap;
	}
	Inventory& operator+=(const string& item) {
		if (items.size() < kapacitet)
			items.push_back(item);
		return *this;
	}
	string& operator[](size_t i) {
		return items[i];
	}
	const string& operator[](size_t i) const {
		return items[i];
	}
	size_t size() const {
		return items.size();
	}
	explicit operator bool() const {
		return !items.empty();
	}
};

void show(const Inventory& inv)
{
    if (!inv) {
        cout << "prazno\n";
        return;
    }
    for (size_t i = 0; i < inv.size(); ++i)
        cout << i << ": " << inv[i] << '\n';
}

int main()
{
    Inventory bag(3);
    show(bag);

    bag += "mac";
    bag += "stit";
    bag += "kljuc";
    bag += "baklja";
    show(bag);

    bag[0] = "zlatni mac";
    cout << bag[0] << ' ' << bag.size() << '\n';

    if (bag)
        cout << "ima predmeta\n";
    return 0;
}
