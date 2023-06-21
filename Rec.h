#pragma once
#include <string>
#ifndef _rec_h_
#define _rec_h_
#include"Skup.h"

using namespace std;

class Rec {
	string niska="";
	Skup *samoglasnici=new Skup("aeiou");
	Skup *nosiociSugl=new Skup("lnr");
public:
	Rec(string niska);

	int operator+() const { return niska.length(); }
	int operator~() const;
	int operator()(int n);
	bool friend operator^( Rec& r1,Rec& r2);
	friend istream& operator>>(istream& it, Rec& r);
	friend ostream& operator<<(ostream& it, Rec& r);

	~Rec(){
		this->niska = "";
		int br=this->samoglasnici->gettreeSize(this->samoglasnici->getRoot());
	}
};

#endif // !_rec_h_
