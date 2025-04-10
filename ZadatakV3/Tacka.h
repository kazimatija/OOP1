#ifndef TACKA_H
#define TACKA_H

#include <cmath>
#include <iostream>

class Tacka {
	int x, y;

public:
	Tacka(int xx, int yy) :x(xx), y(yy) {}
	friend double izrUdaljenost(const Tacka& t1, const Tacka& t2) {
		return sqrt(pow((t1.x - t2.x), 2) + pow((t1.y - t2.y), 2));
	}

	friend bool operator==(const Tacka& t1, const Tacka& t2) {
		if (t1.x == t2.x && t1.y == t2.y) { return true; }
		else return false;
	}

	friend std::ostream& operator<<(std::ostream& it, const Tacka& t) {
		return it << "(" << t.x << "," << t.y << ")";
	}
};

#endif
