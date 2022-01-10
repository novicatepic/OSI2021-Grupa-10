#pragma once





#include <exception>
#include <fstream>
#include <iostream>
#include <string>		
#include <filesystem>

#include "Radnik.h"
#include "Datum.h"



#define ZAVRSENI_LETOVI_FILEPATH  "./LETOVI/ZAVRSENI_LETOVI.txt"
#define REZERVACIJE_FILEPATH	  "./REZERVACIJE"


class Let;




class Sef : virtual public Radnik
{
public:
	Sef(std::string username, std::string pass) : Radnik(username, pass, "Sef") {}
	

	// Nudi opciju da se izabere dnevni, sedmicni ili mjesecni pregled pa ispise letove u skladu sa izborom
	void pregledZavrsenihLetova();

	// Ispise sve rezervacije (nazive fajlova u REZERVACIJE)
	void pregledRezervacija();

private:

	// Prikazuje sve zavrsene letove na uneseni datum - Poziva se iz  pregledZavrsenihLetova();
	void pregledZavrsenihLetovaDnevno(Datum);

	// Prikazuje sve zavrsene letove u sedmici koja pocinje unesenim datumom - Poziva se iz  pregledZavrsenihLetova();
	void pregledZavrsenihLetovaSedmicno(Datum);

	// Prikazuje sve zavrsene letove u mjesecu koji pocinje unesenim datumom - Poziva se iz pregledZavrsenihLetova();
	void pregledZavrsenihLetovaMjesecno(Datum);


};

// Vraca 7 dana kasnije od pocetnogDatuma uz sve provjere
Datum sedamDanaKasnije(Datum pocetniDatum);