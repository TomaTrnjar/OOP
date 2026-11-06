#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool starts_with(const std::string& s, const std::string& prefix) {
    if (prefix.size() > s.size()){
        return false;
    }else{
        return std::equal(prefix.begin(), prefix.end(), s.begin());
    }

}
 
bool ends_with(const std::string& s, const std::string& suffix) {
    if (suffix.size() > s.size()){
        return false;
    }else{
       return std::equal(suffix.rbegin(), suffix.rend(), s.rbegin());    
    }

}
int main() {
      vector<string> files{"vjezba04.cpp", "slajdovi.pdf", "main.cpp",
                                   "README.md",    "vjezba04.h",  "notes.txt","vjezba03.cpp"};
    
 
auto cpp_count = std::count_if(files.begin(), files.end(),[](const std::string& f) { 
    return ends_with(f, ".cpp"); 
    });
cout << "Broj .cpp datoteka: " << cpp_count << '\n';
files.erase(std::remove_if(files.begin(), files.end(),[](const std::string& f) { return starts_with(f, "vjezba"); }),
                            files.end());

    
for (const auto& f : files){
    cout << f << ' ';
}
    cout << '\n';
    return 0;
}
