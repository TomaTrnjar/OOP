#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int main() {
    int n;
    cout<<"Unesite n: ";
    cin>>n;
    vector<double> temperature(n);
    int duljina=temperature.size();
    for(int i=0; i<duljina;i++){
        cout<<i<<". element:";
        cin>>temperature[i];
    }
    vector<double> promjenaTemp;
    promjenaTemp.reserve(duljina-1);
    for(auto it=temperature.begin()+1; it!=temperature.end();++it){
        promjenaTemp.push_back(*it - *(it-1));
    }
    cout<<endl<<"Promjene temperature: "<<endl;
    for(int i=0; i<duljina-1;i++){
        cout<<promjenaTemp[i]<<" ";
    }

    cout<<endl;
    if(duljina>0){
        if(duljina>7){
            temperature.resize(7);
        }else if(duljina<7){
            double a=temperature.back();
            temperature.resize(7);
            for(int i=duljina;i<7;i++){
                temperature[i]=a;
            }
        
        }
    }else{
        cout<<"Duljina niza nije validna";
        return 1;
    }
    cout<<endl<<"Izvjestaj: "<<endl;
    for(int i=0;i<7;i++){
        cout<<temperature[i]<<" ";
    }

    
    return 0;
}
