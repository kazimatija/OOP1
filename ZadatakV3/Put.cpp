#include "Put.h"

void Put::operator+=(const Tacka& t) {
	for (int i = 0; i < tacke.dohvBroj(); i++) {
		if (tacke[i] == t) throw GVecPostojecaTacka();
	}
	tacke += t;
}

double Put::izrDuzinu() {
	double duzina = 0;
	for (int i = 0; i < tacke.dohvBroj() - 1; i++) {
		duzina += izrUdaljenost(tacke[i], tacke[i + 1]);
	}
	return duzina;
}

std::ostream& operator<<(std::ostream& it, const Put& p) {
	int i = 0;
	for (; i < p.tacke.dohvBroj() - 1; i++) {
		it << p.tacke[i] << std::endl;
	}
	it << p.tacke[i];
	return it;
}
