#include "Radnik.h"
#include "Sef.h"
#include "Administrator.h"
#include "Kontrolor.h"
#include "Operater.h"
#include "KorisnickaDokumentacijaIPomocneFunkcije.h"
#include "Datum.h"
#include "Let.h"
#include <iostream>
#include <string>
#include <fstream>

int main() {
	//LOGIKA KOJOM CEMO RADITI KASNIJE
	auto citajFajl = std::ifstream("radnici.dat", std::ios::binary);
	if (citajFajl) {
		pomocnaFunkcijaPriPrijavljivanju();
	}
	else {
		auto pisiUFajl = std::ofstream("radnici.dat", std::ios::binary | std::ios::app);
		std::string korisnickoIme, lozinka;
		std::cout << "Prvo ocitavanje fajla : privremeni admin napravljen!" << std::endl;
		std::cout << "Unesite korisnicko ime i lozinku za prvog admina u sistemu: " << std::endl;
		std::cout << "Unesite korisnicko ime: " ;
		std::cin >> korisnickoIme;
		std::cout << "Unesite lozinku: ";
		std::cin >> lozinka;
		Radnik r(korisnickoIme, lozinka, "Administrator");
		pisiUFajl.write((char*)&r, sizeof(Radnik));
		pisiUFajl.close();
		pisiNoveRedove();
		//Administrator a(korisnickoIme, lozinka);
		//std::string unosOpcije;
		pomocnaFunkcijaPriPrijavljivanju();
	}


	//TEST KAKO BI TO TREBALO IZGLEDATI
	/*auto pisiUFajl = std::ofstream("radnici.dat", std::ios::binary);
	if (pisiUFajl) {
		std::string korisnickoIme = "Novica", lozinka = "12345";
		std::cout << "Unesite korisnicko ime" << std::endl;
		std::cin >> korisnickoIme;
		std::cout << "Unesite lozinku" << std::endl;
		std::cin >> lozinka;

		Radnik r2("Novica", "12345", "Administrator");
		Radnik r3("Marko", "42212", "Sef");
		Radnik r4("Janko", "2123", "Operater");
		pisiUFajl.write((char*)&r4, sizeof(Radnik));
		pisiUFajl.write((char*)&r2, sizeof(Radnik));
		pisiUFajl.write((char*)&r3, sizeof(Radnik));
		pisiUFajl.close();
		Radnik r;
		r = prijaviNaSistem(korisnickoIme, lozinka);
		if (r.getIme() != "")
			std::cout << r << std::endl;
		if (r.getSuspendovan() == true) {
			//SUSPENDOVAN JE
		}
		else {
			//NIJE SUSPENDOVAN, DOZVOLJENE FUNKCIONALNOSTI
		}

		pisiUFajl.close();
	}*/

	/*Datum d(5, 4, 2021);
	Datum d2(1, 1, 2022);
	char upomoc = ',';
	std::string temp3 = "JopeZoran";
	std::string temp2 = "Zoran";

	auto probaFajl = std::ofstream("temp.txt");
	probaFajl << temp3;
	probaFajl << upomoc;
	probaFajl << d;
	probaFajl << upomoc;
	probaFajl << temp2;
	probaFajl.close();
	auto ispisFajl = std::ifstream("temp.txt");
	Datum tempDatum;
	std::getline(ispisFajl, temp3, upomoc);
	ispisFajl >> d;
	ispisFajl.ignore();
	std::getline(ispisFajl, temp2);
	ispisFajl.ignore();
	std::cout << temp3 << std::endl;
	std::cout << d;
	std::cout << temp2 << std::endl;
	std::cout << d.getDan() << std::endl;

	ispisFajl.close();*/

	//Datum d(27, 12, 2021);
	//Datum nadji = vratiDatum(d);
	//std::cout << nadji;

	//PRIKAZ ZA ZORANA, KAKO SE KORISTE LETOVI
	/*auto upis = std::ofstream("proba.txt", std::ios::in);
	Let l;
	upis << l;
	upis << l;
	upis.close();
	auto citaj = std::ifstream("proba.txt", std::ios::out);
	l.ucitajLet(citaj);
	l.ispisi_let();
	l.ucitajLet(citaj);
	l.ispisi_let();*/

	//OVAKO CE SE RADITI SA VREMENOM
	/*std::string vrijeme = "20";
	std::string minute = "-2";
	//std::cout << vrijeme[0];
	if (minute < "0" || minute > "60")
		std::cout << "Neispravan unos" << std::endl;
	std::string vr;
	int br = std::stoi(vrijeme);
	std::string rez = vrijeme + ":" + minute;
	std::cout << rez << std::endl;*/

	return 0;
}