



#pragma once


#include <iomanip>
#include <fstream>

#include "Datum.h"


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

	inline int getID() const noexcept;
	inline string getVrijeme_polijetanja() const noexcept;
	inline string getVrijeme_slijetanja() const noexcept;
	inline Datum getDatum() const noexcept;
	inline string getOpis() const noexcept;
	inline int getBr_mjesta() const noexcept;
	inline int getBr_slobodnih_mjesta() const noexcept;


	void setID(int id) noexcept;
	void setVrijeme_polijetanja(string) noexcept;
	void setVrijeme_slijetanja(string) noexcept;
	void setDatum(Datum) noexcept;
	void setDatum(int, int, int) noexcept;
	void setOpis(string) noexcept;
	void setBr_mjesta(int) noexcept;
	void setBr_slobodnih_mjesta(int) noexcept;

	void ispisi_let() const noexcept;
	void ucitajLet(ifstream&) noexcept;
	friend std::istream& operator>>(std::istream&, Let&) noexcept;
	friend std::ostream& operator<<(std::ofstream&, const Let&) noexcept;








	bool pomocZaOperatera(std::string id);
};