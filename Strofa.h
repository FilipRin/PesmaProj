#pragma once
#include "Stih.h"
#ifndef _strofa_h_
#define _strofa_h_

class Strofa {
	
	struct Elem
	{
		Stih* s;
		Elem* next;
		Elem(Stih& st) { s = &st, next = nullptr; }
	};
	

	void brisi();
	void kopiraj(const Strofa& st);
	void premesti(Strofa& s) {
		prvi = s.prvi;
		poslednji = s.poslednji;
		tek = s.tek;
		s.prvi = s.poslednji = nullptr;
		br = s.br;
		s.br = 0;
	}
protected:
	mutable int br = 0;
	mutable Elem* prvi = nullptr, * poslednji = nullptr;
	mutable Elem* tek = nullptr;
	int kap;
	char ozn;
	virtual void pisi(ostream& it)const;
public:
	Strofa(int k) :kap(k) {}
	Strofa(const Strofa& s) { kopiraj(s); s.br = this->br; }
	Strofa(Strofa&& s) { premesti(s); }

	int dohvKap()const { return kap; }

	void operator +=(Stih& stih);
	void operator -();
	int operator+()const;
	Stih* operator[](int ind)const;
	void operator()(int i, int j);//--------------------------
	virtual bool operator*()const=0;
	virtual char Oznaka()const = 0;
	friend ostream& operator<<(ostream& it, Strofa& st);


	virtual ~Strofa() { brisi(); }
};

#endif // !_strofa_h_
