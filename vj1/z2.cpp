#include <iostream>
#include <string>
using namespace std;

int main() {
	int god;
	string s;
	cout << "Unesite godinu rodenja: ";
	cin >> god;
	cin.ignore();
	cout << "Unesite ime i prezime";
	getline(cin, s);

	int brgod = 2026 - god;
	int br = -1;
	for (auto n : s) {
		br++;
	}
	char c1;
	char c2;
	c1 = s[0];
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			c2 = s[i + 1];
			break;
		}

	}
	cout << "Inicijali su " << c1 << ". " << c2 << ". \n";
	cout << "Broj znakova imena i prezimena: " << br << " \n";
	cout << "Ova osoba ove godine navrsava " << brgod << " godina \n";
}