



#include "Let.h"
//Dodat jos jedan argument za klasu Let -status i dopunjene sve funkcije!


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
void Let::setStatus(std::string st)
{
	this->status = st;
}

void Let::setBr_mjesta(int br1)
{
	this->br_mjesta = br1;
}

void Let::setBr_slobodnih_mjesta(int br2)
{
	this->br_slobodnih_mjesta = br2;
}

std::string Let::getStatus() const
{
	return status;
}
// Ucitava podatke o letu iz fajla i dodjeljuje vrijednosti proslijedjenom objektu (this)
void Let::ucitajLet(ifstream& file)
{

	string t_ID;
	string t_vrijeme_polijetanja;
	string t_vrijeme_slijetanja;
	string t_date_d, t_date_m, t_date_g;
	string t_opis;
	string t_status;
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
	getline(file, t_date_m, '.');										// (postoji i Novicina funkcija) 
	getline(file, t_date_g, '.');										// 
	this->setDatum(stoi(t_date_d), stoi(t_date_m), stoi(t_date_g));		//

	//file >> this->datum; RADI I OVO, VALJA SARCU, SLUZI SVRSI

	getline(file, nothing, ',');										// Da dodje do zareza i da ga preskoci, idemo dalje, na opis.



	getline(file, t_opis, ',');
	this->setOpis(t_opis);

	getline(file, t_br_mjesta, ',');
	this->setBr_mjesta(stoi(t_br_mjesta));

	getline(file, t_br_slobodnih_mjesta, ',');
	this->setBr_slobodnih_mjesta(stoi(t_br_slobodnih_mjesta));

	getline(file, t_status, '\n');
	this->setStatus(t_status);


}


// Ispisuje jedan let u formatiranom obliku
void Let::ispisi_let() const
{
	cout << " " << setw(7) << left << this->getID();
	cout << setw(24) << left << this->getVrijeme_polijetanja();
	cout << setw(23) << left << this->getVrijeme_slijetanja();
	cout << this->getDatum() << "       ";
	cout << setw(31) << left << this->getOpis();
	cout << setw(23) << left << this->getBr_mjesta();
	cout << this->getBr_slobodnih_mjesta() << endl;
	cout << setw(20) << left << this->getStatus();
}

std::istream& operator>>(std::istream& is, Let& l) {
	std::cout << "Unesite ID leta: " << std::endl;
	is >> l.ID;
	std::cout << "Unesite vrijeme polijetanja: " << std::endl;
	is >> l.vrijeme_polijetanja;
	std::cout << "Unesite vrijeme slijetanja: " << std::endl;
	is >> l.vrijeme_slijetanja;
	std::cout << "Unesite datum: " << std::endl;
	is >> l.datum;
	std::cout << "Unesite opis: " << std::endl;
	is >> l.opis;
	std::cout << "Unesite broj mjesta: " << std::endl;
	is >> l.br_mjesta;
	std::cout << "Unesite broj slobodnih mjesta: " << std::endl;
	is >> l.br_slobodnih_mjesta;
	return is;
}


std::ostream& operator<<(std::ofstream& ofs, const Let& l) {
	ofs << l.ID << ',' << l.vrijeme_polijetanja << ',' << l.vrijeme_slijetanja << ','
		<< l.datum << ',' << l.opis << ',' << l.br_mjesta << ',' << l.br_slobodnih_mjesta << ',' << l.status << std::endl;
	return ofs;
}
























bool Let::pomocZaOperatera(std::string id) {
	auto otvori = std::ifstream("./LETOVI/let_" + id + ".txt", std::ios::in);
	try {
		if (!otvori) {
			throw std::exception("Ne postoji let sa datim ID!");
		}
		else {
			Let l;
			otvori >> l;
			otvori.close();
			if (l.br_slobodnih_mjesta >= 1) { //FALI JOS USLOV AKO MIRUJE 
				l.br_slobodnih_mjesta -= 1;
				auto promijeni = std::ofstream("./LETOVI/let_" + id + ".txt", std::ios::out);
				if (promijeni) {
					promijeni << l;
					promijeni.close();
				}
				return true;
			}
			else {
				return false;
			}
		}
	}
	catch (const std::exception& e) {
		std::cout << e.what();
		return false;
	}
}