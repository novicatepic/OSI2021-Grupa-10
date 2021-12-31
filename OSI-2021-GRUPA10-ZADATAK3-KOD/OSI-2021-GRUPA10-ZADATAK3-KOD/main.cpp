#include "Radnik.h"
#include "Sef.h"
#include "Administrator.h"
#include "Kontrolor.h"
#include "Operater.h"
#include "KorisnickaDokumentacijaIPomocneFunkcije.h"
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
		std::cout << "Unesite korisnicko ime" << std::endl;
		std::cin >> korisnickoIme;
		std::cout << "Unesite lozinku" << std::endl;
		std::cin >> lozinka;
		Radnik r(korisnickoIme, lozinka, "Administrator");
		pisiUFajl.write((char*)&r, sizeof(Radnik));
		pisiUFajl.close();
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		//Administrator a(korisnickoIme, lozinka);
		std::string unosOpcije;
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

	return 0;
}