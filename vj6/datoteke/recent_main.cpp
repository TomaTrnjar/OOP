
#include <cassert>
#include <iostream>
#include <string>

class RecentlyPlayed {
private:
    std::string* songs;
    int cap;
    int count;
    int next;

public:
    RecentlyPlayed(int c)
        : songs(new std::string[c]), cap(c), count(0), next(0) {
        assert(c > 0);
    }

    RecentlyPlayed(const RecentlyPlayed& other)
        : songs(new std::string[other.cap]),
          cap(other.cap),
          count(other.count),
          next(other.next) {

        for (int i = 0; i < cap; i++) {
            songs[i] = other.songs[i];
        }
    }

    RecentlyPlayed& operator=(const RecentlyPlayed& other) {
        if (this != &other) {
            std::string* temp = new std::string[other.cap];

            for (int i = 0; i < other.cap; i++) {
                temp[i] = other.songs[i];
            }

            delete[] songs;

            songs = temp;
            cap = other.cap;
            count = other.count;
            next = other.next;
        }

        return *this;
    }


    ~RecentlyPlayed() {
        delete[] songs;
    }

    void play(std::string title) {
        songs[next] = title;

        next = (next + 1) % cap;

        if (count < cap) {
            count++;
        }
    }

    int size() const {
        return count;
    }

    int capacity() const {
        return cap;
    }

    std::string get(int i) const {
        assert(i >= 0 && i < count);

        int index = (next - 1 - i + cap) % cap;

        return songs[index];
    }

    void print() const {
        for (int i = 0; i < count; i++) {
            if (i > 0)
                std::cout << ", ";

            std::cout << get(i);
        }

        std::cout << '\n';
    }
};

int main()
{
    RecentlyPlayed recent(3);
    recent.play("Heroes");
    recent.play("Literary Mind");
    std::cout << recent.size() << ' ' << recent.capacity() << '\n';
    recent.play("Sports");
    recent.print();
    recent.play("Henry Don't Got Love");
    recent.print();

    RecentlyPlayed copy = recent;
    recent.play("Guided by Angels");
    recent.print();
    copy.print();
    std::cout << copy.get(0) << '\n';

    return 0;
}
