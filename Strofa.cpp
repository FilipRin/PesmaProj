#include"Strofa.h"
void Strofa::brisi()
{
	while (this->prvi) {
		Elem* stari = prvi;
		prvi = prvi->next;
		delete stari;
	}
	poslednji = tek = nullptr;
}
void Strofa::kopiraj(const Strofa& st)
{
	prvi = poslednji = tek = nullptr;
	for (Elem* temp = st.prvi; temp; temp = temp->next) {
		poslednji = (!prvi ? prvi : poslednji->next) = new Elem(*temp->s);
	}
}
void Strofa::pisi(ostream& it) const
{
	tek = prvi;
	while (tek) {
		it << *tek->s << endl;
		tek=tek->next;
	}
}
void Strofa::operator+=(Stih& stih)
{
	if (this->br == this->kap) cout << "Nece se dodati stih, strofa je puna" << endl;
	else if (this->br == 0) {
		poslednji = (!prvi ? prvi : poslednji->next) = new Elem(*stih.kopija());
		br++;
	}
	else {
		Elem* temp = this->prvi;
		if (temp->s->operator~() == ~stih) {
			poslednji = (!prvi ? prvi : poslednji->next) = new Elem(*stih.kopija());
			br++;
		}
		else { cout << "Broj slogova stihova u strofi nije isti sa slogovima navedenog stiha, nece se dodati navedeni stih" << endl; }
	}

}

void Strofa::operator-()
{
	Elem* temp = this->prvi;
	if (!this->prvi) { cout << "Prazna strofa, nema sta da se brise!" << endl; }
	else if (this->prvi == this->poslednji && this->prvi) {
		this->prvi = nullptr;
		this->poslednji = nullptr;
		delete temp;
	}
	else {
		while (temp->next != poslednji) {
			temp = temp->next;
		}
		this->poslednji = temp;
		temp = temp->next;
		this->poslednji->next = nullptr;
		delete temp;
	}
	
}

int Strofa::operator+() const
{
	int counter = 0;
	Elem* temp = this->prvi;
	while (temp) {
		counter += temp-> s->operator+();
		temp = temp->next;
	}
	return counter;
}

Stih* Strofa::operator[](int ind) const
{
	int counter = 0;
	Elem* temp = this->prvi;
	while (temp) {
		if (counter == ind) return temp->s;
		counter = counter + 1;
		temp = temp->next;
	}
	return nullptr;
}

void Strofa::operator()(int i, int j)
{
	Elem* p1 = this->prvi;
	//Elem* p2 = this->prvi->next;
	if (this->br > 1) {
		if (i != j) {
			if (i != 0  && j != 0 ) {
				Elem* tempi = this->prvi;
				Elem* tempj = tempi;

				int bri = 0;
				int brj = 0;
				while (p1) {
					if (bri < i) bri++;
					else tempi = p1;
					if (brj < j) brj++;
					else tempj = p1;
					p1->next;
				}

				Elem* finder1 = this->prvi;
				Elem* finder2 = finder1;
				while (1) {
					if (finder1->next != tempi) finder1 = finder1->next;
					if (finder2->next != tempj) finder2 = finder2->next;
					if (finder1->next == tempi && finder2->next == tempj) break;
				}

				finder1->next = tempi->next;
				tempi->next = tempj->next;
				//tempj->next = tempi;
				finder2->next = tempi;//prvi stih prebacen na mesto drugog
				if (tempi->next == nullptr) this->poslednji = tempi;
				tempj->next = finder1->next;
				finder1->next = tempj;
			}
			else if (i == 0 || j == 0) {
				Elem* tempi = this->prvi;
				Elem* tempj = this->prvi;

				int brj = 0;
				while (p1) {
					if (i == 0) {
						if (brj < j) brj++;
						else tempj = p1;
						p1->next;
					}
					else {
						if (brj < i) brj++;
						else tempj = p1;
						p1->next;
					}
				}
				Elem* finder1 = this->prvi;
				while (finder1->next != tempj) {
					finder1=finder1->next;
				}
				finder1->next = tempj->next;
				tempj->next = tempi->next;
				this->prvi = tempj;
				tempi->next = finder1->next;
				finder1->next = tempi;
				if (tempi->next == nullptr) this->poslednji = tempi;
			}
		}
	}
	else {
		cout << "Ne moze se izvrsiti f-ja jer nema dovoljno stihova" << endl;
	}
}

ostream& operator<<(ostream& it, Strofa& st)
{
	st.pisi(it);
	return it;
}
