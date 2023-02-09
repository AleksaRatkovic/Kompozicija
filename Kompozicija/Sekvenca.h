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

	Elem* posl, * prvi;
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
			brisi(s); kopiraj(s);
		}
		return *this;
	}
	Sekvenca& operator=(Sekvenca&& s) {
		if (this != &s) { brisi(); premesti(s); }
	}

	~Sekvenca() { brisi(s); }


	void dodaj(T t);
	T& operator[](int i);
	const T& operator[](int i)const;
	int duzina() const;
	T uzmi();




};

#endif

template<typename T>
void Sekvenca<T>::dodaj(T t) {
	if (!moze) {
		throw GDodaj();
	}
	Elem novi = new Elem(t);
	posl = (!prvi ? prvi : posl->sled) = novi;
	duz++;
}

template<typename T>
T Sekvenca<T>::uzmi() {
	T t = prvi->t;
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
		this->dodaj(tek->t);
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
	
	for (Elem* tek = prvi; i--; tek->sled;);
	return tek->t;
}


