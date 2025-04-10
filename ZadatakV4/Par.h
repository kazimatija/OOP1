#ifndef PAR_H
#define PAR_H

#include <iostream>

template<typename T1, typename T2>
class Par {
	T1* prvi;
	T2* drugi;
public:
	Par(T1* p, T2* d) :prvi(p), drugi(d) {}

	T1* dohvPrvi() const { return prvi; }
	T2* dohvDrugi() const { return drugi; }

	void postaviPrvi(T1& pod) { prvi = &pod; }
	void postaviDrugi(T2& pod) { drugi = &pod; }

	bool operator==(T2* d) { if (*(this->prvi) == *d) return true; else return false; }
	friend std::ostream& operator<<(std::ostream& it, const Par& p) {
		return it << "[" << *(p.dohvPrvi()) << "-" << *(p.dohvDrugi()) << "]";
	}
};

#endif
