#include "Vremenska_oznaka.h"

std::ostream& operator<<(std::ostream& it, const Vreme& v) {
	return it << v.dan << "." << v.mesec << "." << v.godina << "-" << v.sat << ":" << v.minut;
}