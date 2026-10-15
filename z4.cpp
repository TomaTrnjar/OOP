#include <iostream>
using namespace std;

namespace geo {
    constexpr double PI = 3.14159265358979323846;

    double area(double r) {
        return PI * r * r;
    }
    double area(double a, double b) { 
        return a * b;
    }
    int area(int a) { 
        return a * a;
    }
}

void print_line(char c = '-', int length = 30) {
    for (int i = 0; i < length; i++) {
        cout << c;
    }
    cout << "\n";
}

int main() {
    cout << "area(5)    = " << geo::area(5) << "\n";  //ispisat ce se povrsina kvadrata 
    print_line();
    cout << "area(5.0)  = " << geo::area(5.0) << "\n"; //ispisat ce se povrsina kruga
    print_line();
    cout << "area(2, 3) = " << geo::area(2, 3) << "\n"; //ispisat ce se povrsina
    print_line();
    cout << "area('A')  = " << geo::area('A') << "\n";  //povrsina kvadrata jer se A gleda kao vrijednost cijelog broja zbog ASCII-a
    return 0;
}