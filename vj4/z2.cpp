#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct Song{
    string title;
    string artist;
    int year;
    int plays;

};

void print_song(const Song& s){
    cout<<endl;
    cout<<"Title:"<<s.title<<endl;
    cout<<"Artist: "<<s.artist<<endl;
    cout<<"Year: "<<s.year<<endl;
    cout<<"Plays:"<<s.plays<<endl;
}

int main(){
    Song s1;
    s1.title="Cesarica";
    s1.artist="Oliver Dragojevic";
    s1.year=2005;
    s1.plays=3000;

    Song s2;
    s2.title="Prati me kroz snove";
    s2.artist="Oliver Dragojevic";
    s2.year=2002;
    s2.plays=2000;

    Song s3;
    s3.title="Pjesma123";
    s3.artist="The band";
    s3.year=2022;
    s3.plays=200;

    vector<Song> songs={s1,s2,s3};

    //1)
    std::sort(songs.begin(), songs.end(), [](const Song a, const Song b){
        if(a.year==b.year){
            return a.title < b.title;
        }
        return a.year < b.year;
    });

    for(int i=0; i<songs.size(); i++){
        print_song(songs[i]);
    }
    cout<<endl;
    //2)
    string ime;
    cout<<"Unesite ime izvodaca: ";
    getline(cin,ime);
    int brojac=0;
    int velicina=songs.size();
    int polje[velicina]={0};
    for(int i=0; i<songs.size();i++){
        if(songs[i].artist==ime){
            brojac++;
            polje[i]=1;
        }
    }
    if(brojac==0){
        cout<<"Nema pjesama od izvodaca kojeg ste unjeli\n";
    }else{
        cout<<"Broj pjesama od unesenog izvodaca: "<<brojac<<endl;
        for(int i=0;i<songs.size();i++){
            if(polje[i]==1){ //vec su sortirane od najstarije
                cout<<"Najstarija pjesma: ";
                print_song(songs[i]);
                break;
            }
        }
    }


    //3)
    cout<<endl<<endl;
    cout<<"Najslusanija pjesma: "<<endl;
    auto mx = std::max_element(songs.begin(), songs.end(),
    [](const Song& a, const Song& b){
        return a.plays < b.plays;
    });
    print_song(songs[mx-songs.begin()]);

    return 0;
}
