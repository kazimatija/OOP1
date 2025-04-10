#include "Prodavac.h"

void Prodavac::obradi(Posiljka& pos) {
	for (int i = 0; i < katalog.dohvBr(); i++) {
		if (pos.artikal == katalog[i].art) {
			pos.detalji.dani += katalog[i].br_dana;
			pos.detalji.cena += (katalog[i].marza * katalog[i].art.dohvCenu());
		}
	}
}