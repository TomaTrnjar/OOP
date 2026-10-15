#include <iostream>
#include <cmath>
using namespace std;

struct Point {
	double x;
	double y;
};

void move_by(Point* p, double dx, double dy) {
	p->x += dx;
	p->y += dy;
}

double dist(const Point* a, const Point* b) {
	return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

void move_by(Point& p, double dx, double dy) {
	p.x += dx;
	p.y += dy;
}

double dist(const Point& a, const Point& b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
	Point p = {3, 4};
	Point o = {0, 0};

	cout << "Udaljenost (pointeri): " << dist(&p, &o) << "\n";
	cout << "Udaljenost (reference): " << dist(p, o) << "\n";

	move_by(&p, 1, 1);
	cout << "Nakon move_by pointerima: " << p.x << ", " << p.y << "\n";
	move_by(p, 1, 1);
	cout << "Nakon move_by referencama: " << p.x << ", " << p.y << "\n";

	Point niz[5] = {{3, 4}, {-1, 2}, {0.5, -0.5}, {5, 5}, {-2, -3}};
	int index = 0;
	for (int i = 1; i < 5; i++) {
		if (dist(niz[i], o) < dist(niz[index], o)) {
			index = i;
		}
	}
	cout << "Najbliza ishodistu: " << niz[index].x << ", " << niz[index].y << "\n";
}