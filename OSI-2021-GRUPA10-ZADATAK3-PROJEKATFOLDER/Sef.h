#pragma once


#include <exception>
#include <iostream>

#include "Radnik.h"


#define FOLDERNAME_ZAVRSENI_LETOVI	"LETOVI"
#define FOLDERNAME_RESERVACIJE		"REZERVACIJE"



class Sef : virtual public Radnik
{
private:


public:
	Sef(std::string username, std::string pass) { Radnik(username, pass); }

	void pregled_zavrsenih_letova();
	void pregled_rezervacija();

};
