



#include "Sef.h"
#include "Let.h"




void Sef::pregledZavrsenihLetova()
{
	try {

		char izbor;
		Datum datum;

		cout << "Unesite zeljenu opciju: "<< endl;
		cout << "Dnevni prikaz   (prikaz svih letova koji su zavrseni na dan koji cete unijeti)                  - unesite 'd' " << endl;
		cout << "Sedmicni prikaz (prikaz svih letova u periodu od 7 dana, pocevsi od datuma kojeg cete unijeti)  - unesite 's' " << endl;
		cout << "Mjesecni prikaz (prikaz svih letova zavrsenih u mjesecu kojeg cete unijeti)                     - unesite 'm' " << endl;

		cin >> izbor;

		if (izbor == 'd')
		{

			cout << "-- Unos datuma -- " << endl; cin >> datum;
		
			korektanDatum(datum.getDan(), datum.getMjesec(), datum.getGodina());
			this->pregledZavrsenihLetovaDnevno(datum);

		}
		else if (izbor == 's')
		{

			cout << "-- Unos datuma (pocetak sedmice) -- " << endl; cin >> datum;
			
			korektanDatum(datum.getDan(), datum.getMjesec(), datum.getGodina());
			this->pregledZavrsenihLetovaSedmicno(datum);
			
		}
		else if (izbor == 'm')
		{

			cout << "-- Unos datuma -- " << endl;  unosMjesecaIGodine(datum);
			
			korektanDatum(datum.getDan(), datum.getMjesec(), datum.getGodina());
			this->pregledZavrsenihLetovaMjesecno(datum);
			

		}
		else throw std::exception("  Pogresan odabir!  ");

		
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}


}



void Sef::pregledZavrsenihLetovaDnevno(Datum dan)
{
	Let temp_let;

	ifstream file;
	file.open(ZAVRSENI_LETOVI_FILEPATH, ios::in);


	if (!file) throw std::exception("Ne mogu otvoriti fajl 'ZAVRSENI_LETOVI' !");


	cout << "                                 -------------------------------  Dnevni izvjestaj za dan: " << dan << "  -------------------------------" << endl;
	cout << "|  ID  |  Vrijeme polijetanja  |  Vrijeme slijetanja  |  Datum polaska  |             Ruta             |  Ukupan broj mjesta  |  Broj slobodnih mjesta  | " << endl;

	while (!file.eof())
	{
		temp_let.ucitajLet(file);

		if (temp_let.getDatum() > dan) break;							// * * *   I Z B R I S A T I   A K O   L E T O V I   U   F A J L U   N I S U   S O R T I R A N I (1/3)    * * *
																		// Fajl sa letovima je sortiran po datumu, tako da kad se dodje do prvog datuma veceg od dan - prekidaj

		if (temp_let.getDatum() == dan)
			temp_let.ispisi_let();
	}

	cout << "                                 ------------------------------------------------------------------------------------------------------" << endl;

	file.close();
}




void Sef::pregledZavrsenihLetovaSedmicno(Datum dan)
{
	Let temp_let;
	Datum plusSedamDana = sedamDanaKasnije(dan);

	ifstream file;
	file.open(ZAVRSENI_LETOVI_FILEPATH, ios::in);


	if (!file) throw std::exception("Ne mogu otvoriti fajl 'ZAVRSENI_LETOVI' !");


	cout << "                                 ---------  Sedmicni izvjestaj za sedmicu: " << dan << " - " << plusSedamDana << "  ---------" << endl;
	cout << "|  ID  |  Vrijeme polijetanja  |  Vrijeme slijetanja  |  Datum polaska  |             Ruta             |  Ukupan broj mjesta  |  Broj slobodnih mjesta  | " << endl;

	while (!file.eof())
	{
		temp_let.ucitajLet(file);

		if (temp_let.getDatum() >= plusSedamDana) break;								// * * *   I Z B R I S A T I   A K O   L E T O V I   U   F A J L U   N I S U   S O R T I R A N I (2/3)    * * *
																						// Fajl sa letovima je sortiran po datumu, tako da kad se dodje do prvog datuma veceg od dan+7 - prekidaj.

		if(temp_let.getDatum()>= dan && temp_let.getDatum() < plusSedamDana)			// Ako je izmedju ucitanog dana i dan+7 - ispisi.
			temp_let.ispisi_let();
	}

	cout << "                                 ------------------------------------------------------------------------------" << endl;

	file.close();
}




void Sef::pregledZavrsenihLetovaMjesecno(Datum dan)
{
	Let temp_let;

	ifstream file;
	file.open(ZAVRSENI_LETOVI_FILEPATH, ios::in);


	if (!file) throw std::exception("Ne mogu otvoriti fajl 'ZAVRSENI_LETOVI' !");


	cout << "                                 ----------------------  Mjesecni izvjestaj za: " << dan.getMjesec() << ". mjesec  ----------------------" << endl;
	cout << "|  ID  |  Vrijeme polijetanja  |  Vrijeme slijetanja  |  Datum polaska  |             Ruta             |  Ukupan broj mjesta  |  Broj slobodnih mjesta  | " << endl;

	while (!file.eof())
	{
		temp_let.ucitajLet(file);

		if (temp_let.getDatum().getGodina() > dan.getGodina() ||															// * * *   I Z B R I S A T I   A K O   L E T O V I   U   F A J L U   N I S U   S O R T I R A N I (3/3)    * * *
			(temp_let.getDatum().getGodina() == dan.getGodina() && temp_let.getDatum().getMjesec() > dan.getMjesec()))		// Fajl sa letovima je sortiran po datumu, tako da cim se dodje
			break;																											// do datuma sa vecom godinom ili do datuma sa istom godinom a 
																															// vecim mjesecom - prekidaj

		if (temp_let.getDatum().getMjesec() == dan.getMjesec() && temp_let.getDatum().getGodina() == dan.getGodina())
			temp_let.ispisi_let();
	}

	cout << "                                 ---------------------------------------------------------------------------------" << endl;

	file.close();
}



void Sef::pregledRezervacija()
{
	try {

		fstream file;
		file.open(REZERVACIJE_FILEPATH, ios::in);
		string str;

		if (!file) throw std::exception("Ne mogu otvoriti fajl 'REZERVACIJE' !");




		file.close();
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}
}



Datum sedamDanaKasnije(Datum pocetniDatum) {
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


