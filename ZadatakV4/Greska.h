#ifndef GRESKA_H
#define GRESKA_H

#include <exception>

class GVrednost : public std::exception {
public:
	GVrednost() :std::exception("Greska: Vrednost igraca je manja od minimuma") {}
};

class GNeodigran : public std::exception {
public:
	GNeodigran() :std::exception("Greska: Mec jos uvek nije odigran") {}
};

#endif