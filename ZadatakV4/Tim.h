#ifndef TIM_H
#define TIM_H

#include "Igrac.h"

class Tim {
protected:
	std::string naziv;
	int max_br;
	Igrac** igraci;
	int br = 0;

	void kopiraj(const Tim&);
	void premesti(Tim&);
	void brisi();

public:
	Tim(std::string n, int m) :naziv(n), max_br(m) { 
		igraci = new Igrac * [max_br];
		for (int i = 0; i < max_br; i++) {
			igraci[i] = nullptr;
		}
	}
	Tim(const Tim& t) noexcept { kopiraj(t); }
	Tim(Tim&& t) noexcept { premesti(t); }
	Tim& operator=(const Tim& t) noexcept { if (this != &t) { brisi(); kopiraj(t); return *this; } }
	Tim& operator=(Tim&& t) noexcept { if (this != &t) { brisi(); premesti(t); return *this; } }
	virtual ~Tim() { brisi(); }

	virtual void prikljIgraca(Igrac*, int);
	virtual int dohvBr() const { return br; }
	virtual double dohvVred() const;

	virtual Igrac& operator[](int i);
	virtual const Igrac& operator[](int i) const;
	friend bool operator==(const Tim&, const Tim&);
	friend std::ostream& operator<<(std::ostream&, const Tim&);
};

#endif
