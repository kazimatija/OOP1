#include "Prodavac.h"

int main() {

	try {
		Artikal a1("Hleb", 473289479, 70);

		Trojka t1(a1, 1.5, 2);

		Prodavac prod1("Marko");
		prod1.prosiriKatalog(t1);

		Posiljka pos1(a1);
		pos1 += &prod1;

		pos1.izracunajDetalje();
		Detalji d1 = pos1.dohvDetalje();
		std::cout << d1.cena << ", " << d1.dani << std::endl;

		std::cout << pos1 << std::endl;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}