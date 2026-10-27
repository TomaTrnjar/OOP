#include <iostream>
using namespace std;
inline double add(double a,double b){
    return a+b;
}
inline double subtract(double a, double b){
    return a-b;
}
inline double multiply(double a, double b){
    return a*b;
}
inline double divide(double a,double b){
    return a/b;
}
int main() {
    double(*operacije[4])(double,double)={add,subtract,multiply,divide};

    double a;
    cout<<"Unesite a: ";
    cin>>a;
    
    double b;
    cout<<"Unesite b: ";
    cin>>b;
    
    int izbor;
    while(1){
        cout<<"Odaberite operaciju(0-3):";
        cin>>izbor;
        if(izbor>3 || izbor<0){
            cout<<"Greska: ";
        }else{break;}
    }
    if(izbor==3 && b==0){
        cout<<"Dijelenje s nulom nije dozvoljeno";
        return 0;
    }
    cout<<"Rezultat: "<<operacije[izbor](a,b)<<endl;

    
    return 0;
}
