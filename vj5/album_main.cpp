
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Song {
    string title;
    string artist;
    int seconds;
    Song(string t, string a, int sec) {
        title = t;
        artist = a;
        seconds = sec;
    }
};
class Album {
private:
    string title;
    int year;
    vector<Song> songs;
public:
    Album(string t, int y, Song s) {
        title = t;
        year = y;
        songs.push_back(s);
    }
    bool add(Song s) {
        for (const Song& x : songs) {
            if (x.title == s.title) {
                return false;
            }
        }

        songs.push_back(s);
        return true;
    }
    int duration() const {
        int br = 0;

        for (const Song& x : songs) {
            br += x.seconds;
        }
        return br;
    }
    void print() const {
        cout << title << " (" << year << "), "
             << songs.size() << " pjesme, "
             << duration() / 60 << ":";
        int sekunde = duration() % 60;
        cout << sekunde << endl;

        int i = 1;
        for (const Song& x : songs) {
            cout << "  " << i << ". " << x.title << endl;
            i++;
        }
    }
};

int main()
{
    Album a("Sol Invictus", 2015, {"Sol Invictus", "Faith No More", 156});
    a.add({"Superhero", "Faith No More", 315});
    a.add({"Matador", "Faith No More", 368});
    cout << a.add({"Superhero", "Faith No More", 315}) << '\n';
    a.print();

    return 0;
}
