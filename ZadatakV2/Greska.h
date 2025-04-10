#ifndef GRESKA_H
#define GRESKA_H

#include <exception>

class GNemaPodatak : public std::exception {
public:
	GNemaPodatak() :std::exception("Greska: Ne postoji podatak na zadatoj poziciji") {}
};

class GNeizracunatiDetalji : public std::exception {
public:
	GNeizracunatiDetalji() :std::exception("Greska: Detalji posiljke jos uvek nisu izracunati") {}
};

class GVecIzracunatiDetalji : public std::exception {
public:
	GVecIzracunatiDetalji() :std::exception("Greska: Nemoguce dodati novog rukovaoca nakon izracunatih detalja") {}
};

#endif
