
#include <iostream>
#include <cassert>
using namespace std;

class Board {
private:
    int r;
    int c;
    char rub;
    char* polja;

public:
    Board(int rows, int cols, char ch) {
        assert(rows > 0 && cols > 0);

        r = rows;
        c = cols;
        rub = ch;

        polja = new char[r * c];

        for (int i = 0; i < r * c; i++) {
            polja[i] = rub;
        }
    }

    ~Board() {
        delete[] polja;
    }

    // Deep copy konstruktor
    Board(const Board& b) {
        r = b.r;
        c = b.c;
        rub = b.rub;

        polja = new char[r * c];

        for (int i = 0; i < r * c; i++) {
            polja[i] = b.polja[i];
        }
    }

    void set(int i, int j, char ch) {
        if (i > 0 && i < r - 1 && j > 0 && j < c - 1) {
            polja[i * c + j] = ch;
        }
    }

    char get(int i, int j) const {
        assert(i >= 0 && i < r && j >= 0 && j < c);
        return polja[i * c + j];
    }

    int rows() const {
        return r;
    }

    int cols() const {
        return c;
    }

    void print() const {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << polja[i * c + j] << ' ';
            }
            cout << '\n';
        }
    }
};

/*
Ocekivani ispis:

    ########
    # @    #
    #      #
    ########
    ########
    # @    #
    #    * #
    ########
    4 8 *
*/
