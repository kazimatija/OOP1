#ifndef RUKOVALAC_H
#define RUKOVALAC_H

//#include "Posiljka.h"

class Posiljka;

class Rukovalac {

public:
	virtual void obradi(Posiljka&) = 0;
};

#endif
