#include "Obicno_Vozilo.h"

int main() {

	try {
		Tacka t1(0, 0);
		Tacka t2(-200, -200);
		Tacka t3(500, 500);

		Put p;
		p += t1;
		p += t2;
		p += t3;

		/*Obicno o("Dacia");
		std::cout << o << std::endl;
		std::cout << o.izrCenu(p) << std::endl;*/

		std::cout << p << std::endl;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}