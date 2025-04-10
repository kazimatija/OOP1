#include "Mec.h"

int main() {
	try {
		Igrac i1("Uros Lukovic", 30000);
		Igrac i2("Milos Tujkic", 34000);
		Igrac i3("Stefan Filipovic", 28000);
		Igrac i4("Nikola Randjelovic", 27000);
		Igrac i5("Lazar Kostic", 29000);
		Igrac i6("Relja Stosic", 28000);

		Tim t1("Plavi", 3);
		t1.prikljIgraca(&i1, 0);
		t1.prikljIgraca(&i3, 1);
		t1.prikljIgraca(&i4, 2);

		Privilegovani p1("Crveni", 3, 28000);
		p1.prikljIgraca(&i2, 0);
		p1.prikljIgraca(&i5, 1);
		p1.prikljIgraca(&i6, 2);

		Mec m1(&t1, &p1);
		m1.odigrajMec();
		std::cout << m1 << std::endl;

		Igrac i7("Milos Milic", 25000);
		Igrac i8("Miljan Nedeljkovic", 24000);
		Igrac i9("Matej Mihailovic", 23000);
		Igrac i10("Vuk Adamovic", 27000);
		Igrac i11("Aleksandar Maric", 23000);
		Igrac i12("Vladimir Dudic", 33000);

		Privilegovani p2("Orlovi", 3, 20000);
		p2.prikljIgraca(&i7, 0);
		p2.prikljIgraca(&i8, 1);
		p2.prikljIgraca(&i9, 2);

		Tim t2("Lavovi", 3);
		t2.prikljIgraca(&i10, 0);
		t2.prikljIgraca(&i11, 1);
		t2.prikljIgraca(&i12, 2);


		Mec m2(&p2, &t2);
		m2.odigrajMec();
		std::cout << m2 << std::endl;

		/*Par<int, int> p_int = m2.dohvPoene();
		int a = *p_int.dohvPrvi();
		int b = *p_int.dohvDrugi();
		std::cout << a << ", " << b << std::endl;*/

		Mec m3(&p1, &t2);
		m3.odigrajMec();

		std::cout << m3 << std::endl;
	}
	catch(std::exception e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}