#ifndef _Sekvenca_h_
#define _Selvenca_h_

#include<iostream>
using namespace std;

class GDodaj {
	friend ostream& operator<<(ostream& os, const GDodaj&) {
		return os << "Element je uzet !!!";
	}
};

template<typename T>
class Sekvenca {
	struct Elem {
		T pod;
		Elem* sled;

		Elem(T t): pod(t), sled(nullptr) {}
	};

	Elem* posl = nullptr, * prvi = nullptr;
	int duz = 0;
	bool moze = true;

	void kopiraj(const Sekvenca& s);
	void premesti(Sekvenca& s);
	void brisi();


public:
	Sekvenca() = default;
	Sekvenca(const Sekvenca& s) { kopiraj(s); }
	Sekvenca(Sekvenca&& s) { premesti(s); }
	Sekvenca& operator=(const Sekvenca& s) {
		if (this != &s) {
			brisi(); kopiraj(s);
		}
		return *this;
	}
	Sekvenca& operator=(Sekvenca&& s) {
		if (this != &s) { brisi(); premesti(s); }
	}

	~Sekvenca() { brisi(); }


	Sekvenca& dodaj(T t);
	T& operator[](int i);
	const T& operator[](int i)const;
	int duzina() const { return duz; }
	T uzmi();




};

#endif

template<typename T>
Sekvenca<T>& Sekvenca<T>::dodaj(T t) {
	if (!moze) {
		throw GDodaj();
	}
	posl = (!prvi ? prvi : posl->sled) = new Elem(t);
	duz++;
	return *this;
}

template<typename T>
T Sekvenca<T>::uzmi() {
	T t = prvi->pod;
	Elem* pom = prvi;
	prvi = prvi->sled;
	if (!prvi) posl = prvi;
	delete pom;
	duz--;
	moze = false;
	return t;
}

template<typename T>
void Sekvenca<T>::kopiraj(const Sekvenca<T>& s) {
	duz = 0; moze = true;
	for (Elem* tek = s.prvi; tek; tek->sled) {
		this->dodaj(tek->pod);
	}
}

template<typename T>
void Sekvenca<T>::premesti(Sekvenca<T>&  s) {
	duz = s.duz; moze = s.moze;
	prvi = s.prvi; posl = s.posl;
	s.prvi = nullptr;
}

template<typename T>
void Sekvenca<T>::brisi() {
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
}

template<typename T>
T& Sekvenca<T>::operator[](int i) {
	if (i < 0 || i >= duz) throw GDodaj();
	Elem* tek = prvi;
	for (; i > 0; i--, tek = tek->sled);
	return tek->pod;
}

template<typename T>
const T& Sekvenca<T>::operator[](int i) const {
	return const_cast<Sekvenca&>(*this)[i];
}


