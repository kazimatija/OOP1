#include "Posiljka.h"

int Posiljka::stID = 0;

Posiljka& Posiljka::operator+=(Rukovalac* r) {
	if(detalji.dani != 0 && detalji.cena != 0) throw GVecIzracunatiDetalji();
	rukovaoci += r;
	return *this;
}

void Posiljka::izracunajDetalje() {
	for (int i = 0; i < rukovaoci.dohvBr(); i++) {
		rukovaoci[i]->obradi(*this);
	}
};

std::ostream& operator<<(std::ostream& it, const Posiljka& p) {
	return it << "Posiljka[" << p.id << ", " << p.artikal.dohvNaziv() << "]";
}