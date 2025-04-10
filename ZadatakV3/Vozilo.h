#ifndef VOZILO_H
#define VOZILO_H

#include <string>
#include "Put.h"

class Vozilo {
	std::string naziv;

protected:
	virtual void pisi(std::ostream& it) const {	it << naziv; }
	friend std::ostream& operator<<(std::ostream& it, const Vozilo& v);

public:
	Vozilo(std::string n) :naziv(n) {}
	~Vozilo() {}

	virtual double izrCenu(Put& p) = 0;

};

#endif
