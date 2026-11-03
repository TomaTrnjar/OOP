#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

std::vector<std::string> split_words(const std::string& text){
    size_t pocetak=text.find_first_not_of(' ');
    vector<string> rijeci;

    while(pocetak!=string::npos){
        size_t kraj_rijeci=text.find(' ',pocetak);
        if(kraj_rijeci==string::npos){
            rijeci.push_back(text.substr(pocetak));//zadnja rijec 
            //s.substr(pos, len) je sintaksa;
            break;
        }
        rijeci.push_back(text.substr(pocetak,kraj_rijeci-pocetak)); 
        pocetak = text.find_first_not_of(' ', kraj_rijeci);
    }
    return rijeci;
    
}
int main() {
    string text="banana    Zebra auto Mrkva  kiwi";
    cout<<text<<endl;
    vector<string> rijeci = split_words(text);
    cout<<"Broj rijeci: "<<rijeci.size()<<endl;

    int indexNajduze=0;
    for(int i=1;i<rijeci.size();i++){
        if(rijeci[i].length()>rijeci[indexNajduze].length()){
            indexNajduze=i;
        }
    }
    cout<<"Najduza rijec je "<<rijeci[indexNajduze]<<endl;

    string s="";
    for(int i=rijeci.size()-1;i>=0;i--){
        s.append(rijeci[i]);
        if(i>0){
           s.append("-"); 
        }
    }
    cout<<s<<endl;
    string prva = rijeci[0];
    for (int i=1;i<rijeci.size(); i++) {
        if (rijeci[i]<prva) {
            prva = rijeci[i];
        }
    }
    cout << "Prva po abecedi: " << prva << endl;
    
    return 0;
}
