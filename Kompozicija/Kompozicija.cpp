#include "Kompozicija.h"

Kompozicija& Kompozicija::dodaj(Takt& t)
{
    if (!t.zavrsenTakt()) throw GZavrsen();
    if (!prvi) { r = t.dohvMaxTrajanje(); prvi = true; }
    else {
        if (t.dohvMaxTrajanje() > r || r > t.dohvMaxTrajanje()) throw GTaktDuz(); //Ovo je moglo da se odradi tako sto preklopimo operator == u razlomku
    }

    taktovi.dodaj(&t);

}

ostream& operator<<(ostream& os, const Kompozicija& k)
{
    for (int i = 0; i < k.taktovi.duzina(); i++)
        os << *k.taktovi[i] << endl;
    return os;

}
