#ifndef ELEKTRONSKA_PORUKA_H
#define ELEKTRONSKA_PORUKA_H

#include "Korisnik.h"
#include <string>

class Poruka {
	Korisnik* posiljalac;
	Korisnik* primalac;
	std::string naslov;

protected:
	enum Stanje { U_PRIPREMI, POSLATA, PRIMLJENA };
	Stanje stanje;

	virtual void pisi(std::ostream&) const;

public:

	Poruka(Korisnik& pos, Korisnik& prim, std::string n) :naslov(n) {
		stanje = U_PRIPREMI;
		posiljalac = &pos;
		primalac = &prim;
	};

	virtual ~Poruka() {}; 

	Korisnik& dohvPos() const { return *posiljalac; }
	Korisnik& dohvPrim() const { return *primalac; }
	Stanje dohvStanje() const { return stanje; }
	std::string dohvNaziv() const { return naslov; }

	virtual void posalji(std::string t) = 0;
	virtual Poruka* kopija() = 0;

	friend std::ostream& operator<<(std::ostream&, const Poruka&);
};

#endif