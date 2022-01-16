#pragma once





#include <exception>
#include <fstream>		
#include <string>		


#include "Radnik.h"
#include "Datum.h"


#define ZAVRSENI_LETOVI_FILEPATH  "./LETOVI/ZAVRSENI_LETOVI.txt"
#define REZERVACIJE_FILEPATH	  "./REZERVACIJE"


class Let;

using namespace std;



class Sef : virtual public Radnik
{
public:
	Sef(string username, string pass) : Radnik(username, pass, "Sef") {}
	

	// Nudi opciju da se izabere dnevni, sedmicni ili mjesecni pregled pa ispise letove u skladu sa izborom
	void pregledZavrsenihLetova() const;

	void pregledRezervacija() const;

private:

	// Prikazuje sve zavrsene letove na uneseni datum - Poziva se iz  pregledZavrsenihLetova();
	void pregledZavrsenihLetovaDnevno(Datum) const;

	// Prikazuje sve zavrsene letove u sedmici koja pocinje unesenim datumom - Poziva se iz  pregledZavrsenihLetova();
	void pregledZavrsenihLetovaSedmicno(Datum) const;

	// Prikazuje sve zavrsene letove u mjesecu koji pocinje unesenim datumom - Poziva se iz pregledZavrsenihLetova();
	void pregledZavrsenihLetovaMjesecno(Datum) const;



};

// Vraca 7 dana kasnije od pocetnogDatuma, uz sve provjere
Datum sedamDanaKasnije(Datum pocetniDatum);