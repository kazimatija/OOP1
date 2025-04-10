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
	Elem* prvi = nullptr, *posl = nullptr;
	mutable Elem* tek;
	int br;

	void kopiraj(const Lista& l);
	void premesti(Lista& l);
	void brisi();

public:

	Lista() {
		prvi = posl = tek = nullptr;
		br = 0;
	}

	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }

	Lista& operator=(const Lista& l) {
		if (this != &l) { brisi(); kopiraj(l); return *this; }
	}
	Lista& operator=(Lista && l) {
		if (this != &l) { brisi(); premesti(l); return *this; }
	}

	~Lista() { brisi(); }

	Lista& operator+=(const T& p) {
		posl = ((prvi == nullptr) ? prvi : posl->sled) = new Elem(p);
		br++;
		return *this;
	}

	int dohvBr() const { return br; }

	T& operator[](int i);
	const T& operator[](int i) const;
};

template<typename T>
const T& Lista<T>::operator[](int i) const {
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
	tek = prvi;
	int index = 0;
	while (tek) {
		if (index == i) { return tek->podatak; }
		index++;
		tek = tek->sled;
	}
	throw GNemaPodatak();
}

template<typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = posl = tek = nullptr;
	for (Elem* tmp = l.prvi; tmp; tmp = tmp->sled) {
		posl = ((prvi == nullptr) ? prvi : posl->sled) = new Elem(tmp->podatak);
	}
	br = l.br;
}

template<typename T>
void Lista<T>::premesti(Lista& l) {
	prvi = l.prvi;
	posl = l.posl;
	tek = l.tek;
	br = l.br;
	l.prvi = l.posl = l.tek = nullptr;
}

template<typename T>
void Lista<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = tek = nullptr;
}

#endif