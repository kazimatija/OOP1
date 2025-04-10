#ifndef ARTIKAL_H
#define ARTIKAL_H

#include <string>
#include <iostream>

class Artikal {
	std::string naziv;
	int barkod;
	double cena;

public:
	Artikal(std::string n, int bk, double c) :naziv(n), barkod(bk), cena(c) {}

	std::string dohvNaziv() const { return naziv; }
	int dohvBarkod() const { return barkod; }
	double dohvCenu() const { return cena; }

	friend bool operator==(const Artikal& a1, const Artikal& a2) {
		return a1.barkod == a2.barkod;
	}

	friend std::ostream& operator<<(std::ostream& it, const Artikal& a) {
		return it << "Naziv: " << a.naziv << ", Barkod: " << a.barkod << ", Cena: " << a.cena;
	}
};

#endif
