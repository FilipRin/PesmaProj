#include "Rec.h"

Rec::Rec(string niska)
{
	for (int i = 0; i < niska.length(); i++) {
		if (niska[i] >= 'A' && niska[i] <= 'z') { this->niska=this->niska+niska[i]; }//ignorisanje karaktera koji nisu u engl alfabetu
	}
}

int Rec::operator~() const
{
	char* temp;
	int br = 0;
	int size = sizeof(this->niska) / sizeof(this->niska[0]);
	
	int sizeTemp=0;
	int znSize = 0;
	int j = 0;
	char* zn=nullptr;
	temp = new char[size];
	for (int i = 0; i < this->niska.length(); i++) {
		temp[i] = this->niska[i];
		sizeTemp++;
	}
	for (int i = 0; i < sizeTemp; i++) {
		switch (temp[i])
		{
		case 'a':case 'e':case 'i':case 'o': case 'u': br++; break;
		case 'r': 
			
			j = 0;
			znSize = samoglasnici->gettreeSize(samoglasnici->getRoot());
			this->samoglasnici->getRoot()->clear();
			zn = this->samoglasnici->getZnakove(zn);
			while (j < znSize) {
				if (temp[i - 1] == zn[j] || temp[i + 1] == zn[j]) break;
				j++;
			}
			if (j == znSize)br++;
			break;
		case 'l':case 'n':
			if (temp[i - 1] == 'a' || temp[i - 1] == 'e' || temp[i - 1] == 'i' || temp[i - 1] == 'o' || temp[i - 1] == 'u' || temp[i + 1] == 'a' || temp[i + 1] == 'e' || temp[i + 1] == 'i' || temp[i + 1] == 'o' || temp[i + 1] == 'u' || temp[i + 1] == 'j') {
				break;
			}
			else { br++; }
			break;
		default:
			break;
		}
		
	}
	return br;
}

int Rec::operator()(int n) 
{
	char* temp;
	int br = 0;
	int size = sizeof(this->niska) / sizeof(this->niska[0]);
	int sizeTemp = 0;
	temp = new char[size];
	for (int i = 0; i < this->niska.length(); i++) {
		temp[i] = this->niska[i];
		sizeTemp++;
	}

	if (n == 0) {
		for (int i = 0; i < sizeTemp; i++) {
			switch (temp[i])
			{
			case 'a':case 'e':case 'i':case 'o': case 'u': return i;
			case 'r':
				if (temp[i + 1] == 'a' || temp[i + 1] == 'e' || temp[i + 1] == 'i' || temp[i + 1] == 'o' || temp[i + 1] == 'u') break;
				else return i;
			case 'l':case 'n': 
				if (temp[i + 1] == 'a' || temp[i + 1] == 'e' || temp[i + 1] == 'i' || temp[i + 1] == 'o' || temp[i + 1] == 'u' || temp[i + 1] == 'j') break;
				else return i;
			default:
				break;
			}
		}
	}
	else if (n > 0) {
		int check = 0;
		for (int i = 0; i < sizeTemp; i++) {
			switch (temp[i])
			{
			case 'a':case 'e':case 'i':case 'o': case 'u': 
				if (check == n) return i;
				check++;
				break;
			case 'r':
				
				if (temp[i + 1] == 'a' || temp[i + 1] == 'e' || temp[i + 1] == 'i' || temp[i + 1] == 'o' || temp[i + 1] == 'u' ||
					temp[i - 1] == 'a' || temp[i - 1] == 'e' || temp[i - 1] == 'i' || temp[i - 1] == 'o' || temp[i - 1] == 'u') break;
				else {
					if (check == n) return i;
					check++;
					break;
				}
			case 'l':case 'n':
				if (temp[i + 1] == 'a' || temp[i + 1] == 'e' || temp[i + 1] == 'i' || temp[i + 1] == 'o' || temp[i + 1] == 'u' || temp[i + 1] == 'j' ||
					temp[i - 1] == 'a' || temp[i - 1] == 'e' || temp[i - 1] == 'i' || temp[i - 1] == 'o' || temp[i - 1] == 'u') break;
				else {
					if (check == n) return i;
					check++;
					break;
				}
			default:
				break;
			}
		}
	}
	else {
		int check = -1;
		for (int i = sizeTemp-1; i >= 0; i--) {
			switch (temp[i])
			{
			case 'a':case 'e':case 'i':case 'o': case 'u':
				if (check == n) return i;
				check--;
				break;
			case 'r':

				if (temp[i + 1] == 'a' || temp[i + 1] == 'e' || temp[i + 1] == 'i' || temp[i + 1] == 'o' || temp[i + 1] == 'u' ||
					temp[i - 1] == 'a' || temp[i - 1] == 'e' || temp[i - 1] == 'i' || temp[i - 1] == 'o' || temp[i - 1] == 'u') break;
				else {
					if (check == n) return i;
					check--;
					break;
				}
			case 'l':case 'n':
				if (temp[i + 1] == 'a' || temp[i + 1] == 'e' || temp[i + 1] == 'i' || temp[i + 1] == 'o' || temp[i + 1] == 'u' || temp[i + 1] == 'j' ||
					temp[i - 1] == 'a' || temp[i - 1] == 'e' || temp[i - 1] == 'i' || temp[i - 1] == 'o' || temp[i - 1] == 'u') break;
				else {
					if (check == n) return i;
					check--;
					break;
				}
			default:
				break;
			}
		}
	}

	return -1;
}


bool operator^(Rec& r1, Rec& r2)
{
	int brSlog1 = 0, brSlog2 = 0;
	int brpoz1 = 0, brpoz2 = 0;
	brSlog1 = ~r1;
	brSlog2 = ~r2;
	if (brSlog1 == 1 || brSlog2 == 1) {
		brpoz1 = r1(-1);
		brpoz2 = r2(-1);
		if (r1.niska[brpoz1] == r2.niska[brpoz2]) {
			return true;
		}
		else return false;
	}
	else {
		brpoz1 = r1(-2);
		brpoz2 = r2(-2);
		if (r1.niska[brpoz1] == r2.niska[brpoz2]) {
			brpoz1 = r1(-1);
			brpoz2 = r2(-1);
			if (r1.niska[brpoz1] == r2.niska[brpoz2]) return true;
			else return false;
		}
	}
	return false;
}

istream& operator>>(istream& it, Rec& r)
{
	string pom;
	r.niska = "";
	it >> pom;
	for (int i = 0; i < pom.length(); i++) {
		if (pom[i] >= 'A' && pom[i] <= 'z') { r.niska = r.niska + pom[i]; }//throw neki karakteri ne pripadaju engl alfabetu
	}
	//it >> r.niska;
	return it;
}


ostream& operator<<(ostream& it, Rec& r)
{
	for (int i = 0; i < r.niska.length(); i++) {
		it << r.niska[i];
	}
	return it;
}
