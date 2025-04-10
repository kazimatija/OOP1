#ifndef PUT_H
#define PUT_H

#include "Tacka.h"
#include "Lista.h"

class Put {
	Lista<Tacka> tacke;

public:
	void operator+=(const Tacka& t);
	double izrDuzinu();

	friend std::ostream& operator<<(std::ostream&, const Put&);
};

#endif