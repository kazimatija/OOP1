#include "Elektronska_Poruka.h"

void Poruka::pisi(std::ostream& it) const {
	it << naslov << std::endl << *posiljalac << std::endl << *primalac;
}

std::ostream& operator<<(std::ostream& it, const Poruka& p) {
	 p.pisi(it);
	 return it;
}
