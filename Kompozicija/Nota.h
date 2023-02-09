#ifndef _Nota_h_
#define _Nota_h_
#include"Znak.h"

class GPogresanBroj {
	friend ostream& operator<<(ostream& os, const GPogresanBroj&) {
		return os << "*** Unos oktave mora biti izmedju 1 i 5 ***";
	}
};

enum Visina { DO, RE, MI, FA, SO, LA, SI };

class Nota : public Znak
{
	Visina visina;
	int oktava;
public:
	Nota(Visina v, int o, Razlomak r) : Znak(r), visina(v) {
		if (o > 5 || o < 1) GPogresanBroj();
		oktava = o;
}
	Nota& operator<<=(int p);
	Nota& operator>>=(int p);

	virtual string opis() const override;



};

#endif

