// Definisane globalne funkcije iz Datum.h







#include "Datum.h"








// Ako je nepravilan datum, funkcija ga ispise pa baci izuzetak. Zasto? Da bi se znalo o kojem datumu se radi.
bool korektanDatum(int dan, int mjesec, int godina) {
	if (godina < 1800)
	{
		std::cout << dan << "." << mjesec << "." << godina << "." << " -- ";
		throw std::exception("Nepravilan unos godine! Godina mora biti veca od 1800! ");

	}
	if (mjesec == 1 || mjesec == 3 || mjesec == 5 || mjesec == 7 || mjesec == 8 || mjesec == 10 || mjesec == 12) {
		if (dan >= 1 && dan <= 31)
			return true;
		else
		{
			std::cout << dan << "." << mjesec << "." << godina << "." << " -- ";
			throw std::exception("Nepravilan unos dana! ");
		}
	}
	else if (mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11) {
		if (dan >= 1 && dan <= 30)
			return true;
		else
		{
			std::cout << dan << "." << mjesec << "." << godina << "." << " -- ";
			throw std::exception("Nepravilan unos dana!");
		}
	}
	else if (mjesec == 2) {
		if (prestupnaGodina(godina)) {
			if (dan >= 1 && dan <= 29)
				return true;
			else
			{
				std::cout << dan << "." << mjesec << "." << godina << "." << " -- ";
				throw std::exception("Nepravilan unos dana! ");
			}
		}
		else {
			if (dan >= 1 && dan <= 28)
				return true;
			else
			{
				std::cout << dan << "." << mjesec << "." << godina << "." << " -- ";
				throw std::exception("Nepravilan unos dana! ");
			}
		}
	}
	else {
		std::cout << dan << "." << mjesec << "." << godina << "." << " -- ";
		throw std::exception("Nepravilan unos mjeseca! ");
	}

	return true;
}


bool prestupnaGodina(int godina) noexcept
{
	if (godina % 100 != 0 && godina % 4 == 0 || godina % 400 == 0)
		return true;
	return false;
}


int vratiKolikoDanaImaMjesec(int mjesec, int godina) {
	switch (mjesec) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		return 31;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		return 30;
		break;
	}
	case 2:
		if (prestupnaGodina(godina))
			return 29;
		else
			return 28;
		break;
	default:
	{
		throw std::exception("Nepravilan unos mjeseca (u funkciji vratiKolikoDanaImaMjesec)! ");
		break;
	}

	}
}


void unosMjesecaIGodine(Datum& d)
{
	int mj, god;

	d.setDan(1);

	std::cout << "Unesite mjesec: " << std::endl;
	std::cin >> mj; d.setMjesec(mj);
	if (d.getMjesec() > 12 || d.getMjesec() < 1) throw std::exception("Pogressan unos mjeseca!");

	std::cout << "Unesite godinu: " << std::endl;
	std::cin >> god; d.setGodina(god);

	if (d.getGodina() < 1800) throw std::exception("Pogresan unos godine!");
}

