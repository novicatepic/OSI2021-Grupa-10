#pragma once
#include <iostream>
#include "Radnik.h"

class Administrator :virtual public Radnik {
private:

public:
	Administrator(std::string korisnickoIme, std::string lozinka);
	bool dodajRadnika();
	bool suspendujRadnika(Radnik r);
	void obrisiRadnika();
	void pregledRadnika();
};