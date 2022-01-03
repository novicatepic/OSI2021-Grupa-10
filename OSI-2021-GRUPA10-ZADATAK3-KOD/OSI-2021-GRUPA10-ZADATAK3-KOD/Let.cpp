



#include "Let.h"



int Let::getID() const
{
	return ID;
}

std::string Let::getVrijeme_polijetanja() const
{
	return vrijeme_polijetanja;
}

std::string Let::getVrijeme_slijetanja() const
{
	return vrijeme_slijetanja;
}

Datum Let::getDatum() const
{
	return datum;
}

std::string Let::getOpis() const
{
	return opis;
}

int Let::getBr_mjesta() const
{
	return br_mjesta;
}

int Let::getBr_slobodnih_mjesta() const
{
	return br_slobodnih_mjesta;
}


void Let::setID(int id)
{
	this->ID = id;
}

void Let::setVrijeme_polijetanja(std::string vr_p)
{
	this->vrijeme_polijetanja = vr_p;
}

void Let::setVrijeme_slijetanja(std::string vr_s)
{
	this->vrijeme_slijetanja = vr_s;
}

void Let::setDatum(Datum dat)
{
	this->datum = dat;
}

void Let::setDatum(int d, int m, int g)
{
	(this->datum).setDan(d);
	(this->datum).setMjesec(m);
	(this->datum).setGodina(g);
}

void Let::setOpis(std::string op)
{
	this->opis = op;
}

void Let::setBr_mjesta(int br1)
{
	this->br_mjesta = br1;
}

void Let::setBr_slobodnih_mjesta(int br2)
{
	this->br_slobodnih_mjesta = br2;
}


// Ucitava podatke o letu iz fajla i dodjeljuje vrijednosti proslijedjenom objektu
void Let::ucitajLet(ifstream& file)
{

	string t_ID;
	string t_vrijeme_polijetanja;
	string t_vrijeme_slijetanja;
	string t_date_d, t_date_m, t_date_g;
	string t_opis;
	string t_br_mjesta;
	string t_br_slobodnih_mjesta;

	string nothing;

	getline(file, t_ID, ',');
	this->setID(stoi(t_ID));

	getline(file, t_vrijeme_polijetanja, ',');
	this->setVrijeme_polijetanja(t_vrijeme_polijetanja);

	getline(file, t_vrijeme_slijetanja, ',');
	this->setVrijeme_slijetanja(t_vrijeme_slijetanja);
															
	getline(file, t_date_d, '.');										// Za ucitavanje datuma 
	getline(file, t_date_m, '.');										// jer Novicina funkcija 
	getline(file, t_date_g, '.');										// ne valja
	this->setDatum(stoi(t_date_d), stoi(t_date_m), stoi(t_date_g));		// sarcu.

	getline(file, nothing, ',');										// Da dodje do zareza i da ga preskoci, idemo dalje, na opis.

															

	getline(file, t_opis, ',');
	this->setOpis(t_opis);

	getline(file, t_br_mjesta, ',');
	this->setBr_mjesta(stoi(t_br_mjesta));

	getline(file, t_br_slobodnih_mjesta, '\n');
	this->setBr_slobodnih_mjesta(stoi(t_br_slobodnih_mjesta));

}


// Ispisuje jedan let u formatiranom obliku
void Let::ispisi_let() const
{
	cout << " " << setw(7) << left << this->getID();
	cout << setw(24) << left << this->getVrijeme_polijetanja();
	cout << setw(23) << left << this->getVrijeme_slijetanja();
	cout << this->getDatum()<<"       ";
	cout << setw(31) << left << this->getOpis();
	cout << setw(23) << left << this->getBr_mjesta();
	cout << this->getBr_slobodnih_mjesta() << endl;
}

