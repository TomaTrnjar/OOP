#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;


bool split_email(const std::string& email, std::string& user,
std::string& domain){
    size_t pozicija = email.find('@');
    if(pozicija==string::npos){
        return 0;
    }
    if(email.find('@', pozicija + 1) != string::npos){
        return 0;
    }
    if(pozicija==0 || pozicija==(email.length()-1)){
        return 0;
    }
    user=email.substr(0,pozicija);
    domain=email.substr(pozicija+1);
    
    if(domain.find('.')==string::npos){
        return 0;
    }
    
    
    
    
    return 1;
}

int main() {
    string email;
    cout<<"Uneiste email:";
    getline(cin,email);
    string user,domain;


    if (split_email(email, user, domain)) {
        cout << "Korisnik: " << user << endl;
        cout << "Domena: " << domain << endl;
    }
    else {
        cout << "Neispravna adresa!\n";
    }

    
    return 0;
}
