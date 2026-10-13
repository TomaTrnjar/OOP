#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	cout << "Unesite a:";
	cin >> a;
	cout << "Unesite b:";
	cin >> b;

	float zbroj = a + b;
	float sredina = zbroj / 2.0;
	bool rez = (a < b);
	cout << "Zbroj: " << zbroj << ", Aritmeticka sredina: " << sredina << " Je li a manje od b: " << rez;

}