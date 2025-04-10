#include "Tim.h"

void Tim::kopiraj(const Tim& t) {
	naziv = t.naziv;
	max_br = t.max_br;
	br = t.br;
	igraci = new Igrac*[max_br];
	for (int i = 0; i < max_br; i++) {
		igraci[i] = nullptr;
		if(t.igraci[i]) igraci[i] = t.igraci[i];
	}
}

void Tim::premesti(Tim& t) {
	igraci = t.igraci;
	max_br = t.max_br;
	naziv = t.naziv;
	t.igraci = nullptr;
}

void Tim::brisi() {
	delete[] igraci;
	igraci = nullptr;
}

void Tim::prikljIgraca(Igrac* igr, int i) {
	if (i < max_br && i >= 0) {
		igraci[i] = igr;
		br++;
	}
}

double Tim::dohvVred() const {
	double sr_vred = 0;
	for (int i = 0; i < max_br; i++) {
		if (igraci[i]) {
			sr_vred += igraci[i]->dohvVrednost();
		}
	}
	return sr_vred / br;
}

Igrac& Tim::operator[](int i) {
	return *(igraci[i]);
}

const Igrac& Tim::operator[](int i) const {
	return const_cast<Tim&>(*this)[i];
}

bool operator==(const Tim& t1, const Tim& t2) {
	if (t1.max_br != t2.max_br || t1.naziv != t2.naziv) return false;
	for (int i = 0; i < t1.max_br; i++) {
		if (t1.igraci[i] != t2.igraci[i]) return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& it, const Tim& t) {
	int i = 0;
	it << t.naziv << "[";
	for (i = 0; i < t.max_br - 1; i++) {
		if (t.igraci[i]) { 
			it << *(t.igraci[i]);
			break;
		}
	}
	for (++i; i < t.max_br; i++) {
		if (t.igraci[i]) it << " ," << *(t.igraci[i]);
	}
	it << "]";
	return it;
}
