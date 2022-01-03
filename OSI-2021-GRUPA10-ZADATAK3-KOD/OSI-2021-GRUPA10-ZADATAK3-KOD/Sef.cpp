

#include <vector>

#include "Sef.h"
#include "Let.h"




void Sef::pregled_zavrsenih_letova_dnevno(Datum d)
{
	try {

		Let temp_let(0, "0", "0", 0, 0, 0, 0);

		fstream file;
		file.open(ZAVRSENI_LETOVI_FILEPATH, ios::in);
				

		if (!file) throw std::exception("Ne mogu otvoriti fajl 'ZAVRSENI_LETOVI' !");

		while (!file.eof())
		{	
			
			
		}

		file.close();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}
}



void Sef::pregled_rezervacija()
{
	try {

		fstream file;
		file.open(REZERVACIJE_FILEPATH, ios::in);
		string str;

		if (!file) throw std::exception("Ne mogu otvoriti fajl 'REZERVACIJE' !");

		while (!file.eof())
		{
			getline(file, str);

			cout << str << endl;
		}

		file.close();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}



bool prestupnaGodina(int godina)
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
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (prestupnaGodina(godina))
			return 29;
		else
			return 28;
		break;
	default:
		break;
	}
}

bool korektanDatum(int mjesec, int dan, int godina) {
	if (godina < 2010)
		throw std::exception("Godina mora biti veca od 2020");

	if (mjesec == 1 || mjesec == 3 || mjesec == 5 || mjesec == 7 || mjesec == 8 || mjesec == 10 || mjesec == 12) {
		if (dan >= 1 && dan <= 31)
			return true;
		else
			throw std::exception("Dani moraju biti izmedju 1 i 31!");
	}
	else if (mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11) {
		if (dan >= 1 && dan <= 30)
			return true;
		else
			throw std::exception("Dani moraju biti izmedju 1 i 30!");
	}
	else if (mjesec == 2) {
		if (prestupnaGodina(godina)) {
			if (dan >= 1 && dan <= 29)
				return true;
			else
				throw std::exception("Dani moraju biti izmedju 1 i 29");
		}
		else {
			if (dan >= 1 && dan <= 28)
				return true;
			else
				throw std::exception("Dani moraju biti izmedju 1 i 28");
		}
	}
	else {
		throw std::exception("Mjesec mora biti izmedju 1 i 12");
	}
}

Datum vratiDatum(Datum pocetniDatum) {
	//Datum rez;
	try {
		bool korDatum = korektanDatum(pocetniDatum.getMjesec(), pocetniDatum.getDan(), pocetniDatum.getGodina());
		int daniUMjesecu = vratiKolikoDanaImaMjesec(pocetniDatum.getMjesec(), pocetniDatum.getGodina());
		int noviDani = (pocetniDatum.getDan() + 7) % daniUMjesecu;

		if (noviDani % daniUMjesecu == 0)
			noviDani = daniUMjesecu;
		int noviMjesec;
		int novaGodina = pocetniDatum.getGodina();
		if (daniUMjesecu - pocetniDatum.getDan() < 7) {
			noviMjesec = pocetniDatum.getMjesec() + 1;
			novaGodina = pocetniDatum.getGodina();
			if (noviMjesec == 13) {
				noviMjesec = 1;
				novaGodina = pocetniDatum.getGodina() + 1;
			}
		}
		else {
			noviMjesec = pocetniDatum.getMjesec();
			novaGodina = pocetniDatum.getGodina();
		}
		Datum rez(noviDani, noviMjesec, novaGodina);
		return rez;
	}
	catch (const std::exception& e) {
		Datum rez;
		std::cout << e.what() << std::endl;
		return rez;
	}
}