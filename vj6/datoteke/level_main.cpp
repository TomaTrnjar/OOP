
#include <iostream>
#include <string>
#include <vector>

class Enemy {
private:
    std::string name;
    int x, y;
    int health;

public:
    Enemy(std::string n, int x, int y)
        : name(n), x(x), y(y), health(100) {}

    std::string get_name() const {
        return name;
    }

    int get_x() const {
        return x;
    }

    int get_y() const {
        return y;
    }

    int get_health() const {
        return health;
    }

    bool is_alive() const {
        return health > 0;
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void take_damage(int d) {
        health -= d;

        if (health < 0)
            health = 0;
    }
};

class Level {
private:
    int rows;
    int cols;
    std::vector<Enemy> enemies;

public:
    Level(int r, int c) : rows(r), cols(c) {}

    bool add(Enemy e) {
        if (e.get_x() < 0 || e.get_x() >= cols ||
            e.get_y() < 0 || e.get_y() >= rows) {
            return false;
        }

        enemies.push_back(e);
        return true;
    }

    void step(int dx, int dy) {
        for (int i = 0; i < enemies.size(); i++) {
            int new_x = enemies[i].get_x() + dx;
            int new_y = enemies[i].get_y() + dy;

            if (new_x >= 0 && new_x < cols &&
                new_y >= 0 && new_y < rows) {
                enemies[i].move(dx, dy);
            }
        }
    }

    void print() const {
        for (const Enemy& e : enemies) {
            std::cout << e.get_name() << " ("
                      << e.get_x() << ", "
                      << e.get_y() << ") "
                      << e.get_health() << '\n';
        }
    }

    void draw() const {
        std::vector<std::string> board(
            rows + 2, std::string(cols + 2, ' ')
        );

        for (int i = 0; i < rows + 2; i++) {
            board[i][0] = '#';
            board[i][cols + 1] = '#';
        }

        for (int j = 0; j < cols + 2; j++) {
            board[0][j] = '#';
            board[rows + 1][j] = '#';
        }

        for (const Enemy& e : enemies) {
            board[e.get_y() + 1][e.get_x() + 1] =
                e.get_name()[0];
        }

        for (const std::string& line : board) {
            std::cout << line << '\n';
        }
    }
};

int main()
{
    Level cave(5, 10);
    cave.add(Enemy("Gnome", 1, 1));
    std::cout << cave.add(Enemy("Troll", 8, 3))
              << cave.add(Enemy("Bat", 12, 2)) << '\n';
    cave.step(1, 1);
    cave.print();
    cave.step(1, 1);
    cave.print();
    return 0;
}
