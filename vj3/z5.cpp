#include <iostream>
#include <string>
#include <array>
using namespace std;

string with_separators(std::string & digits){
    if(digits[0]!='-'){
        for(int i=digits.length()-3; i>0;i-=3){
            digits.insert(i,".");
        }
    }else{
        for(int i=digits.length()-3; i>1;i-=3){
            digits.insert(i,".");
        }    
    }
    return digits;

}
string without_separators(std::string text){
    size_t pozicija;
    
    if((pozicija=text.find('.'))!=string::npos){
       text.erase(pozicija,1); 
    }
    return text;
}

int main() {
    string digits;
    cout<<"Unesite broj: ";
    cin>>digits;
    cout<<"Broj: "<<digits<<endl;
    cout<<"Sa tockama: "<<with_separators(digits)<<endl;
    cout<<"Bez tocaka: "<<without_separators(digits);
    
    
    return 0;
}
