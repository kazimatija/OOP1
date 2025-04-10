#ifndef IGRAC_H
#define IGRAC_H

#include <string>
#include <iostream>

class Igrac {
	std::string ime;
	int vrednost;
	
public:
	Igrac(std::string i, int v = 1000) :ime(i), vrednost(v) {}

	int dohvVrednost() const { return vrednost; }
	void promeniVrednost(const double procenat) { vrednost += vrednost * procenat; }

	friend bool operator==(const Igrac& i1, const Igrac& i2) {
		if (i1.ime == i2.ime && i1.vrednost == i2.vrednost) return true;
		else return false;
	}

	friend std::ostream& operator<<(std::ostream& it, const Igrac& i) {
		return it << i.ime << '#' << i.vrednost;
	}
};

#endif