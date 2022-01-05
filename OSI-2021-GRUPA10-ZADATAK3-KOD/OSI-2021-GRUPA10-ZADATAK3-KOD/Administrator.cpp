#include "Administrator.h"
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>

Administrator::Administrator(std::string korisnickoIme, std::string lozinka) : Radnik(korisnickoIme, lozinka, "Administrator") {}


void Administrator::dodajRadnika() {
	try {
		auto pisiUFajl = std::ofstream("radnici.dat", std::ios::binary | std::ios::app);
		try {
			if (!pisiUFajl) throw std::exception("-Neuspjesno otvaranje datoteke!-");
			std::string korisnickoIme, lozinka, radnoMjesto;

			std::cout << "Dodajete podatke o korisniku:" << std::endl;
			std::cout << "(Napomena: Unositi tip radnog mjesta sa pocetnim velikim slovom!)" << std::endl;
			std::cout << "Korisnicko ime: "; std::cin >> korisnickoIme;
			if (provjeriIme(korisnickoIme)) throw std::exception("-Korisnicko ime zauzeto!-");
			std::cout << "Lozinka: "; std::cin >> lozinka;
			do
			{
				std::cout << "Radno mjesto: "; std::cin >> radnoMjesto;

			} while ((radnoMjesto != "Sef" && radnoMjesto != "Administrator" && radnoMjesto != "Kontrolor"
				&& radnoMjesto != "Operater"));

			if (radnoMjesto == "Administrator") {
				if (kolikoAdministratora() >= 2) {
					throw std::exception("-Dozvoljeno maksinalno 2 administratora u sistemu!-");
				}
			}
			else if (radnoMjesto == "Sef") {
				if (kolikoSefova() >= 3) {
					throw std::exception("-Dozvoljeno maksimalno 3 sefa u sistemu!-");
				}
			}

			Radnik r(korisnickoIme, lozinka, radnoMjesto);
			pisiUFajl.write((char*)&r, sizeof(Radnik));

			pisiUFajl.close();
			std::cout << "Radnik " << "'" << korisnickoIme << "' " << "uspjesno dodat." << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (const  std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

void Administrator::obrisiRadnika() {
	try {
		std::string korisnickoIme;
		std::string lozinka;
		std::cout << "Unesite korisnicko ime radnika ciji nalog zelite da obrisete: " << std::endl;
		std::cin >> korisnickoIme;
		if (!provjeriIme(korisnickoIme)) throw std::exception("-Ne postoji korisnik sa datim imenom-");
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
					std::cout << "Radnik " << "'" << r->getIme() << "' " << "uspjesno obrisan." << std::endl;
				}
			}
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}


void Administrator::suspendujRadnika() {
	try {
		std::string korisnickoIme;
		int suspenzija;
		std::cout << "Unesite korisnicko ime radnika ciji nalog zelite da suspendujete:" << std::endl;
		std::cin >> korisnickoIme;
		if (!provjeriIme(korisnickoIme)) throw std::exception("-Ne postoji korisnik sa datim imenom-");
		do {
			std::cout << "Unesite 1 ili 0 da suspendujete ili uklonite suspenziju:" << std::endl;
			std::cin >> suspenzija;
			if (suspenzija != 1 && suspenzija != 0) std::cout << "NEKOREKTAN UNOS!" << std::endl;
		} while (suspenzija != 1 && suspenzija != 0);

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
			else if (suspenzija == 0) {
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
				if (suspenzija == 1) {
					std::cout << "Radnik " << "'" << r->getIme() << "' " << "uspjesno suspendovan." << std::endl;
				}
				else {
					std::cout << "Radniku " << "'" << r->getIme() << "' " << "uspjesno uklonjena suspenzija." << std::endl;
				}
			}

		}
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
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

bool Administrator::provjeriIme(std::string ime) {

	auto citanje = std::ifstream("radnici.dat", std::ios::binary | std::ios::in);

	if (citanje) {
		Radnik* r = new Radnik;
		while (citanje.good()) {
			r = new Radnik;
			citanje.read((char*)r, sizeof(Radnik));
			if (r->getIme() == ime) {
				citanje.close();
				return true;
			}
		}
		citanje.close();
		return false;
	}
}