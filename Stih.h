#pragma once
#ifndef _stih_h_
#define _stih_h_
#include"Skup.h"
#include"Rec.h"
#include <string>
using namespace std;

class Stih {
	struct Elem
	{
		Rec* r;
		Elem* next;
		Elem(Rec& rec) { r = &rec,next=nullptr; }
	};
	mutable int br=0;
	//Elem* reci=nullptr;
	mutable Elem* prvi, * poslednji;
	mutable Elem* tek = nullptr;

	void brisi();
	void kopiraj(const Stih& s);
	void premesti(Stih& s) {
		prvi = s.prvi;
		poslednji = s.poslednji;
		tek = s.tek;
		s.prvi = s.poslednji = nullptr;
		br = s.br;
		s.br = 0;
	}
public:
	Stih() { this->prvi = nullptr; this->poslednji = nullptr; };
	Stih(const Stih& s) { kopiraj(s); s.br = this->br; }
	Stih(Stih&& s) { premesti(s); }

	Stih& operator=(const Stih& s) {
		if (this != &s) {
			brisi();
			kopiraj(s);
		}
		return *this;
	}

	Stih& operator=(Stih&& s) {
		if (this != &s) {
			brisi();
			premesti(s);
		}
		return *this;
	}

	void operator+=(Rec& r) const;
	int operator+() const;
	int operator~() const;
	Rec* operator[](int ind)const;
	void operator()(Rec& r, int ind);
	void operator()(int ind);
	Stih* kopija() const { return new Stih(*this); }
	bool friend operator^(Stih& s1, Stih& s2);
	friend istream& operator>>(istream& it, Stih& s);
	friend ostream& operator<<(ostream& it, Stih& s);

	~Stih();
};



#endif _stih_h_