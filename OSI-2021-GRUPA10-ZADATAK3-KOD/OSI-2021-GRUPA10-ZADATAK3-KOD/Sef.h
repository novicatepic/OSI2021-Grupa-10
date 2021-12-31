#pragma once


#include <exception>
#include <iostream>
#include <fstream>		
#include <string>		//getline()

#include "Radnik.h"



#define ZAVRSENI_LETOVI_FILEPATH  "./LETOVI/ZAVRSENI_LETOVI.txt"
#define REZERVACIJE_FILEPATH	  "./LETOVI/REZERVACIJE.txt"


class Sef : virtual public Radnik
{
private:


public:
	Sef(std::string username, std::string pass) : Radnik(username, pass, "Sef") {}

	void pregled_zavrsenih_letova();
	void pregled_rezervacija();

};
