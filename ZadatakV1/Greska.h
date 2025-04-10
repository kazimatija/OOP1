#ifndef GRESKA_H
#define GRESKA_H

#include <exception>

class GNemaTek: public std::exception {
public:
	GNemaTek() :std::exception("Greska: Ne postoji tekuci element.") {}
};

class GVecPoslata : public std::exception {
public:
	GVecPoslata() :std::exception("Greska: Nije moguce menjati tekst vec poslate poruke.") {}
};

#endif