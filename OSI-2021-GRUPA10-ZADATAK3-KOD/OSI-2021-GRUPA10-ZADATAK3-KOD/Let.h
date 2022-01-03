#pragma once



#include "Datum.h"



class Let
{
	int ID;
	std::string vrijeme_polijetanja;
	std::string vrijeme_slijetanja;
	Datum datum;
	std::string opis;
	int br_mjesta;
	int br_slobodnih_mjesta;

public:

	Let(int id, std::string vr_p, std::string vr_s, Datum d, std::string op, int br1, int br2)
		: ID(id), vrijeme_polijetanja(vr_p), vrijeme_slijetanja(vr_s), datum(d), opis(op), br_mjesta(br1), br_slobodnih_mjesta(br2) {}

	int getID() const;
	inline std::string getVrijeme_polijetanja() const;
	inline std::string getVrijeme_slijetanja() const;
	inline Datum getDatum() const;
	inline std::string getOpis() const;
	inline int getBr_mjesta() const;
	inline int getBr_slobodnih_mjesta() const;


};