#ifndef MEC_H
#define MEC_H

#include "Par.h"
#include "Privilegovani_Tim.h"

class Mec {
	Par<Tim, Tim> mec;
	enum Ishod { POBEDA_DOMACIN, NERESENO, POBEDA_GOST };
	Ishod ishod;
	bool neodigran = true;

public:
	Mec(Tim* t1, Tim* t2) :mec(t1, t2) {}

	Par<Tim, Tim> dohvPar() const { return mec; }
	Par<int, int> dohvPoene();

	void odigrajMec();
	void vrednostDomacin(double);
	void vrednostGost(double);
	bool odigran() const;

	friend std::ostream& operator<<(std::ostream&, const Mec&);
};

#endif
