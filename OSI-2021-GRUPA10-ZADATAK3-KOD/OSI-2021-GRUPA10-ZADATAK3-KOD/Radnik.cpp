#include "Radnik.h"
#include <iostream>

Radnik::Radnik(std::string korisnickoIme, std::string lozinka, std::string radnoMjesto) : korisnickoIme(korisnickoIme),
lozinka(lozinka), radnoMjesto(radnoMjesto) {}

std::string Radnik::getIme() const {
	return this->korisnickoIme;
}

std::string Radnik::getLozinka() const {
	return this->lozinka;
}

std::string Radnik::getradnoMjesto() const {
	return this->radnoMjesto;
}

bool Radnik::getSuspendovan() const {
	return  this->suspendovan;
}

void Radnik::setSuspendovan(bool suspenzija) {
	this->suspendovan = suspenzija;
}

/*bool Radnik::operator==(const Radnik& other) const {
	if (this->korisnickoIme == other.korisnickoIme && this->lozinka == other.lozinka)
		return true;

	return false;
}*/

std::ostream& operator<<(std::ostream& os, const Radnik& r) {
	os << r.korisnickoIme << ", " << r.radnoMjesto << std::endl;
	return os;
}