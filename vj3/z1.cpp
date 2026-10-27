#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
void input_vector(vector<int>& v){
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
void print_vector(const vector<int>& v){
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}
int main() {
	vector<int> v1;
	input_vector(v1);
	cout << endl << "Ispis unesenog vektora:";
	print_vector(v1);

	cout <<endl<<"Obrnuto:";
	for (auto j = v1.rbegin(); j != v1.rend(); j++) {
		cout << *j << " ";
	}
	cout << endl;

	vector <int> v3;
	for (int i = 1; i <= 20; i++) {
		v3.push_back(i);
		cout << "Size: " <<v3.size() << " /  Capacity:"
			<< v3.capacity() <<endl;
	}

	cout << endl << endl << "Novi vektor sa reserve(100)" << endl;

	vector <int> v4;
	v4.reserve(100);
	for (int i = 1; i <= 20; i++) {
		v4.push_back(i);
		cout << "Size: " << v4.size() << " /  Capacity:"
			<< v4.capacity() << endl;
	}
	v4.shrink_to_fit();
	cout <<"Finalni capacity "<<v4.capacity();


	return 0;
}