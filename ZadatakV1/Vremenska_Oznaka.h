#ifndef VREMENSKA_OZNAKA_H
#define VREMENSKA_OZNAKA_H

#include <iostream>

class Vreme {
	int godina, mesec, dan, sat, minut;

public:
	Vreme(int g, int m, int d, int s, int min) : godina(g), mesec(m), dan(d), sat(s), minut(min) {};
	
	friend std::ostream& operator<<(std::ostream&, const Vreme&);
};

#endif