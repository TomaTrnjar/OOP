// Vjezba 5, zadatak 1: napisite klasu Volume iznad main.


#include <cassert>
#include <iostream>

class Volume {
private:
    int glasnoca;
    int proslaGlasnoca;
    bool isMuted;

    static int ogranicenje(int gl) {
        if (gl > 100) {
            gl = 100;
        }
        else if (gl < 0) {
            gl = 0;
        }
        return gl;
    }

    bool valid() const {
        return glasnoca >= 0 && glasnoca <= 100;
    }

public:
    Volume(int l) {
        glasnoca = ogranicenje(l);
        proslaGlasnoca = glasnoca;
        isMuted = false;
        assert(valid());
    }

    Volume() : Volume(50) {
    }

    void up(int step = 10) {
        glasnoca = ogranicenje(glasnoca + step);
        assert(valid());
    }

    void down(int step = 10) {
        glasnoca = ogranicenje(glasnoca - step);
        assert(valid());
    }

    void mute() {
        if (!isMuted) {
            proslaGlasnoca = glasnoca;
            glasnoca = 0;
            isMuted = true;
        }
        assert(valid());
    }

    void unmute() {
        if (isMuted) {
            glasnoca = proslaGlasnoca;
            isMuted = false;
        }
        assert(valid());
    }

    int get() const {
        return glasnoca;
    }
};

int main() {
    Volume v;
    std::cout << v.get() << '\n';

    v.up();
    v.up(60);
    std::cout << v.get() << '\n';

    v.mute();
    std::cout << v.get() << '\n';

    v.unmute();
    std::cout << v.get() << '\n';

    Volume w(-20);
    w.down();
    std::cout << w.get() << '\n';

    return 0;
}

/*
Ocekivani ispis:

    50
    100
    0
    100
    0
*/
