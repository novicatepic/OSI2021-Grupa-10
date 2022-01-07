#include "Kontrolor.h"
#include "Let.h"
#include "Datum.h"
#include <stdio.h>

//Funkcija radi i testirana 
void Kontrolor::kreiraj_let()
{

	try
	{
		auto fileRaspored = std::ofstream(LETOVI_FILEPATH, std::ios::app);
		if (!fileRaspored) throw std::exception("Fajl za 'RASPORED'nije otvoren");
		else
		{
			Let let;
			cin >> let;
			string id = to_string(let.getID());
			auto fileLet = std::ofstream("./LETOVI/let_" + id + ".txt", std::ios::app);
			if (!fileLet) throw std::exception("Fajl za 'let'nije otvoren");
			else
			{

				fileLet << " | ID | Vrijeme polijetanja | Vrijeme slijetanja | Datum polaska | Rut | Ukupan broj mjesta | Broj slobodnih mjesta | " << std::endl;
				fileLet << let;
			}

			;
			fileLet.close();
			fileRaspored << let;

		}
		fileRaspored.close();

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
//Treba malo izmjene!
bool Kontrolor::promjenaStatusa(std::string id)
{

	try
	{
		auto ucitaj = std::ifstream("./LETOVI/RASPORED.txt", std::ios::in);
		if (!ucitaj) throw std::exception("Fajl nije ucitan!");
		else
		{
			Let temp_let;
			std::string noviStatus;

			while (!ucitaj.eof())
			{

				temp_let.ucitajLet(ucitaj);
				if (temp_let.getID() < 0)//treba izmjeniti ovaj uslov-stavljen samo radi testa
				{

					break;
					return false;
					ucitaj.close();

				}

				if (temp_let.getID() == stoi(id))
				{
					auto pisi = std::ofstream("./LETOVI/let_" + id + "temp.txt", std::ios::out | std::ios::app);
					std::cout << "Unesi novi status leta: ";
					std::cin >> noviStatus;
					if (pisi)
					{
						temp_let.setStatus(noviStatus);
						pisi << temp_let;;
						return true;
						pisi.close();
					}
				}



			}

			ucitaj.close();
			//remove("./LETOVI/let_"+id+".txt");//treba staviti da putanja bude ista kao i kod otvaranja ali funkcije remove i rename ne priznaju!
			//rename("./LETOVI/let_1.txt", "./LETOVI/let_1temp.txt");

		}


	}

	catch (const exception& e)
	{
		std::cout << e.what() << ::endl;
	}


}
//Treba dovrsiti za ponovni upis u fajl
void Kontrolor::sortiranjeRasporeda()
{
	try
	{
		ifstream file;
		file.open("./LETOVI/TEMP_RASPORED.txt", std::ios::in);
		if (!file) throw std::exception("Fajl nije otvoren!");

		std::vector<Let> letovi;
		Let temp;
		while (!file.eof())
		{
			temp.ucitajLet(file);
			letovi.push_back(temp);
		}
		for (const auto& let : letovi)
		{


		}

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
//Funkcija testirana i radi
void Kontrolor::pregledInformacijaOLetovima() const
{
	try
	{
		std::cout << "Pregled svih letova!" << std::endl;
		fstream file;
		string str;
		file.open(LETOVI_FILEPATH, std::ios::in);
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
//Nedovrsnena funkcija
void Kontrolor::otkazivanjeLeta()
{
	try
	{

		int ID;
		std::cout << "Unesi ID leta koji se otkazuje!";
		std::cin >> ID;

		std::ifstream filein;
		filein.open("./LETOVI/RASPORED.txt", std::ios::in);
		if (filein)
		{
			Let* l = new Let;
			while (!filein.eof())
			{
				l = new Let;

				l->ucitajLet(filein);
				if (l->getID() == ID)
				{
					l->ispisi_let();

				}
				break;
			}
			filein.close();

			if (l->getID() == 0)
			{
				auto citanje = ifstream("./LETOVI/RASPORED.txt", std::ios::in);
				auto upis = ofstream("./LETOVI/NOVIRASPORED.txt", std::ios::out | std::ios::app);

				if (citanje) {

					while (!citanje.eof())
					{
						Let* let = new Let;
						let->ucitajLet(citanje);
						if (l->getID() != let->getID())
							upis << let;
					}
					citanje.close();
					upis.close();
					remove("./LETOVI/RASPORED.txt");
					rename("./LETOVI/NOVIRASPORED.txt", "./LETOVI/RASPORED.txt");

				}
			}
			std::cout << "Let sa ID:", l->getID(), "uspjesno izbrisan!";

		}
	}
	catch (const exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}
