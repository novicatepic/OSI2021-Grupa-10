#include "Kontrolor.h"
#include "Let.h"
#include "Datum.h"
#include <stdio.h>

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
		int index = 0;
		Let* letovi = new Let[100];
		std::cout << "Unesi ID leta za projemnu statusa:";
		std::cin >> id;
		auto ucitaj = std::ifstream("./LETOVI/RASPORED.txt", std::ios::in);
		if (!ucitaj) throw std::exception("Fajl nije ucitan!");
		else
		{
			
			std::string noviStatus;

			while (ucitaj.peek() != EOF)
			{

				letovi[index].ucitajLet(ucitaj);
				if (letovi[index].getID() < 0)//treba izmjeniti ovaj uslov-stavljen samo radi testa
				{

					break;
					return false;
					ucitaj.close();

				}

				if (letovi[index].getID() == stoi(id))
				{
					auto pisi = std::ofstream("./LETOVI/RASPORED_AKTIVNI-LETOVI.txt", std::ios::out | std::ios::app);
					auto pisi2 = std::ofstream("./LETOVI/ZAVRSENI_LETOVI.txt", std::ios::out | std::ios::app);
					std::cout << "Unesi novi status leta: ";
					std::cin >> noviStatus;
					if (pisi && pisi2)
					{
						letovi[index].setStatus(noviStatus);
						if (letovi[index].getStatus() == "Sletio")
						{
							pisi2 << letovi[index];
							std::cout << "Status leta promjenjen! " << std::endl;;
							return  true;
							pisi2.close();
						}
						else
						{
							pisi << letovi[index];
							std::cout << "Status leta promjenjen! " << std::endl;;
							return true;
							pisi.close();
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
//FUNKCIJA ZA SORITRANJE RASPOREDA
void Kontrolor::sortiranjeRasporeda()
{
	ifstream file;
	int index = 0;
	int numLine = 0;
	string line;
	Let* letovi = new Let[100];
	file.open("./LETOVI/RASPORED.txt", std::ios::in);
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
				if (letovi[j].getDatum() >= letovi[i].getDatum())
				{
					Let temp = letovi[j];
					letovi[j] = letovi[i];
					letovi[i] = temp;
				}
			}
		}
		auto pisi = std::ofstream("./LETOVI/NOVI_RASPORED.txt", std::ios::app | std::ios::out);
		for (int i = 0; i < index; ++i)
		{
			pisi << letovi[i];
		}
		pisi.close();
	}

	remove("./LETOVI/RASPORED.txt");
	rename("./LETOVI/NOVI_RASPORED.txt", "./LETOVI/RASPORED.txt");
	delete[] letovi;
	std::cout << "Raspored soritan po datumu!" << std::endl;

}
//FUNKCIJA ZA PREGLED SVIH LETOVIA
void Kontrolor::pregledInformacijaOLetovima() const
{
	try
	{
		std::cout << "PREGLED RASPOREDA LETOVA" << std::endl;
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
			std::cout << "Unesi ID leta koji se otkazuje!";
			std::cin >> ID;
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
				for (int i = 0; i < index; i++)
				{
					if (letovi[i].getID() != stoi(ID))
					{
						auto upis = ofstream("./LETOVI/NOVIRASPORED.txt", std::ios::out | std::ios::app);

						if (upis) {
							upis << letovi[i];
						}
					}
				}
				std::string fileName= "./LETOVI/let_"+ID+".txt";
				int result=remove(fileName.c_str());
				if (result == 0)
					std::cout << "Let za izabrani ID=" << ID << " je uspjesno otkazan! ";
				else
					std::cout << "Let za izabrani ID=" << ID << " nije otkazan! ";
			remove("./LETOVI/RASPORED.txt");
			rename("./LETOVI/NOVIRASPORED.txt", "./LETOVI/RASPORED.txt");
			delete[] letovi;
		}
		catch (const exception& e)
		{
			std::cout << e.what() << std::endl;
		}

}

