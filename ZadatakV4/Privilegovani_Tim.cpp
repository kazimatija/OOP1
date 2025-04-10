#include "Privilegovani_Tim.h"

bool operator==(const Privilegovani& p1, const Privilegovani& p2) {
	if (p1.max_br != p2.max_br || p1.naziv != p2.naziv) return false;
	for (int i = 0; i < p1.max_br; i++) {
		if (p1.igraci[i] != p2.igraci[i]) return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& it, const Privilegovani& p) {
	int i = 0;
	it << p.naziv << "(" << p.min_vr << ")" << "[";
	for (i = 0; i < p.max_br - 1; i++) {
		if (p.igraci[i]) {
			it << *(p.igraci[i]);
			break;
		}
	}
	for (++i; i < p.max_br; i++) {
		if (p.igraci[i]) it << " ," << *(p.igraci[i]);
	}
	it << "]";
	return it;
}
