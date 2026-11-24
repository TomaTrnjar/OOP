#include <iostream>
#include <utility>
using namespace std;

class IntStack {
private:
	int* niz;
	int broj;
	int kapacitet;
public:
	IntStack(int kap = 2) {
		broj = 0;
		kapacitet = kap;
		niz = new int[kapacitet];
	}
	~IntStack() {
		delete[] niz;
	}
	IntStack(const IntStack& other) {
		cout << "copy konstruktor\n";
		kapacitet = other.kapacitet;
		broj = other.broj;
		niz = new int[kapacitet];
		for (int i = 0; i < broj; i++) {
			niz[i] = other.niz[i];
		}
	}
	IntStack& operator=(const IntStack& other) {
		cout << "copy assignment\n";
		if (this == &other) {
			return *this;
		}
		int* noviNiz = new int[other.kapacitet];
		for (int i = 0; i < other.broj; i++) {
			noviNiz[i] = other.niz[i];
		}
		delete[] niz;
		niz = noviNiz;
		broj = other.broj;
		kapacitet = other.kapacitet;
		return *this;
	}
	IntStack(IntStack&& other) {
		cout << "move konstruktor\n";
		niz = other.niz;
		broj = other.broj;
		kapacitet = other.kapacitet;
		other.niz = nullptr;
		other.broj = 0;
		other.kapacitet = 0;
	}
	IntStack& operator=(IntStack&& other) {
		cout << "move assignment\n";
		if (this == &other) {
			return *this;
		}
		delete[] niz;
		niz = other.niz;
		broj = other.broj;
		kapacitet = other.kapacitet;
		other.niz = nullptr;
		other.broj = 0;
		other.kapacitet = 0;
		return *this;
	}
	int size() {
		return broj;
	}
	void push(int x) {
		int noviKap;
		if (broj == kapacitet) {
			noviKap = 2 * kapacitet;
			int *noviNiz = new int[noviKap];
			for (int i = 0; i < kapacitet; i++) {
				noviNiz[i] = niz[i];
			}
			delete[] niz;

			kapacitet = noviKap;
			niz = noviNiz;
		}
		niz[broj] = x;
		broj++;
	}
	void pop() {
		if (broj > 0) {
			broj--;
		}
	}
	int top() {
		return niz[broj - 1];
	}
	bool empty() {
		return broj == 0;
	}
	int capacity() {
		return kapacitet;
	}
};

int main()
{
    IntStack a;
    a.push(10);
    a.push(20);
    a.push(30);

    IntStack b = a;
    b = a;
    IntStack c = move(a);
    b = move(c);

    cout << a.size() << ' ' << c.size() << ' ' << b.size() << ' ' << b.top() << '\n';
    return 0;
}
