#ifndef _Razlomak_h_
#define _Razlomak_h_

#include<iostream>

using namespace std;
class Razlomak
{
	int imenilac;
	int brojilac;

	void pisi(ostream& os) const ;

public:
	Razlomak(int b, int i=1): imenilac(i), brojilac(b) {}

	friend Razlomak operator+(const Razlomak& r1, const Razlomak& r2);
	friend bool operator>(const Razlomak& r1, const Razlomak& r2);
	friend ostream& operator<<(ostream& os, const Razlomak& r);


};

#endif

