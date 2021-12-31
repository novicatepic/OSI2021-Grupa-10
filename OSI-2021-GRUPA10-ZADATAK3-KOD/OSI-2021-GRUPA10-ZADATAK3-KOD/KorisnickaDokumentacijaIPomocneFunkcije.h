#pragma once
#include <iostream>
#include <string>
#include "Radnik.h"
#include "Administrator.h"
#include "Operater.h"
#include "Sef.h"
#include "Kontrolor.h"

void korisnickaDokumentacijaGreskePriPrijavljivanju() {
	std::cout << "Najcesce greske pri prijavljivanju na sistem: " << std::endl;
	std::cout << "-Neispravan unos korisnickog imena!" << std::endl;
	std::cout << "-Neispravan unos lozinke!" << std::endl;
	std::cout << "-Slucajno pritisnut taster enter!" << std::endl;
}

void korisnickaDokumentacijaPrijePrijavljivanja() {
	std::cout << "Unesite --help ili -h za pomoc prije prijavljivanja, bilo koji drugi znak za izlaz iz opcije." << std::endl;
	//std::cout << 
}

Radnik prijaviNaSistem(const std::string korisnickoIme, const std::string lozinka) {
	auto citaj = std::ifstream("radnici.dat", std::ios::binary);
	//Radnik r;
	if (citaj) {
		while (citaj.good()) {
			//Radnik r ne radi, program kresa
			Radnik* r = new Radnik;
			citaj.read((char*)r, sizeof(Radnik));
			if (r->getIme() == korisnickoIme && r->getLozinka() == lozinka) {
				citaj.close();
				return *r;
			}

		}
	}
	Radnik r;
	citaj.close();
	return r;
}

void pomocnaFunkcijaPriPrijavljivanju() {
	std::string korisnickoIme;
	std::string lozinka;
	do {
		std::cout << "Ukoliko zelite prestati sa radom, unesite --exit" << std::endl;
		std::cout << "Unesite podatke za prijavljivanje: " << std::endl;
		std::cout << "Unesite korisnicko ime" << std::endl;
		std::cin >> korisnickoIme;
		if (korisnickoIme != "--exit") {
			std::cout << "Unesite lozinku" << std::endl;
			std::cin >> lozinka;
			Radnik r = prijaviNaSistem(korisnickoIme, lozinka);
			if (r.getIme() != "") {
				if (r.getradnoMjesto() == "Administrator") {
					Administrator a(r.getIme(), r.getLozinka());
					//FUNKCIONALNOSTI ADMINISTRATORA
				}
				else if (r.getradnoMjesto() == "Sef") {
					//FUNKCIONALNOSTI SEFA
				}
				else if (r.getradnoMjesto() == "Operater") {
					//FUNKCIONALNOSTI OPERATERA
				}
				else if (r.getradnoMjesto() == "Kontrolor") {
					//FUNKCIONALNOSTI KONTROLORA
				}
			}
			else {
				korisnickaDokumentacijaPrijePrijavljivanja();
				std::string pomoc;
				std::cin >> pomoc;
				if (pomoc == "--help" || pomoc == "-h") {
					korisnickaDokumentacijaGreskePriPrijavljivanju();
				}
			}
		}

	} while (korisnickoIme != "--exit");
}

void sefPomocnaFunkcija1() {
	std::cout << "Unesite --viewreports za pregled izvjestaja na dnevnom nivou." << std::endl;
	std::cout << "Unesite --viewreservations za pregled rezervacije letova." << std::endl;
}

void sefPomocnaFunkcija2() {
	std::cout << "Unesite --daily za pregled izvjestaja na dnevnom nivou." << std::endl;
	std::cout << "Unesite --weekly za pregled izvjestaja na sedmicnom nivou." << std::endl;
	std::cout << "Unesite --monthly za pregled izvjestaja na mjesecnom nivou." << std::endl;	
}

void kontrolorPomocnaFunkcija() {
	std::cout << "Unesite --create za kreiranje novog leta." << std::endl;
	std::cout << "Unesite --decline za otkazivanje leta." << std::endl;
	std::cout << "Unesite --view za pregled informacija o svakom letu." << std::endl;
	std::cout << "Unesite --change za mijenjanje statusa leta." << std::endl;
}

void operaterPomocnaFunkcija() {
	std::cout << "Unesite --viewreservations za pregled rezervacije letova." << std::endl;
	std::cout << "Unesite --view za pregled odobrenih i otkazanih rezervacija letova." << std::endl;
	std::cout << "Unesite --viewspecific za prikaz odredjene rezervacije letova." << std::endl;
}

void operaterPomocnaFunkcija2() {
	std::cout << "Unesite --permit za odobravanje leta." << std::endl;
	std::cout << "Unesite --decline za otkazivanje leta." << std::endl;
}

void administratorPomocnaFunkcija() {
	std::cout << "Unesite --list za pregled liste radnika." << std::endl;
	std::cout << "Unesite --delete za brisanje naloga radnika." << std::endl;
	std::cout << "Unesite --suspend za suspendovanje naloga radnika." << std::endl;
	std::cout << "Unesite --create za kreiranje naloga radnika." << std::endl;
}
