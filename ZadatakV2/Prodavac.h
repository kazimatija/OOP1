#ifndef PRODAVAC_H
#define PRODAVAC_H

#include "Rukovalac.h"
#include "Artikal.h"
#include "Posiljka.h"
#include "Greska.h"
#include "Lista.h"

struct Trojka {
	Artikal art;
	double marza;
	int br_dana;
	Trojka(Artikal a, double m, int b):art(a), marza(m), br_dana(b) {}
};

class Prodavac: public Rukovalac {
	std::string naziv;
	Lista<Trojka> katalog;

public:
	Prodavac(std::string n) :naziv(n) {}
	void prosiriKatalog(const Trojka& t) { katalog += t; }

	std::string dohvNaziv()const { return naziv; }
	void obradi(Posiljka&) override;
};

#endif
