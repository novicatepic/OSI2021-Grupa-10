#include "Kontrolor.h"
#include "Let.h"
#include "Datum.h"
#include <stdio.h>
#include <string>
#include <vector>
#include <filesystem>

//FUNKCIJA ZA KREIRANJE LETOVA
void Kontrolor::kreiraj_let()
{

	try
	{
		auto fileRaspored = std::ofstream(RASPORED_FILEPATH, std::ios::app);
		if (!fileRaspored) throw std::exception("Fajl za 'RASPORED'nije otvoren");
		else
		{
			Let let;
			cin >> let;
			if (postojiLiLet(let.getID())) {
				throw std::exception("Let postoji u sistemu, ne moze se unijeti!");
			}
			char s1 = let.getVrijeme_polijetanja()[0];
			char s2 = let.getVrijeme_polijetanja()[1];
			char s3 = let.getVrijeme_polijetanja()[3];
			char s4 = let.getVrijeme_polijetanja()[4];

			std::string ccat1 = std::to_string(s1) + std::to_string(s2);
			std::string ccat2 = std::to_string(s3) + std::to_string(s4);

			if (let.getVrijeme_polijetanja().size() > 5 || let.getVrijeme_slijetanja().size() > 5)
				throw std::exception("Vrijeme neispravno uneseno!");

			/*if (s1 < '0' || s1 > '2' || s2 < '0' || s2 > '9' || s3 < '0' || s3 >= '6' || s4 < '0' || s4 > '9') {
				throw std::exception("Vrijeme neispravno uneseno!");
			}*/

			string id = to_string(let.getID());
			auto fileLet = std::ofstream("./LETOVI/let_" + id + ".txt", std::ios::app);
			if (!fileLet) throw std::exception("Fajl za 'let'nije otvoren");
			else
			{

				
				fileLet << let;
			}

			;
			fileLet.close();
			fileRaspored << let;

		}


		fileRaspored.close();

		sortiranjeRasporeda("RASPORED");
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
//FUNKCIJA ZA PROMJENU STATUSA LETA
bool Kontrolor::promjenaStatusa()
{

	try
	{
		std::string id;
		std::cin.ignore();

		namespace fs = std::filesystem;
		fs::path path = std::filesystem::current_path();

		int index = 0;
		Let* letovi = new Let[100];
		std::cout << "Unesi ID leta za projemnu statusa:";
		std::getline(std::cin, id, '\n');
		auto ucitaj = std::ifstream("./LETOVI/RASPORED.txt", std::ios::in);
		if (!ucitaj) throw std::exception("Fajl nije ucitan!");

		if (!postojiLiLet(std::stoi(id))) throw std::exception("Let ne postoji, stoga se ne moze izmijeniti!");

		else
		{
			
			std::string noviStatus;

			while (ucitaj.peek() != EOF)
			{

				letovi[index].ucitajLet(ucitaj);

				if (letovi[index].getID() == std::stoi(id))
				{
					//auto pisi = std::ofstream("./LETOVI/RASPORED_AKTIVNI_LETOVI.txt", std::ios::out | std::ios::app);
					auto pisi2 = std::ofstream("./LETOVI/ZAVRSENI_LETOVI.txt", std::ios::out | std::ios::app);
					std::cout << "Unesi novi status leta: Sletio/Poletio/Leti" << std::endl;
					std::cin >> noviStatus;
					if (pisi2)
					{
						letovi[index].setStatus(noviStatus);
						if (letovi[index].getStatus() == "Sletio")
						{
							pisi2 << letovi[index];
							std::cout << "Status leta promijenjen na sletio! " << std::endl;
							pisi2.close();
							std::string nazivFajla = "./LETOVI" + id + ".txt";

							
							fs::path exampleSubfolderPath = path / "./LETOVI";
							auto filePath = exampleSubfolderPath / ("let_" + id + ".txt");
							fs::remove(filePath);
							//remove(kopirajNaziv);
							azurirajAktivneLetove(id);
							izbrisiIzRasporeda(id);
							sortiranjeRasporeda("ZAVRSENI_LETOVI");
							return  true;
						}
						else if (letovi[index].getStatus() == "Poletio" || letovi[index].getStatus() == "Leti") {
							//SAMO PROMIJENITI U .TXT FAJLU LETA DA JE POLETIO

							//pisi << letovi[index];
							auto upisUFajl = std::ofstream("./LETOVI/let_" + id + ".txt", std::ios::out);
							upisUFajl << letovi[index];
							upisUFajl.close();
							auto upisUAktivneLetove = std::ofstream("./LETOVI/AKTIVNI_LETOVI.txt", std::ios::out | std::ios::app);
							upisUAktivneLetove << letovi[index];
							upisUAktivneLetove.close();
							if (letovi[index].getStatus() == "Poletio") {
								std::cout << "Status leta promijenjen na poletio!" << std::endl;
							}
							else {
								std::cout << "Status leta promijenjen na leti!" << std::endl;
							}

							izbrisiIzRasporeda(id);

							return true;
						}
						else
						{
							//OVDJE TREBA ISPISATI GRESKU!!!!!
							//pisi << letovi[index];
							//std::cout << "Status leta promijenjen! " << std::endl;
							std::cout << "Neispravan izbor opcije!" << std::endl;
							//pisi.close();
							return true;
						}
					}
					++index;
				}
				else
				{
					++index;
				}
			}

			ucitaj.close();
		}
		delete[] letovi;

	}

	catch (const exception& e)
	{
		std::cout << e.what() << ::endl;
	}
}
//FUNKCIJA ZA SORTIRANJE RASPOREDA
void Kontrolor::sortiranjeRasporeda(std::string nazivFajla)
{
	ifstream file;
	int index = 0;
	string line;
	Let* letovi = new Let[100];
	file.open("./LETOVI/"+nazivFajla+".txt", std::ios::in);
	if (file)
	{
		while (file.peek() != EOF)
		{
			letovi[index].ucitajLet(file);
			index++;
		}
		file.close();
		for (int i = 0; i < index - 1; ++i)
		{
			for (int j = i + 1; j < index; j++)
			{
				if (letovi[j].getDatum() < letovi[i].getDatum())
				{
					Let temp = letovi[j];
					letovi[j] = letovi[i];
					letovi[i] = temp;
				}
			}
		}
		auto pisi = std::ofstream("./LETOVI/"+nazivFajla+".txt", std::ios::out);
		for (int i = 0; i < index; ++i)
		{
			pisi << letovi[i];
		}
		pisi.close();
	}

	//remove("./LETOVI/ZAVRSENI_LETOVI.txt");
	//rename("./LETOVI/NOVI_RASPORED.txt", "./LETOVI/ZAVRSENI_LETOVI.txt");
	delete[] letovi;
	//std::cout << "Raspored soritan po datumu!" << std::endl;

}
//FUNKCIJA ZA PREGLED SVIH LETOVIA
void Kontrolor::pregledInformacijaOLetovima() const
{
	try
	{
		std::cout << "PREGLED RASPOREDA LETOVA" << std::endl;
		std::cout << "ID, Vrijeme polijetanja, Vrijeme slijetanja, Opis, Broj mjesta, Broj trenutno slobodnih mjesta, Status" << std::endl;
		fstream file;
		string str;
		file.open(RASPORED_FILEPATH, std::ios::in);
		if (!file) throw std::exception("Ne moze se otvoriti fajl 'LETOVI'");
		{
			while (!file.eof())
			{
				getline(file, str);
				std::cout << str << endl;
			}
		}
		file.close();
	
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}



}
//FUNKCIJA ZA OTKAZIVANJE LETA
void Kontrolor::otkazivanjeLeta()
{
	try
		{

			string ID;
			int index = 0;
			std::cin.ignore();
			std::cout << "Unesi ID leta koji se otkazuje!";
			std::getline(std::cin, ID, '\n');

			if (!postojiLiLet(std::stoi(ID))) {
				throw std::exception("Ne mozete ukloniti let koji ne postoji!");
			}
			if (daLiJeLetAktivan(ID)) {
				throw std::exception("Ne mozete otkazati let koji je poletio!");
			}

			//std::cin >> ID;
			std::ifstream file;
			Let* letovi = new Let[100];
			file.open("./LETOVI/RASPORED.txt", std::ios::in);
			if (file)
			{

				while (file.peek() != EOF)
				{
					letovi[index].ucitajLet(file);
					++index;
				}
			}
				file.close();
				auto upis = std::ofstream("./LETOVI/RASPORED.txt", std::ios::out);
				for (int i = 0; i < index; i++)
				{
					if (letovi[i].getID() != std::stoi(ID))
					{
						//auto upis = ofstream("./LETOVI/RASPORED.txt", std::ios::out | std::ios::app);

						if (upis) {
							upis << letovi[i];
						}
						
					}
				}
				upis.close();
				std::string fileName = "./LETOVI/let_" + ID +".txt";
				int result=remove(fileName.c_str());
				if (result == 0) {
					std::cout << "Let za izabrani ID=" << ID << " je uspjesno otkazan! ";
					promijeniOperatera(ID);
				}
					
				else {
					std::cout << "Let za izabrani ID=" << ID << " nije otkazan! ";
				}


			//remove("./LETOVI/RASPORED.txt");
			//rename("./LETOVI/NOVIRASPORED.txt", "./LETOVI/RASPORED.txt");
			delete[] letovi;
		}
		catch (const exception& e)
		{
			std::cout << e.what() << std::endl;
		}

}

bool Kontrolor::postojiLiLet(int ime) const {
	namespace fs = std::filesystem;

	fs::path path = std::filesystem::current_path();
	fs::path exampleSubfolderPath = path / "./LETOVI";
	//auto filePath = exampleSubfolderPath / ("let_" + id + ".txt");
	//fs::remove(filePath);

	std::string napraviIme = "let_" + std::to_string(ime);

	for (auto const& entry : fs::directory_iterator(exampleSubfolderPath)) {
		if (entry.path().filename() == napraviIme + ".txt")
			return true;
	}

	return false;

}


void Kontrolor::promijeniOperatera(std::string id) const {

	namespace fs = std::filesystem;
	fs::path path = std::filesystem::current_path();

	fs::path subFolder = path / "REZERVACIJE";

	for (auto const& entry : fs::directory_iterator(path / "REZERVACIJE")) {
		if (entry.path().filename() != "ODOBRENE_REZERVACIJE" && entry.path().filename() != "OTKAZANE_REZERVACIJE") {
			
			std::string a = entry.path().filename().string();

			//a = a.substr(1, a.size() - 2);

			//std::string b = entry.path;

			auto citaj = std::ifstream("./REZERVACIJE/" + a, std::ios::in);

			//std::cout << a;
			//std::cout << entry.path().filename() << std::endl;
			if (citaj) {
				std::string pomocniString;
				std::getline(citaj, pomocniString, '\n');
				if (pomocniString == id) {
					//auto putanja = subFolder / ("")
					citaj.close();
					fs::remove("./REZERVACIJE/" + a);
				}
				citaj.close();
			}
		}
	}

}

void Kontrolor::izbrisiIzRasporeda(std::string id) {
	std::vector<Let> nizLetova;
	auto citajLetove = std::ifstream("./LETOVI/RASPORED.txt", std::ios::in);

	if (citajLetove) {
		Let citaj;
		while (citajLetove.peek() != EOF) {
			citaj.ucitajLet(citajLetove);
			if (citaj.getID() != std::stoi(id)) {
				nizLetova.push_back(citaj);
			}
		}

		citajLetove.close();

		auto pisiLetove = std::ofstream("./LETOVI/RASPORED.txt", std::ios::out);
		for (auto elem : nizLetova) {
			pisiLetove << elem;
		}

		sortiranjeRasporeda("RASPORED");

		pisiLetove.close();
	}
}

void Kontrolor::azurirajAktivneLetove(std::string id) {
	std::vector<Let> nizLetova;
	auto citajLetove = std::ifstream("./LETOVI/AKTIVNI_LETOVI.txt", std::ios::in);

	if (citajLetove) {
		Let citaj;
		while (citajLetove.peek() != EOF) {
			citaj.ucitajLet(citajLetove);
			if (citaj.getID() != std::stoi(id)) {
				nizLetova.push_back(citaj);
			}
		}

		citajLetove.close();

		auto pisiLetove = std::ofstream("./LETOVI/AKTIVNI_LETOVI.txt", std::ios::out);
		for (auto elem : nizLetova) {
			if(elem.getID() != std::stoi(id))
				pisiLetove << elem;
		}

		sortiranjeRasporeda("AKTIVNI_LETOVI");

		pisiLetove.close();

	}
}

bool Kontrolor::daLiJeLetAktivan(std::string id) {
	auto otvoriFajl = std::ifstream("./LETOVI/let_" + id + ".txt", std::ios::in);

	if (otvoriFajl) {
		Let l;
		l.ucitajLet(otvoriFajl);

		if (l.getStatus() != "spreman")
			return true;


		otvoriFajl.close();
	}

	return false;
}

void Kontrolor::promjenaStatusaNovica() {

	try
	{
		std::string id;
		std::cin.ignore();

		namespace fs = std::filesystem;
		fs::path path = std::filesystem::current_path();

		//int index = 0;
		std::cout << "Unesi ID leta za projemnu statusa:";
		std::getline(std::cin, id, '\n');
		auto ucitaj = std::ifstream("./LETOVI/let_" + id + ".txt", std::ios::in);
		if (!ucitaj) throw std::exception("Let ne postoji!");

		if (!postojiLiLet(std::stoi(id))) throw std::exception("Let ne postoji, stoga se ne moze izmijeniti!");

		else
		{

				std::string noviStatus;

				Let l;
				l.ucitajLet(ucitaj);

				//auto pisi = std::ofstream("./LETOVI/RASPORED_AKTIVNI_LETOVI.txt", std::ios::out | std::ios::app);
				auto pisi2 = std::ofstream("./LETOVI/ZAVRSENI_LETOVI.txt", std::ios::out | std::ios::app);
				std::cout << "Unesi novi status leta: Sletio/Poletio/Leti" << std::endl;
				std::cin >> noviStatus;
				if (pisi2)
				{
					l.setStatus(noviStatus);
					//letovi[index].setStatus(noviStatus);
					if (l.getStatus() == "Sletio")
					{
						pisi2 << l;
						std::cout << "Status leta promijenjen na sletio! " << std::endl;
						pisi2.close();
						std::string nazivFajla = "./LETOVI" + id + ".txt";

						ucitaj.close();
						fs::path exampleSubfolderPath = path / "./LETOVI";
						auto filePath = exampleSubfolderPath / ("let_" + id + ".txt");
						fs::remove(filePath);
						//remove(kopirajNaziv);
						azurirajAktivneLetove(id);
						izbrisiIzRasporeda(id);
						sortiranjeRasporeda("ZAVRSENI_LETOVI");
						return;
					}
					else if (l.getStatus() == "Poletio" || l.getStatus() == "Leti") {
							//SAMO PROMIJENITI U .TXT FAJLU LETA DA JE POLETIO

							//pisi << letovi[index];
						auto upisUFajl = std::ofstream("./LETOVI/let_" + id + ".txt", std::ios::out);
						upisUFajl << l;
						upisUFajl.close();
						prepisiLetove(id);
						auto upisUAktivneLetove = std::ofstream("./LETOVI/AKTIVNI_LETOVI.txt", std::ios::out | std::ios::app);
						upisUAktivneLetove << l;
						upisUAktivneLetove.close();
						if (l.getStatus() == "Poletio") {
							std::cout << "Status leta promijenjen na poletio!" << std::endl;
						}
						else {
							std::cout << "Status leta promijenjen na leti!" << std::endl;
						}
						sortiranjeRasporeda("AKTIVNI_LETOVI");
						izbrisiIzRasporeda(id);
					}
					else
					{
							//OVDJE TREBA ISPISATI GRESKU!!!!!
							//pisi << letovi[index];
							//std::cout << "Status leta promijenjen! " << std::endl;
						std::cout << "Neispravan izbor opcije!" << std::endl;
							//pisi.close();
					}
				}
			ucitaj.close();
		}
	}
	catch (const exception& e)
	{
		std::cout << e.what() << ::endl;
	}
}

void Kontrolor::prepisiLetove(std::string id) {
	auto citanje = std::ifstream("./LETOVI/AKTIVNI_LETOVI.txt", std::ios::in);
	std::vector<Let> aktivniLetovi;
	if (citanje) {
		while (citanje.peek() != EOF) {
			Let l;
			l.ucitajLet(citanje);
			if (l.getID() != std::stoi(id)) {
				aktivniLetovi.push_back(l);
			}
		}
		citanje.close();
	}

	auto upis = std::ofstream("./LETOVI/AKTIVNI_LETOVI.txt", std::ios::out);

	for (auto elem : aktivniLetovi) {
		upis << elem;
	}
	upis.close();
}