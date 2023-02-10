#ifndef _Kompozicija_h_
#define _Kompozicija_h_

#include"Takt.h"

class GZavrsen {
	friend ostream& operator<<(ostream& os, const GZavrsen&) {
		return os << "*** Takt nije zavrsen ***";
	}
};

class GTaktDuz {
	friend ostream& operator<<(ostream& os, const GTaktDuz&) {
		return os << "*** Taktovi nisu jednakih duzina ***";
	}
};

class Kompozicija
{
public:
	Kompozicija() = default;
	Sekvenca<Takt*> taktovi;
	Razlomak r = Razlomak(0);
	bool prvi = false;

public:
	Kompozicija(const Kompozicija& t) = delete;
	void operator=(const Kompozicija& t) = delete;

	Kompozicija& dodaj(Takt& t);
	friend ostream& operator<<(ostream& os, const Kompozicija& k);

};

#endif
