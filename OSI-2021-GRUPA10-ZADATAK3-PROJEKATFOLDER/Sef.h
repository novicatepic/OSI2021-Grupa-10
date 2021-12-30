#pragma once


#include <exception>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <iomanip>

#include "Radnik.h"



#define FILEPATH "/LETOVI/ZAVRSENI_LETOVI"


class Sef : virtual public Radnik
{
private:


public:
	Sef(std::string username, std::string pass) : Radnik(username, pass, "Sef") {}

	void pregled_zavrsenih_letova();
	void pregled_rezervacija();

};
