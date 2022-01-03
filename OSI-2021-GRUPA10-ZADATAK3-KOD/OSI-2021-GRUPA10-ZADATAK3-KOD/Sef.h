#pragma once


#include <exception>
#include <fstream>		
#include <string>		//getline()


#include "Radnik.h"
#include "Datum.h"


#define ZAVRSENI_LETOVI_FILEPATH  "./LETOVI/ZAVRSENI_LETOVI.txt"
#define REZERVACIJE_FILEPATH	  "./LETOVI/REZERVACIJE.txt"


class Let;


using namespace std;



class Sef : virtual public Radnik
{
private:


public:
	Sef(string username, string pass) : Radnik(username, pass, "Sef") {}
	
	// Prikazuje sve zavrsene letove na uneseni datum
	void pregled_zavrsenih_letova_dnevno(Datum);

	// Prikazuje sve zavrsene letove u 7 dana, pocevsi od unesenog datuma
	void pregled_zavrsenih_letova_sedmicno(Datum);

	// Prikazuje sve zavrsene letove u narednih mjesec dana, pocevsi od unesenog datuma
	void pregled_zavrsenih_letova_mjesecno(Datum);


	void pregled_rezervacija();

};



bool prestupnaGodina(int godina);

int vratiKolikoDanaImaMjesec(int mjesec, int godina);

bool korektanDatum(int mjesec, int dan, int godina);

Datum vratiDatum(Datum pocetniDatum);