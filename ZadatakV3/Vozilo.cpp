#include "Vozilo.h"

std::ostream& operator<<(std::ostream& it, const Vozilo& v) {
	v.pisi(it);
	return it;
}
