#ifndef ELEKTRONSKA_PORUKA_SA_TEKSTOM
#define ELEKTRONSKA_PORUKA_SA_TEKSTOM

#include "Elektronska_Poruka.h"
#include "Greska.h"

class Text : public Poruka {
	std::string text;

protected:
	void pisi(std::ostream&) const override;

public:
	Text(Korisnik& pos, Korisnik& prim, std::string n) :Poruka(pos, prim, n) {}

	void posalji(std::string t) override { if (stanje == POSLATA) throw GVecPoslata(); text = t; stanje = POSLATA; }
	Text* kopija() override;

	friend std::ostream& operator<<(std::ostream&, const Text&);
};

#endif
