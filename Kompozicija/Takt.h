#ifndef _Takt_h_
#define _Takt_h_
#include"Nota.h"
#include"Pauza.h"
#include"Sekvenca.h"

class GTakt{
	friend ostream& operator<<(ostream& os, const GTakt&) {
		return os << "*** Takt je potpun ***";
	}
};


class Takt
{
	Sekvenca<Znak*> sekvenca;
	Razlomak max, uk_trajanje;
	bool zavrsen = false;

public:
	Takt(Razlomak m): max(m), uk_trajanje(0){}
	Takt(const Takt& t) = delete;
	void operator=(const Takt& t) = delete;
	Razlomak dohvMaxTrajanje() const { return this->max; }
	Takt& dodaj(Znak& z);
	Takt& zavrsi() { zavrsen = true; return *this; }
	bool zavrsenTakt() const { return zavrsen; }
	bool nepotpun() const { return max > uk_trajanje; }
	friend ostream& operator<<(ostream& os, const Takt& t);
		
	

	

	

};
#endif
