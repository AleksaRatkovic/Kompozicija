#ifndef _Znak_h_
#define _Znak_h_
#include"Razlomak.h"

class Znak
{
	Razlomak trajanje;
	void pisi(ostream& os) const;

public:
	Znak(Razlomak r): trajanje(r) {}
	Razlomak dohvTrajanje() const { return this->trajanje; }

	friend Razlomak operator+(const Znak& z1, const Znak& z2);
	virtual string opis() const = 0;
	friend ostream& operator<<(ostream& os, const Znak& z);

	virtual ~Znak() {}

};

#endif

