#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

std::vector<std::string> split_words(const std::string& text){
    size_t pocetak=text.find_first_not_of(' ');
    vector<string> rijeci;

    while(pocetak!=string::npos){
        size_t kraj_rijeci=text.find(' ',pocetak);
        if(kraj_rijeci==string::npos){
            rijeci.push_back(text.substr(pocetak));
            break;
        }
        rijeci.push_back(text.substr(pocetak,kraj_rijeci-pocetak));
        pocetak = text.find_first_not_of(' ', kraj_rijeci);
    }
    return rijeci;
}

int main() {
    vector<string> rjecnik{"programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije", "jednostavan", "za", "pocetnike"};
    sort(rjecnik.begin(),rjecnik.end());

    string recenica;
    cout<<"Recenica: ";
    getline(cin,recenica);

    vector<string> rijeci=split_words(recenica);
    vector<string> nepoznate;

    for(int i=0;i<rijeci.size();i++){
        string rijec=rijeci[i];

        rijec.erase(remove_if(rijec.begin(),rijec.end(),[](char c){
            return c==','||c=='.';
        }),rijec.end());

        transform(rijec.begin(),rijec.end(),rijec.begin(),[](unsigned char c){
            return tolower(c);
        });

        if(!binary_search(rjecnik.begin(),rjecnik.end(),rijec)){
            nepoznate.push_back(rijec);
        }
    }

    cout<<"nepoznatih rijeci: "<<nepoznate.size()<<endl;
    for(int i=0;i<nepoznate.size();i++){
        cout<<nepoznate[i]<<endl;
    }

    return 0;
}
