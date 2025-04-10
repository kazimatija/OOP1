#include "Mec.h"

void Mec::odigrajMec() {
	if (mec.dohvPrvi()->dohvVred() > mec.dohvDrugi()->dohvVred()) {
		ishod = POBEDA_DOMACIN; 
		vrednostDomacin(0.1);
		vrednostGost(-0.1);
	}
	else if (mec.dohvDrugi()->dohvVred() > mec.dohvPrvi()->dohvVred()) {
		ishod = POBEDA_GOST;
		vrednostGost(0.1);
		vrednostDomacin(-0.1);
	}
	else ishod = NERESENO;
 }

void Mec::vrednostDomacin(double proc) {
	int i = 0, brojac = 0;
	while (brojac < mec.dohvPrvi()->dohvBr()) {
		if (&(*(mec.dohvPrvi()))[i] != nullptr) {
			(*mec.dohvPrvi())[i].promeniVrednost(proc);
			brojac++;
		}
		i++;
	}
}

void Mec::vrednostGost(double proc) {
	int i = 0, brojac = 0;
	while (brojac < mec.dohvDrugi()->dohvBr()) {
		if (&(*(mec.dohvDrugi()))[i] != nullptr) {
			(*mec.dohvDrugi())[i].promeniVrednost(proc);
			brojac++;
		}
		i++;
	}
}

Par<int, int> Mec::dohvPoene() {
	if (neodigran) throw GNeodigran();
	int domacin = 0, gost = 0;
	if (ishod == POBEDA_DOMACIN) { domacin = 3; gost = 0; }
	if (ishod == POBEDA_GOST) { domacin = 0; gost = 3; }
	if (ishod == NERESENO) { domacin = 1; gost = 1; }
	static Par<int, int> poeni(&domacin, &gost);
	return poeni;
}

bool Mec::odigran() const {
	if (neodigran) return false;
	else return true;
}

std::ostream& operator<<(std::ostream& it, const Mec& m) {
	it << m.mec;
	if (m.odigran()) {
		switch (m.ishod) {
		case 0: it << ", Pobeda domacini";
			break;
		case 1: it << ", Nereseno";
			break;
		case 2: it << ", Pobeda gosti";
		}
	}
	return it;
}
