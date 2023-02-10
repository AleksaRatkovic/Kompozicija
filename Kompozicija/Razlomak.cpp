#include "Razlomak.h"

Razlomak operator+(const Razlomak& r1, const Razlomak& r2)
{
    //my solution
    /*if (r1.imenilac > r2.imenilac) {
        if (r1.imenilac % r2.imenilac== 0) {
            return Razlomak(r1.brojilac + (r1.imenilac / r2.imenilac) * r2.brojilac, r1.imenilac);
        }
        return Razlomak(r1.imenilac * r2.brojilac + r1.brojilac * r2.imenilac, r1.imenilac * r2.imenilac);
    }
    else if (r2.imenilac % r1.imenilac == 0) {
        return Razlomak(r2.brojilac + (r2.imenilac / r1.imenilac) * r1.brojilac, r2.imenilac);
    }
    return Razlomak(r1.imenilac * r2.brojilac + r1.brojilac * r2.imenilac, r1.imenilac * r2.imenilac);*/

    // Given solution

   return Razlomak(r1.brojilac * r2.imenilac + r1.imenilac * r2.brojilac, r1.imenilac * r2.imenilac);

}

bool operator>(const Razlomak& r1, const Razlomak& r2)
{
    return r1.brojilac *r2.imenilac > r1.imenilac*r2.brojilac;
}

ostream& operator<<(ostream& os, const Razlomak& r)
{
    r.pisi(os);
    return os;
}

void Razlomak::pisi(ostream& os) const
{
    os << brojilac << '/' << imenilac;
}
