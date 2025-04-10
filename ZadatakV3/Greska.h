#ifndef GRESKA_H
#define GRESKA_H

#include <exception>

class GNemaPodatak :public std::exception {
public:
	GNemaPodatak() :std::exception("Greska: Ne postoji podatak na zadatoj poziciji") {}
};

class GVecPostojecaTacka :public std::exception {
public:
	GVecPostojecaTacka() :std::exception("Greska: Uneli ste vec postojecu tacku") {}
};

#endif