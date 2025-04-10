#include "Korisnik.h"

std::ostream& operator<<(std::ostream& it, const Korisnik& k) {
	return it << "(" << k.ime << ")" << k.email;
}