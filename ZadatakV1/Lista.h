#ifndef LISTA_H
#define LISTA_H

#include "Greska.h"

template <typename T>
class Lista {

	struct Elem {
		T podatak;
		Elem* sled;
		Elem(const T& pod, Elem* sl = nullptr) : podatak(pod), sled(sl) {}
	};

	Elem* prvi, posl;
	mutable Elem* tek;
	int br;

	void kopiraj(const Lista&);
	void premesti(Lista& l);
	void brisi();

public:
	
	Lista() {
		prvi = posl = tek = nullptr;
		br = 0;
	}

	Lista(const Lista& l) {
		kopiraj(l);
	}

	Lista(Lista&& l) {
		premesti(l);
	}

	Lista& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			kopiraj(l);
		}
		return *this;
	}

	Lista& operator=(Lista&& l) {
		if (this != &l){
			brisi();
			premesti(l);
		}
		return *this;
	}

	~Lista() {
		brisi();
	}

	void dodaj(const T& p) {
		posl = ((prvi == nullptr) ? prvi : posl->sled) = new Elem(p);
		br++;
	}

	int dohvBr() const { return br; }

	void naPrvi() const { tek = prvi; }
	const void naPrvi() const { tek = prvi; }
	void naSled() const { if(tek) tek = tek->sled; }
	const void naSled() const { it(tek) tek = tek->sled; }
	bool imaTek() const { if (tek != nullptr) return true; else return false; }

	T& dohvPodatak() { if (tek == nullptr) throw GNemaTek; return tek->podatak; }
	const T& dohvPodatak() const { if (tek == nullptr) throw GNemaTek; return tek->podatak; }

};

template<typename T>
void Lista<T>::kopiraj(const Lista& l) {
	prvi = posl = tek = nullptr;
	for (Elem* tmp = l.prvi; tmp != nullptr; tmp = tmp->sled) {
		posl = ((prvi == nullptr) ? prvi : posl->sled) = new Elem(tmp->pod);
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

#endif // !LISTA_H