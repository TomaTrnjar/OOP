#include <iostream>
using namespace std;

void my_transform(int arr[], int n, int (*f)(int)){
    for(int i=0; i<n; i++){
        arr[i]=f(arr[i]);
    }
}

int twice(int a){
    return 2*a;
}

int main() {
    cout<<"\n";
    int niz1[]={2,4,3,2,0,12};
    int n1=sizeof(niz1)/sizeof(niz1[0]);
    my_transform(niz1,n1,twice);
    for(int i=0;i<n1;i++){
        cout<<niz1[i]<<" ";
    }
    cout<<"\n";


    
    my_transform(niz1, n1, [](int x) {
        if (x%2 == 0)
            return x/2;
        else
            return x*2;
    });

    cout << "Nakon lambde (Parne prepolovi, neparne udvostruči): ";
    for (int i=0; i<n1; i++) {
        cout<<niz1[i]<< " ";
    }
    cout<<endl;


    
    int suma=0;
    int produkt=1;
    auto izracunaj=[&](int x) {
        suma = suma+x;
        produkt = produkt * x;
    };

    for (int i=0; i<n1; i++) {
        izracunaj(niz1[i]);
    }

    cout << "Suma: " << suma << endl;
    cout << "Produkt: " << produkt << endl;




    
    int prag=5;
    int s=0;
    auto zbrojiVeceOdPraga = [prag, &s](int x) {
        if (x > prag) {
            s=s+x;
        }
    };

    for (int i=0; i<n1; i++) {
        zbrojiVeceOdPraga(niz1[i]);
    }

    cout << "Suma clanova vecih od praga "
         << prag << ": " << s << endl;
    return 0;
}
