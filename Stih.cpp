#include"Stih.h"
void Stih::operator+=(Rec& r) const
{
	poslednji = (!prvi ? prvi : poslednji->next) = new Elem(r);
	br++;
}

void Stih::brisi()
{
	while (this->prvi) {
		Elem* stari = prvi;
		prvi = prvi->next;
		delete stari;
	}
	poslednji = tek = nullptr;
}

void Stih::kopiraj(const Stih& s)
{
	prvi = poslednji = tek = nullptr;
	for (Elem* temp = s.prvi; temp; temp = temp->next) {
		poslednji = (!prvi ? prvi : poslednji->next) = new Elem(*temp->r);
		br++;
	}
}

void Stih::operator()(Rec& r, int ind)
{
	int counter = 0;
	Elem* temp = this->prvi;
	Elem* temp2 = this->prvi;
	while (counter < ind && temp) {
		temp = temp->next;
		counter++;
	}
	if (!temp && counter==ind) *this+=r;
	else if (!temp) { cout << "Izvan opsega,nemoguce dodati rec na tu poziciju" << endl; }
	else if (temp == this->prvi) {
		Elem* p = new Elem(r);
		p->next = temp;
		this->prvi = p;
		this->br++;
	}
	else {
		while (temp2->next != temp) {
			temp2 = temp2->next;
		}
		Elem* p = new Elem(r);
		temp2->next = p;
		p->next = temp;
		this->br++;
	}
}

void Stih::operator()(int ind)
{
	int counter = 0;
	Elem* temp = this->prvi;
	Elem* temp2 = this->prvi;
	while (counter<ind && temp) {
		temp = temp->next;
		counter++;
	}
	if (!temp)cout << "izvan opsega";
	else {
		while (temp2->next != temp) {
			temp2 = temp2->next;
		}
		temp2->next = temp->next;
		delete temp;
	}
}

int Stih::operator+() const
{
	int counter=0;
	Elem* temp = this->prvi;
	while ( temp) {
		counter = counter + (temp->r->operator+());
		temp=temp->next;
	}
	return counter;
}

Stih::~Stih()
{
	brisi();
}


int Stih::operator~() const
{
	int counter = 0;
	Elem* temp = this->prvi;
	while (temp) {
		counter = counter + (temp->r->operator~());
		temp = temp->next;
	}
	return counter;
}

Rec* Stih::operator[](int ind) const
{
	int counter = 0;
	Elem* temp = this->prvi;
	while (temp) {
		if (counter == ind) return temp->r;
		counter = counter + 1;
		temp = temp->next;
	}
	return nullptr;
}

bool operator^(Stih& s1, Stih& s2)
{
	int poz1 = s1.br - 2;
	int poz2 = s2.br - 2;
	int counter = 0, counter2 = 0;
	s1.tek = s1.prvi; s2.tek = s2.prvi;
	while (s1.tek && s2.tek) {
		if (counter == poz1 && counter2 == poz2) {
			if ((*s1.tek->r ^ *s2.tek->r)) {
				//counter++; counter2++;
				s1.tek = s1.tek->next;
				s2.tek = s2.tek->next;
				if ((*s1.tek->r ^ *s2.tek->r)) return true;
				else return false;
			}
			else return false;
		}
		else if (counter == poz1) { counter2++; s2.tek = s2.tek->next; }
		else { counter++; s1.tek = s1.tek->next;}
	}
	return false;
}

istream& operator>>(istream& it, Stih& s)
{
	string pom,pom2="";
	//it >> pom;
	getline(it, pom);
	for (int i = 0; i < pom.length(); i++) {
		if (pom[i] != ' ')pom2 += pom[i];
		else {

			s.operator+=(*(new Rec(pom2)));
			pom2 = "";
		}
	}
	s.operator+=(*(new Rec(pom2)));
	pom2 = "";
	return it;
}

ostream& operator<<(ostream& it, Stih& s)
{
	s.tek = s.prvi;
	while (s.tek) {
		it << *s.tek->r;
		if (s.tek->next) it << " ";
		s.tek = s.tek->next;
	}
	
	return it;
}
