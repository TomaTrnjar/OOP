#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
void input_vector(vector<int>& v) {
	int n;
	while (1) {
		cout << "Unesite cijeli broj u vektor (0 za kraj): ";
		cin >> n;
		if (n != 0) {
			v.push_back(n);
		}
		else {
			break;
		}
	}
}
void print_vector(const vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}
int main() {
	vector<int> v1;
	input_vector(v1);
	int k;
	while (1) {
		cout << "Unesite k:";
		cin >> k;
		if (k > 0) {
			break;
		}
	}
	auto negativan = [](int x) {
		return x < 0;
	};


	auto c = std::count_if(v1.begin(), v1.end(), negativan);
	cout << "Negativnih: " << c<<endl;

	auto visekratnik = [k](int x) {
		return x % k == 0;
	};

	auto it = find_if(v1.begin(), v1.end(), visekratnik);

	if (it != v1.end()) {
		cout << "Prvi visekratnik: " << *it << endl;
		cout << "Njegova pozicija: " << it - v1.begin() << endl;
	}
	else {
		cout << "Nema visekratnika broja " << k << endl;
	}

	auto mx = std::max_element(v1.begin(), v1.end());
	auto mn = std::min_element(v1.begin(), v1.end());
	cout<<"Max: "<< *mx << " Min:" << *mn<<endl;
	cout << "Max pozicija " << mx - v1.begin()<<endl;
	cout << "Min pozicija " << mn - v1.begin() << endl;

	v1.erase(std::remove_if(v1.begin(), v1.end(),
		[k](int x) { return x % k == 0; }),
		v1.end());

	cout << "Ispis vektora bez visekratnika: ";
	print_vector(v1);

}