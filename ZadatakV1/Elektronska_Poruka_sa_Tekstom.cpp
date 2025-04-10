#include "Elektronska_Poruka_sa_Tekstom.h"

Text* Text::kopija() {
	return new Text(*this);
}

void Text::pisi(std::ostream& it) const {
	Poruka::pisi(it);
	it << std::endl << text;
}

std::ostream& operator<<(std::ostream& it, const Text& t) {
	t.pisi(it);
	return it;
}
