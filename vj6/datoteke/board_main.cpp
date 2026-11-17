
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

        // Rubovi dobivaju znak rub, unutrašnjost razmak
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                polja[i * c + j] =
                    (i == 0 || i == r - 1 || j == 0 || j == c - 1)
                    ? rub : ' ';
            }
        }
    }

    ~Board() {
        delete[] polja;
    }

    // Copy konstruktor (deep copy)
    Board(const Board& b) {
        r = b.r;
        c = b.c;
        rub = b.rub;

        polja = new char[r * c];

        for (int i = 0; i < r * c; i++) {
            polja[i] = b.polja[i];
        }
    }

    // Operator dodjele (deep copy)
    Board& operator=(const Board& b) {
        if (this != &b) {
            char* novo = new char[b.r * b.c];

            for (int i = 0; i < b.r * b.c; i++) {
                novo[i] = b.polja[i];
            }

            delete[] polja;

            polja = novo;
            r = b.r;
            c = b.c;
            rub = b.rub;
        }

        return *this;
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
                cout << polja[i * c + j];
            }
            cout << '\n';
        }
    }
};

int main() {
    Board b1(4, 8, '#');

    b1.set(1, 2, '@');

    Board b2 = b1;  // Poziva copy konstruktor

    b2.set(2, 5, '*');

    b1.print();
    b2.print();

    cout << b1.rows() << " "
         << b1.cols() << " "
         << b2.get(2, 5) << endl;

    return 0;
}

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
