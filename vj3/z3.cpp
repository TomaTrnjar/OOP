#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

constexpr int DAYS = 7;

double total(const array<double, DAYS>& hours){
    double br=0;

    for(int i=0; i < DAYS; i++){
        br=br+hours[i];
    }
    return br;
}
int best_day(const std::array<double, DAYS>& hours){
    int najvise_index=0;
    for(int i=1; i<DAYS; i++){
        if(hours[i]>hours[najvise_index]){
            najvise_index=i;
        }
    }
    return najvise_index+1;
}

int main() {

    std::array<double, DAYS> tjedan1;
    std::array<double, DAYS> tjedan2;
    cout<<"Unos za prvi tjedan: "<<endl;
    for(int i=0; i<7; i++){
        cout<<i+1<<". dan: ";
        cin>>tjedan1[i];
    }
    cout<<"Total 1. tjedan: "<<total(tjedan1)<<endl;
    cout<<best_day(tjedan1)<<". dan je dan sa najvise sati!"<<endl;
    
    tjedan2.fill(1.5);
    cout<<"2. tjedan:"<<endl;
    for(int i=0; i<7;i++){
        cout<<tjedan2[i]<<" ";
    }

    cout<<endl<<"Usporedba tjedana s operatorom '==': "<<(tjedan1==tjedan2);
    cout<<endl<<"Usporedba tjedana s operatorom '<': "<<(tjedan1<tjedan2);

    tjedan1.swap(tjedan2);
    cout<<endl;
    cout<<"Total 1. tjedna: "<<total(tjedan1)<<"; Total 2. tjedna: "<<total(tjedan2);


    
    return 0;
}
