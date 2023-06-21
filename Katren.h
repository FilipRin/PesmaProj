#pragma once
#ifndef _katren_h_
#define _katren_h_
#include"Strofa.h"

class Katren :public Strofa {

	void pisi(ostream& it) const override{
		Strofa::pisi(it);
	}
public:
	Katren() :Strofa(4) { this->ozn = 'K'; };
	bool operator*()const override;
	char Oznaka() const override { return this->ozn; }
};

#endif // !_katren_h_
