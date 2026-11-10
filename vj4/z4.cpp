#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct PasswordInfo {
    int length;
    int digits;
    int uppercase;
    int special;
};

PasswordInfo analyze(const std::string& password){
    PasswordInfo info;
    info.length=password.length();
    info.digits=count_if(password.begin(),password.end(),[](unsigned char c){
        return isdigit(c);
    });
    info.uppercase=count_if(password.begin(),password.end(),[](unsigned char c){
        return isupper(c);
    });
    info.special=count_if(password.begin(),password.end(),[](unsigned char c){
        return ispunct(c);
    });
    return info;
}

bool is_strong(const PasswordInfo& info){
    if(info.length>=10 && info.digits>=1 && info.uppercase>=1 && info.special>=1){
        return true;
    }
    return false;
}

int main() {
    string password;
    cout<<"Unesite lozinku: ";
    cin>>password;

    PasswordInfo info=analyze(password);
    cout<<password<<": duljina "<<info.length<<", znamenke "<<info.digits
        <<", velika "<<info.uppercase<<", posebni "<<info.special<<" -> ";

    if(is_strong(info)){
        cout<<"jaka"<<endl;
    }else{
        cout<<"slaba"<<endl;
    }

    return 0;
}
