#include "Takt.h"

Takt& Takt::dodaj(Znak& z)
{
    if(zavrsen) throw GTakt();
    sekvenca.dodaj(&z);
    uk_trajanje = uk_trajanje+  z.dohvTrajanje();
    return *this;

}

ostream& operator<<(ostream& os, const Takt& t)
{
    for (int i = 0; i < t.sekvenca.duzina(); i++)
        os << *t.sekvenca[i] << " ";
    return os << "|";
}
