#ifndef POSILJKA_H
#define POSILJKA_H

#include "Artikal.h"
#include "Lista.h"
#include "Rukovalac.h"
#include "Prodavac.h"
#include <iostream>

struct Detalji {
	int dani = 0;
	double cena = 0;
};

class Rukovalac;

class Posiljka {
	Artikal artikal;
	int id = ++stID;
	static int stID;
	Lista<Rukovalac*> rukovaoci;
	Detalji detalji;

public:
	//friend class Rukovalac;
	friend class Prodavac;

	Posiljka(Artikal& a):artikal(a) {}
	Posiljka(const Posiljka& p) :artikal(p.artikal), rukovaoci(p.rukovaoci), detalji(p.detalji) {}
	Posiljka& operator=(const Posiljka& p) { artikal = p.artikal; rukovaoci = p.rukovaoci; detalji = p.detalji; return *this; }

	Posiljka& operator+=(Rukovalac*);

	void izracunajDetalje();

	Artikal dohvArtikal() { return artikal; }
	int dohvID() { return id; }
	Detalji dohvDetalje() { if (detalji.dani == 0 && detalji.cena == 0) throw GNeizracunatiDetalji(); return detalji; }

	friend std::ostream& operator<<(std::ostream&, const Posiljka&);
};

#endif
