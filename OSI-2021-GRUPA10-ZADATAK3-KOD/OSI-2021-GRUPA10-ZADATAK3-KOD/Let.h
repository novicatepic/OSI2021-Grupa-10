#pragma once


#include <iomanip>

#include "Datum.h"

#include <fstream>

using namespace std;


class Let
{
	int ID;
	string vrijeme_polijetanja;
	string vrijeme_slijetanja;
	Datum datum;
	string opis;
	int br_mjesta;
	int br_slobodnih_mjesta;

public:

	Let(int id, string vr_p, string vr_s, Datum d, string op, int br1, int br2)
		: ID(id), vrijeme_polijetanja(vr_p), vrijeme_slijetanja(vr_s), datum(d), opis(op), br_mjesta(br1), br_slobodnih_mjesta(br2) {}

	Let() : ID(0), vrijeme_polijetanja("xxx"), vrijeme_slijetanja("xxx"), datum(0, 0, 0), opis("xxx"), br_mjesta(0), br_slobodnih_mjesta(0) {}

	inline int getID() const;
	inline string getVrijeme_polijetanja() const;
	inline string getVrijeme_slijetanja() const;
	inline Datum getDatum() const;
	inline string getOpis() const;
	inline int getBr_mjesta() const;
	inline int getBr_slobodnih_mjesta() const;


	void setID(int id);
	void setVrijeme_polijetanja(string);
	void setVrijeme_slijetanja(string);
	void setDatum(Datum);
	void setDatum(int, int, int);
	void setOpis(string);
	void setBr_mjesta(int);
	void setBr_slobodnih_mjesta(int);

	void ispisi_let() const;
	void ucitajLet(ifstream&);
	friend std::istream& operator>>(std::istream&, Let&);
	friend std::ostream& operator<<(std::ofstream&, const Let&);
};