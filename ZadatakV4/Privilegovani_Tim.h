#ifndef PRIVILEGOVANI_H
#define PRIVILEGOVANI_H

#include "Igrac.h"
#include "Tim.h"
#include "Greska.h"

class Privilegovani :public Tim {
	int min_vr;

	void kopiraj(const Privilegovani& p) { min_vr = p.min_vr; Tim::kopiraj(p); }
	void premesti(Privilegovani& p) { min_vr = p.min_vr; Tim::premesti(p); }
	void brisi() { Tim::brisi(); }

public:
	Privilegovani(std::string n, int max, int min) :Tim(n, max), min_vr(min) {}
	Privilegovani(const Privilegovani& p) noexcept :Tim(p.naziv, p.max_br) { kopiraj(p); }
	Privilegovani(Privilegovani&& p) noexcept :Tim(p.naziv, p.max_br) { premesti(p); }
	Privilegovani& operator=(const Privilegovani& p) noexcept { if (this != &p) { brisi(); kopiraj(p); return *this; } }
	Privilegovani& operator=(Privilegovani&& p) noexcept { if (this != &p) { brisi(); premesti(p); return *this; } }

	friend bool operator==(const Privilegovani&, const Privilegovani&);
	friend std::ostream& operator<<(std::ostream&, const Privilegovani&);
};

#endif
