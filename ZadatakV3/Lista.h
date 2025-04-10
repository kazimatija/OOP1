#ifndef LISTA_H
#define LISTA_H

#include "Greska.h"

template<typename T>
class Lista {
	struct Elem {
		T podatak;
		Elem* sled;
		Elem(const T& p, Elem* s = nullptr) :podatak(p), sled(s) {}
	};
	Elem* prvi = nullptr, * posl = nullptr;
	mutable Elem* tek = nullptr;
	int br = 0;

	void kopiraj(const Lista&);
	void premesti(Lista&);
	void brisi();

public:
	Lista() = default;
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	Lista& operator=(const Lista& l) { 
		if (this != &l) { brisi(); kopiraj(l); }
		return *this;
	}
	Lista& operator=(Lista&& l) {
		if (this != &l) { brisi(); premesti(l); }
		return *this;
	}
	~Lista() { brisi(); }

	void operator+=(const T& pod) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(pod);
		br++;
	}
	T& operator[](int i);
	const T& operator[](int i) const;

	int dohvBroj() const { return br; }
};

template<typename T>
const T& Lista<T>::operator[](int i) const{
	int index = 0;
	tek = prvi;
	while (tek) {
		if (index == i) { return tek->podatak; }
		index++;
		tek = tek->sled;
	}
	throw GNemaPodatak();
}

template<typename T>
T& Lista<T>::operator[](int i) {
	int index = 0;
	tek = prvi;
	while (tek) {
		if (index == i) { return tek->podatak; }
		index++;
		tek = tek->sled;
	}
	throw GNemaPodatak();
}

template<typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = tek = posl = nullptr;
	for (Elem* tmp = l.prvi; tmp; tmp = tmp->sled) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(tmp->podatak);
	}
	br = l.br;
}

template<typename T>
void Lista<T>::premesti(Lista& l) {
	prvi = l.prvi;
	tek = l.tek;
	posl = l.posl;
	br = l.br;
	l.prvi = l.tek = l.posl = nullptr;
}

template<typename T>
void Lista<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	tek = posl = nullptr;
}

#endif
