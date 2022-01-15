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
	auto citajFajl = std::ifstream("radnici.dat", std::ios::binary | std::ios::in);
	if (citajFajl) {
		citajFajl.close();
		pomocnaFunkcijaPriPrijavljivanju();
	}
	else {
		 std::cout << "\n"
                 "                                    |\n"
                 "Digital Flight Control System       |\n"
                 "by Group X                          |\n"
                 "                                  .-'-.\n"
                 "                                 ' ___ '\n"
                 "                       ---------'  .-.  '---------\n"
                 "       _________________________'  '-'  '_________________________\n"
                 "        ''''''-|---|--/    \\==][^',_m_,'^][==/    \\--|---|-''''''\n"
                 "                      \\    /  ||/   H   \\||  \\    /\n"
                 "                       '--'   OO   O|O   OO   '--'"
     << std::endl;
		auto pisiUFajl = std::ofstream("radnici.dat", std::ios::binary | std::ios::app | std::ios::out);
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

	return 0;
}
