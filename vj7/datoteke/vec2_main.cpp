
#include <iostream>
using namespace std;

struct Vec2 {
    int x;
    int y;

    Vec2& operator+=(const Vec2& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }
};

Vec2 operator+(Vec2 a, const Vec2& b) {
    a += b;
    return a;
}

Vec2 operator-(Vec2 a, const Vec2& b) {
    a -= b;
    return a;
}

Vec2 operator*(const Vec2& v, int n) {
    return {v.x * n, v.y * n};
}

Vec2 operator*(int n, const Vec2& v) {
    return v * n;
}

bool operator==(const Vec2& a, const Vec2& b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Vec2& a, const Vec2& b) {
    return !(a == b);
}

ostream& operator<<(ostream& os, const Vec2& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

int main()
{
    Vec2 player{2, 3};
    Vec2 right{1, 0};
    Vec2 down{0, 1};

    player += right;
    cout << player << '\n';

    player += 2 * down;
    cout << player << '\n';

    Vec2 target = player + right * 3 - down;
    cout << target << '\n';

    Vec2 enemy{6, 4};
    cout << (target == enemy) << ' ' << (player != enemy) << '\n';

    cout << player << " -> " << target << '\n';

    return 0;
}
