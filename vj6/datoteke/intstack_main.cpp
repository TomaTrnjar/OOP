#include <string>	
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
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
		kapacitet = other.kapacitet;
		broj = other.broj;
		niz = new int[kapacitet];
		for (int i = 0; i < broj; i++) {
			niz[i] = other.niz[i];
		}
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
	IntStack s;
	for (int i = 1; i <= 5; ++i)
		s.push(i * 10);
	std::cout << s.size() << ' ' << s.capacity() << ' ' << s.top() << '\n';
	IntStack c = s;      // copy konstruktor; isto kao IntStack c(s);
	c.pop();
	c.push(99);
	std::cout << s.top() << ' ' << c.top() << '\n';
	while (!s.empty()) { std::cout << s.top() << ' '; s.pop(); }
	std::cout << '\n';
	return 0;
}

/*
Ocekivani ispis:

	5 8 50
	50 99
	50 40 30 20 10
*/
