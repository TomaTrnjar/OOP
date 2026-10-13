#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (a < 0) {
		a = -a;
	}
	if (b < 0) {
		b = -b;
	}
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

struct Fraction {
	int numerator;
	int denominator;

	void reduce() {
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
		int g = gcd(numerator, denominator);
		numerator /= g;
		denominator /= g;
	}

	double value() {
		return (double)numerator / denominator;
	}

	void print() {
		cout << numerator << "/" << denominator;
	}
};

Fraction sum(const Fraction& a, const Fraction& b) {
	Fraction r;
	r.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	r.denominator = a.denominator * b.denominator;
	r.reduce();
	return r;
}

int main() {
	Fraction a = {6, 8};
	a.reduce();
	cout << "Skraceni razlomak: ";
	a.print();
	cout << "\n";
	cout << "Decimalna vrijednost: " << a.value() << "\n";

	Fraction b = {1, 3};
	Fraction c = {1, 2};
	Fraction s = sum(b, c);
	cout << "Zbroj: ";
	s.print();
	cout << "\n";
}