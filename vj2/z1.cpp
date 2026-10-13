#include <iostream>
#define MAX(a, b) ((a) > (b) ? (a) : (b));
using namespace std;
template<typename T>
inline T  my_max(T a, T b) {
	return ((a) > (b) ? (a) : (b));
}

int main() {


	int a2 = MAX(3, 5);
	int b2 = 2 * MAX(3, 5);
	int c2 = MAX(3, 5) + 1;

	cout << "Popravljeni makro: \n";
	cout << " a = " << a2;
	cout << " b = " << b2;
	cout << " c = " << c2;


	cout << endl;


	int i = 3;

	int rez1 = MAX(++i, 2);
	i = 3;
	int rez2 = my_max(++i, 2);

	cout << "MAX: " << rez1 << ", max2: " << rez2;

	cout << endl;

	cout << "Int: " << my_max(3, 4)<<endl;
	cout << "Double: " << my_max(2.5, 3.4)<<endl;
	cout << "Char: " << my_max('c', 'd')<<endl;
	cout << "String: " << my_max("jabuka", "netanjahu")<<endl;

}