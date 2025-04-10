#ifndef OBICNO_VOZILO_H
#define OBICNO_VOZILO_H

#include "Vozilo.h"

class Obicno : public Vozilo {
	static const int startna_obicno = 120;

public:
	Obicno(std::string naziv) :Vozilo(naziv) {}

	double izrCenu(Put& p) override { return (startna_obicno + p.izrDuzinu() * 0.1); }

	friend std::ostream& operator<<(std::ostream& it, const Obicno& o) {
		o.pisi(it);
		return it;
	}

};

#endif