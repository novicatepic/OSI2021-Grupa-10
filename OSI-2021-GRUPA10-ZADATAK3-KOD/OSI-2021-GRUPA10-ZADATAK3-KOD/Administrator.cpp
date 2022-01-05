#include "Administrator.h"
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>

Administrator::Administrator(std::string korisnickoIme, std::string lozinka) : Radnik(korisnickoIme, lozinka, "Administrator") {}


bool Administrator::dodajRadnika(){
	auto pisiUFajl = std::ofstream("radnici.dat", std::ios::binary | std::ios::app);
	if (pisiUFajl) {
		std::string korisnickoIme, lozinka, radnoMjesto;
		
		std::cout << "Dodajete podatke o korisniku:" << std::endl;
		std::cout << "(Napomena: Unositi tip radnog mjesta sa pocetnim velikim slovom!)" << std::endl;
		std::cout << "Korisnicko ime: "; std::cin >> korisnickoIme;
		std::cout << "Lozinka: "; std::cin >> lozinka;
		do
		{
			std::cout << "Radno mjesto: "; std::cin >> radnoMjesto;

		}while ((radnoMjesto != "Sef" && radnoMjesto != "Administrator" && radnoMjesto!= "Kontrolor"
			&& radnoMjesto != "Operater"));
		Radnik r(korisnickoIme,lozinka, radnoMjesto);
		pisiUFajl.write((char*)&r, sizeof(Radnik));

		pisiUFajl.close();
		return true;
	}
	else {
		return false;
	}
}

void Administrator::obrisiRadnika() {

	std::string korisnickoIme;
	std::string lozinka;
	std::cout << "Unesite korisnicko ime radnika ciji nalog zelite da obrisete: " << std::endl;
	std::cin >> korisnickoIme;
	std::cout << "Unesite lozinku radnika ciji nalog zelite da obrisete: " << std::endl;
	std::cin >> lozinka;

	std::ifstream ocitavanje;
	std::ofstream upisivanje;

	ocitavanje.open("radnici.dat", std::ios::binary | std::ios::in);

	if (ocitavanje) {
		Radnik* r = new Radnik;
		while (ocitavanje.good()) {
			r = new Radnik;
			ocitavanje.read((char*)r, sizeof(Radnik));
			if (r->getIme() == korisnickoIme && r->getLozinka() == lozinka) {
				ocitavanje.close();
				break;
			}
		}

		if (r->getIme() != "") {
			auto upis = std::ofstream("temp.dat", std::ios::binary | std::ios::out | std::ios::app);
			auto citanje = std::ifstream("radnici.dat", std::ios::binary | std::ios::in);
			if (citanje) {

				while (citanje.good()) {
					Radnik* t = new Radnik;
					citanje.read((char*)t, sizeof(Radnik));
					if (t->getIme() != r->getIme()) {
						upis.write((char*)t, sizeof(Radnik));
					}
				}
				citanje.close();
				upis.close();
				remove("radnici.dat");
				rename("temp.dat", "radnici.dat");
			}
		}
	}
}


void Administrator::suspendujRadnika() {
	std::string korisnickoIme;
	int suspenzija;
	std::cout << "Unesite korisnicko ime radnika ciji nalog zelite da suspendujete:" << std::endl;
	std::cin >> korisnickoIme;
	std::cout << "Unesite 1 ili 0 da suspendujete ili uklonite suspenziju:" << std::endl;
	std::cin >> suspenzija;

	std::ifstream ocitavanje;

	ocitavanje.open("radnici.dat", std::ios::binary | std::ios::in);

	if (ocitavanje) {
		Radnik* r = new Radnik;
		while (ocitavanje.good()) {
			r = new Radnik;
			ocitavanje.read((char*)r, sizeof(Radnik));
			if (r->getIme() == korisnickoIme) {
				ocitavanje.close();
				break;
			}
		}
		if (suspenzija == 1) {
			r->setSuspendovan(true);
		}
		else if(suspenzija==0) {
			r->setSuspendovan(false);
		}

		if (r->getIme() != "") {
			auto upis = std::ofstream("temp.dat", std::ios::binary | std::ios::out | std::ios::app);
			auto citanje = std::ifstream("radnici.dat", std::ios::binary | std::ios::in);
			if (citanje) {

				while (citanje.good()) {
					Radnik* t = new Radnik;
					citanje.read((char*)t, sizeof(Radnik));
					if (t->getIme() != r->getIme()) {
						upis.write((char*)t, sizeof(Radnik));
					}
				}
				citanje.close();
				upis.close();
				remove("radnici.dat");
				rename("temp.dat", "radnici.dat");
			}
		}
		auto pisiUFajl = std::ofstream("radnici.dat", std::ios::binary | std::ios::app);
		if (pisiUFajl) {
			pisiUFajl.write((char*)r, sizeof(Radnik));
			pisiUFajl.close();
		}

	}

}

void Administrator::pregledRadnika() {
	std::ifstream ocitavanje;
	ocitavanje.open("radnici.dat", std::ios::binary | std::ios::in);
	Radnik* r = new Radnik;
	while (ocitavanje.good()) {
		r = new Radnik;
		ocitavanje.read((char*)r, sizeof(Radnik));
		if (r->getIme() != "") {
			std::cout << r->getIme() << "  " << r->getradnoMjesto() << "  " << r->getLozinka() << " " <<
				r->getSuspendovan() << std::endl;
		}
	}
}
