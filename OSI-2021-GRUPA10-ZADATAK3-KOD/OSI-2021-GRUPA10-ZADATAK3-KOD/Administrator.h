#pragma once
#include <iostream>
#include <fstream>
#include "Radnik.h"

class Administrator :virtual public Radnik {
private:

public:
	Administrator(std::string korisnickoIme, std::string lozinka);
	void dodajRadnika();
	void suspendujRadnika();
	void obrisiRadnika();
	void pregledRadnika();
	bool provjeriIme(std::string ime);

	int kolikoAdministratora() {
		int brojac = 0;
		std::ifstream citaj;
		citaj.open("radnici.dat", std::ios::binary | std::ios::in);
		try {
			if (citaj) {
				Radnik* r;
				while (citaj.good()) {
					r = new Radnik;
					citaj.read((char*)r, sizeof(Radnik));
					if (r->getradnoMjesto() == "Administrator") {
						brojac++;
					}
				}
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		citaj.close();
		return brojac;
	}


	int kolikoSefova() {
		int brojac = 0;
		std::ifstream citaj;
		citaj.open("radnici.dat", std::ios::binary | std::ios::in);
		try {
			if (citaj) {
				Radnik* r;
				while (citaj.good()) {
					r = new Radnik;
					citaj.read((char*)r, sizeof(Radnik));
					if (r->getradnoMjesto() == "Sef") {
						brojac++;
					}
				}
			}
		}
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
		}
		citaj.close();
		return brojac;
	}
};


