#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Vec2 {
	int x;
	int y;
};

struct Enemy {
	string name;
	Vec2 pos;
};

class InRange {
	Vec2 center;
	int range;
public:
	InRange(Vec2 c, int r) {
		center = c;
		range = r;
	}
	bool operator()(const Enemy& e) const {
		int dx = e.pos.x - center.x;
		int dy = e.pos.y - center.y;
		return dx * dx + dy * dy <= range * range;
	}
};

int main()
{
    vector<Enemy> enemies = {
        {"Goblin", {2, 2}}, {"Troll", {6, 1}}, {"Bat", {3, 5}},
        {"Ghost", {0, 0}}, {"Slime", {7, 7}}
    };
    Vec2 player{3, 3};

    InRange near(player, 2);
    cout << near(enemies[0]) << ' ' << near(enemies[1]) << '\n';

    int n1 = count_if(enemies.begin(), enemies.end(), near);
    cout << n1 << '\n';

    int range = 2;

    int n2 = count_if(enemies.begin(), enemies.end(), [player, range](const Enemy& e) {
        int dx = e.pos.x - player.x;
        int dy = e.pos.y - player.y;
        return dx * dx + dy * dy <= range * range;
    });
    cout << n2 << '\n';
    return 0;
}
