#include"Katren.h"
bool Katren::operator*() const
{
	this->tek = this->prvi->next;
	if (*this->prvi->s ^ *this->poslednji->s && *this->tek->s ^ *this->tek->next->s) return true;
	return false;
}
