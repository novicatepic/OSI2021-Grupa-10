#pragma once
#include <iostream>
#include "Radnik.h"

class Administrator :virtual public Radnik {
private:

public:
	Administrator(std::string korisnickoIme, std::string lozinka);
	void dodajRadnika();
	void suspendujRadnika();
	void obrisiRadnika();
	void pregledRadnika();
	bool provjeriIme(std::string ime);
};