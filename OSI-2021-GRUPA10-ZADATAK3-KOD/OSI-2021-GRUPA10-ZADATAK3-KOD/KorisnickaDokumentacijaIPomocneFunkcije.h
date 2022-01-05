#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Radnik.h"
#include "Administrator.h"
#include "Operater.h"
#include "Sef.h"
#include "Kontrolor.h"

void pisiNoveRedove() {
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void korisnickaDokumentacijaGreskePriPrijavljivanju() {
	std::cout << "Najcesce greske pri prijavljivanju na sistem: " << std::endl;
	std::cout << "-Neispravan unos korisnickog imena!" << std::endl;
	std::cout << "-Neispravan unos lozinke!" << std::endl;
	std::cout << "-Slucajno pritisnut taster enter!" << std::endl;
	pisiNoveRedove();
}

void korisnickaDokumentacijaPrijePrijavljivanja() {
	std::cout << "Unesite --help ili -h za pomoc prije prijavljivanja, bilo koji drugi znak za izlaz iz opcije." << std::endl;
	pisiNoveRedove();
}

void pomocZaBiloKojuKlasuRadnika() {
	std::cout << "Neispravna opcija, ukoliko zelite pogledati dokumentaciju unesite --doc ili -d, bilo koji drugi znak za ponovan pokusaj opcije" << std::endl;
	pisiNoveRedove();
}

void porukaZaOdjavljivanje() {
	std::cout << "Unesite -logout da biste se odjavili sa sistema" << std::endl;
	pisiNoveRedove();
}

void sefPomocnaFunkcija1() {
	std::cout << "Unesite --viewreports za pregled izvjestaja na dnevnom nivou." << std::endl;
	std::cout << "Unesite --viewreservations za pregled rezervacije letova." << std::endl;
	porukaZaOdjavljivanje();
	pisiNoveRedove();
}

void sefPomocnaFunkcija2() {
	std::cout << "Unesite --daily za pregled izvjestaja na dnevnom nivou." << std::endl;
	std::cout << "Unesite --weekly za pregled izvjestaja na sedmicnom nivou." << std::endl;
	std::cout << "Unesite --monthly za pregled izvjestaja na mjesecnom nivou." << std::endl;
	pisiNoveRedove();
}

void kontrolorPomocnaFunkcija() {
	std::cout << "Unesite --create za kreiranje novog leta." << std::endl;
	std::cout << "Unesite --decline za otkazivanje leta." << std::endl;
	std::cout << "Unesite --view za pregled informacija o svakom letu." << std::endl;
	std::cout << "Unesite --change za mijenjanje statusa leta." << std::endl;
	porukaZaOdjavljivanje();
	pisiNoveRedove();
}

void operaterPomocnaFunkcija() {
	std::cout << "Unesite --viewreservations za pregled rezervacije letova." << std::endl;
	std::cout << "Unesite --view za pregled odobrenih i otkazanih rezervacija letova." << std::endl;
	std::cout << "Unesite --viewspecific za prikaz odredjene rezervacije letova." << std::endl;
	porukaZaOdjavljivanje();
	pisiNoveRedove();
}

void operaterPomocnaFunkcija2() {
	std::cout << "Unesite --permit za odobravanje leta." << std::endl;
	std::cout << "Unesite --decline za otkazivanje leta." << std::endl;
	std::cout << "Unesite bilo koji drugi znak za izlaz iz opcije." << std::endl;
	pisiNoveRedove();
}

void administratorPomocnaFunkcija() {
	std::cout << "Unesite --list za pregled liste radnika." << std::endl;
	std::cout << "Unesite --delete za brisanje naloga radnika." << std::endl;
	std::cout << "Unesite --suspend za suspendovanje naloga radnika." << std::endl;
	std::cout << "Unesite --create za kreiranje naloga radnika." << std::endl;
	porukaZaOdjavljivanje();
	pisiNoveRedove();
}

Radnik prijaviNaSistem(const std::string korisnickoIme, const std::string lozinka) {
	auto citaj = std::ifstream("radnici.dat", std::ios::binary | std::ios::in);
	//Radnik r;
	if (citaj) {
		while (citaj.good()) {
			//Radnik r ne radi, program kresa
			Radnik* r = new Radnik;
			citaj.read((char*)r, sizeof(Radnik));
			if (r->getIme() == korisnickoIme && r->getLozinka() == lozinka) {
				if (r->getSuspendovan() == true) {
					std::cout << "Nemoguca prijava na sistem, radnik je suspendovan!" << std::endl;
					citaj.close();
					Radnik r;
					return r;
				}
				else {
					citaj.close();
					return *r;
				}
			}

		}
	}
	Radnik r;
	citaj.close();
	return r;
}

void prikaziPodatkeORadniku(const Radnik& r) {
	std::cout << std::endl;
	std::cout << "Prijavljeni ste kao: " << std::endl;
	std::cout << r;
	std::cout << std::endl;
}

void pomocnaFunkcijaPriPrijavljivanju() {
	std::string korisnickoIme;
	std::string lozinka;
	do {
		//std::cout << "Sefova: " << kolikoSefova() << std::endl;
		//std::cout << "Administratora: " << kolikoAdministratora() << std::endl;
		std::cout << "Ukoliko zelite prestati sa radom, unesite --exit" << std::endl;
		std::cout << "Unesite podatke za prijavljivanje: " << std::endl;
		std::cout << "Unesite korisnicko ime" << std::endl;
		std::cin >> korisnickoIme;
		if (korisnickoIme != "--exit") {
			std::cout << "Unesite lozinku" << std::endl;
			std::cin >> lozinka;
			Radnik r = prijaviNaSistem(korisnickoIme, lozinka);
			if (r.getIme() != "") {
				std::string opcija;
				if (r.getradnoMjesto() == "Administrator") {
					Administrator a(r.getIme(), r.getLozinka());
					prikaziPodatkeORadniku(r);
					//FUNKCIONALNOSTI ADMINISTRATORA
					do {
						//administratorPomocnaFunkcija();
						//std::cout << "Sefova: " << a.kolikoSefova() << std::endl;
						//std::cout << "Administratora: " << a.kolikoAdministratora() << std::endl;
						std::cout << "Unesite opciju za rad: " << std::endl;
						std::cin >> opcija;
						if (opcija == "--list") {
							a.pregledRadnika();
						}
						else if (opcija == "--delete") {
							a.obrisiRadnika();
						}
						else if (opcija == "--suspend") {
							a.suspendujRadnika();
						}
						else if (opcija == "--create") {
							a.dodajRadnika();
						}
						else if (opcija == "-logout") {
							//OVDJE SE NE RADI NISTA, CISTO DA SE NE UDJE U ELSE
						}
						else if (opcija == "--doc" || opcija == "-d") {
							administratorPomocnaFunkcija();
						}
						else {
							pomocZaBiloKojuKlasuRadnika();
							std::string pomoc;
							std::cin >> pomoc;
							if (pomoc == "--doc" || pomoc == "-d") {
								administratorPomocnaFunkcija();
							}
						}
					} while (opcija != "-logout");
				}
				else if (r.getradnoMjesto() == "Sef") {
					Sef s(r.getIme(), r.getLozinka());
					prikaziPodatkeORadniku(s);
					do {
						//sefPomocnaFunkcija1();
						std::cout << "Unesite opciju za rad: " << std::endl;
						std::cin >> opcija;
						if (opcija == "--viewreports") {
							sefPomocnaFunkcija2();
							std::string dodatniUnos;
							std::cin >> dodatniUnos;
							if (dodatniUnos == "--daily") {
								//s.pregled_zavrsenih_letova_dnevno();
							}
							else if(dodatniUnos == "--weekly") {
								//s.pregled_zavrsenih_letova_sedmicno();
							}
							else if (dodatniUnos == "--monthly") {
								//s.pregled_zavrsenih_letova_mjesecno();
							}
							else {
								pomocZaBiloKojuKlasuRadnika();
								std::string pomoc;
								std::cin >> pomoc;
								if (pomoc == "--doc" || pomoc == "-d") {
									sefPomocnaFunkcija1();
								}
							}
						}
						else if (opcija == "--viewreservations") {
							//s.pregled_rezervacija();
						}
						else if (opcija == "-logout") {
							//OVDJE SE NE RADI NISTA, CISTO DA SE NE UDJE U ELSE 
						}
						else if (opcija == "--doc" || opcija == "-d") {
							sefPomocnaFunkcija1();
						}
						else {
							pomocZaBiloKojuKlasuRadnika();
							std::string pomoc;
							std::cin >> pomoc;
							if (pomoc == "--doc" || pomoc == "-d") {
								sefPomocnaFunkcija1();
							}
						}
					} while (opcija != "-logout");
				}
				else if (r.getradnoMjesto() == "Operater") {
					Operater o(r.getIme(), r.getLozinka());
					prikaziPodatkeORadniku(o);
					do {
						//operaterPomocnaFunkcija();
						std::cout << "Unesite opciju za rad: " << std::endl;
						std::cin >> opcija;
						if (opcija == "--viewreservations") {

						}
						else if (opcija == "--view") {

						}
						else if (opcija == "--viewspecific") {
							operaterPomocnaFunkcija2();
							std::string dodatniUnos;
							std::cin >> dodatniUnos;
							if (dodatniUnos == "--permit") {

							}
							else if (dodatniUnos == "--decline") {

							}
							else {
								//NE RADI SE NISTA OVDJE
							}
						}
						else if (opcija == "--logout") {

						}
						else if (opcija == "--doc" || opcija == "-d") {
							operaterPomocnaFunkcija();
						}
						else {
							pomocZaBiloKojuKlasuRadnika();
							std::string pomoc;
							std::cin >> pomoc;
							if (pomoc == "--doc" || pomoc == "-d") {
								operaterPomocnaFunkcija();
							}
						}
					} while (opcija != "-logout");
				}
				else if (r.getradnoMjesto() == "Kontrolor") {
					Kontrolor k(r.getIme(), r.getLozinka());
					prikaziPodatkeORadniku(k);
					do {
						//kontrolorPomocnaFunkcija();
						std::cout << "Unesite opciju za rad: " << std::endl;
						std::cin >> opcija;
						if (opcija == "--create") {

						}
						else if (opcija == "--decline") {

						}
						else if (opcija == "--view") {

						}
						else if (opcija == "--change") {

						}
						else if (opcija == "-logout") {

						}
						else if (opcija == "--doc" || opcija == "-d") {
							kontrolorPomocnaFunkcija();
						}
						else {
							pomocZaBiloKojuKlasuRadnika();
							std::string pomoc;
							std::cin >> pomoc;
							if (pomoc == "--doc" || pomoc == "-d") {
								kontrolorPomocnaFunkcija();
							}
						}
					} while (opcija != "-logout");
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


