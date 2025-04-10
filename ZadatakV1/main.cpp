#include "Elektronska_Poruka_sa_Tekstom.h"
#include "Vremenska_oznaka.h"

int main() {
	try {

		Korisnik k1("Marko", "m.markovic@gmail.com");
		Korisnik k2("Zarko", "z.zarkovic@gmail.com");
		
		Text p(k1, k2, "Ispit");
		p.posalji("Kada imamo ispit iz OOP-a?");

		std::cout << p << std::endl;

	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}