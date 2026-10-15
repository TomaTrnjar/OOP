#include <iostream>
using namespace std;

int& find_max(int arr[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[index]) {
            index = i;
        }
    }
    return arr[index]; 
}

int main() {
    int numbers[] = {4, -7, 12, 0, 9, -3};
    const int len = sizeof(numbers) / sizeof(numbers[0]);
    cout<<"Ispis niza: ";
    for (auto n : numbers) {
        cout << n << ' ';
    }
    cout << "\n";

    
    for (auto &n : numbers) {
        if (n < 0) {
            n = -n;
        }
    }

    cout<<"Zamijenejne negativne vrijednosti: ";
    for (auto n : numbers) {
        cout << n << ' ';
    }
    cout << "\n";
    cout<<"Najveca vrijednost: "<<find_max(numbers, len);
    cout << "\n";
    find_max(numbers, len) = 0;

    cout<<"Zamijenjena najveca vrijednost: ";
    for (auto n : numbers) {
        cout << n << ' ';
    }
    cout << "\n";

    return 0;
}