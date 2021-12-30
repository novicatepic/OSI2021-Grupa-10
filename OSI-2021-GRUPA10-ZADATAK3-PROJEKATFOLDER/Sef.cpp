



#include "Sef.h"




void Sef::pregled_zavrsenih_letova()
{
	try {
		
		std::fstream file;
		file.open("./LETOVI/ZAVRSENI_LETOVI.txt", std::ios::in);
		std::string str;

		if (!file) throw std::exception("Ne mogu otvoriti fajl 'ZAVRSENI_LETOVI' !");
		
		while (!file.eof())
		{
			getline(file, str);

			std::cout << str << std::endl;
		}

		file.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}



void Sef::pregled_rezervacija()
{
	try {

		std::fstream file;
		file.open("./LETOVI/REZERVACIJE.txt", std::ios::in);
		std::string str;

		if (!file) throw std::exception("Ne mogu otvoriti fajl 'REZERVACIJE' !");

		while (!file.eof())
		{
			getline(file, str);

			std::cout << str << std::endl;
		}

		file.close();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
}