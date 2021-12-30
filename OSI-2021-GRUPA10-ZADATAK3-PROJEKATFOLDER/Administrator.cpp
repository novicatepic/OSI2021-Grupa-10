#include "Administrator.h"
#include <fstream>
#include <string>

Administrator::Administrator(std::string korisnickoIme, std::string lozinka)
{
	Radnik (korisnickoIme, lozinka, "Administrator");
}


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

bool Administrator::suspendujRadnika(Radnik r) {
	return true;
}

bool Administrator::obrisiRadnika(Radnik r) {
	return true;
}