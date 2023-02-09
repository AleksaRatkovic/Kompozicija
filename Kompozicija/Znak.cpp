#include "Znak.h"

void Znak::pisi(ostream& os) const
{
	os << this->opis() << '(' << this->dohvTrajanje() << ") \n";
}

Razlomak operator+(const Znak& z1, const Znak& z2)
{
	return z1.dohvTrajanje() + z2.dohvTrajanje();
}

ostream& operator<<(ostream& os, const Znak& z)
{
	z.pisi(os);
	return os;
}
