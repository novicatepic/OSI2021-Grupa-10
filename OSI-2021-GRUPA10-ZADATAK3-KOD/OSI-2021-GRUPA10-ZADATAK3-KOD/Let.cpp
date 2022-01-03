



#include "Let.h"



int Let::getID() const
{
	return ID;
}

std::string Let::getVrijeme_polijetanja() const
{
	return vrijeme_polijetanja;
}

std::string Let::getVrijeme_slijetanja() const
{
	return vrijeme_slijetanja;
}

Datum Let::getDatum() const
{
	return datum;
}

std::string Let::getOpis() const
{
	return opis;
}

int Let::getBr_mjesta() const
{
	return br_mjesta;
}

int Let::getBr_slobodnih_mjesta() const
{
	return br_slobodnih_mjesta;
}
