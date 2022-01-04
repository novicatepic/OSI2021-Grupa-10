#pragma once



#include <iostream>
#include <fstream>
#include <string>


class Datum {
private:
	int dan;
	int mjesec;
	int godina;

public:
	Datum(int dan = 0, int mjesec = 0, int godina = 0) : dan(dan), mjesec(mjesec), godina(godina) {}

	int getDan() const {
		return this->dan;
	}

	int getMjesec() const {
		return this->mjesec;
	}

	int getGodina() const {
		return this->godina;
	}

	void setDan(int d) { this->dan = d; }
	void setMjesec(int m) { this->mjesec = m; }
	void setGodina(int g) { this->godina = g; }

	friend std::istream& operator>>(std::ifstream& ifs, Datum& d) {
		char delim = '.';
		std::string tip;
		std::string dan, mjesec, godina;
		std::getline(ifs, dan, delim);
		std::getline(ifs, mjesec, delim);
		std::getline(ifs, godina, delim);
						
		
		d.dan = std::stoi(dan);
		d.mjesec = std::stoi(mjesec);
		d.godina = std::stoi(godina);
		return ifs;
	}

	friend std::ostream& operator<<(std::ofstream& ofs, const Datum& d) {
		return ofs << d.dan << '.' << d.mjesec << '.' << d.godina << '.';
	}

	friend std::ostream& operator<<(std::ostream& os, const Datum& d) {
		return os << d.dan << '.' << d.mjesec << '.' << d.godina << '.';
	}

	friend std::istream& operator>>(std::istream& is, Datum& d) {
		std::cout << "Unesite dan: " << std::endl;
		is >> d.dan;
		std::cout << "Unesite mjesec: " << std::endl;
		is >> d.mjesec;
		std::cout << "Unesite godinu: " << std::endl;
		is >> d.godina;
		return is;
	}
	
	bool operator==(const Datum& drugiDatum) const {
		if (this->dan == drugiDatum.dan && this->mjesec == drugiDatum.mjesec && this->godina == drugiDatum.godina)
			return true;

		return false;
	}

	bool operator!=(const Datum& drugiDatum) const {
		if (this->dan == drugiDatum.dan && this->mjesec == drugiDatum.mjesec && this->godina == drugiDatum.godina)
			return false;

		return true;
	}

	bool operator>=(const Datum& drugiDatum) const {
		if (*this == drugiDatum)
			return true;

		if (this->godina > drugiDatum.godina ||
			(this->godina == drugiDatum.godina && this->mjesec > drugiDatum.mjesec) ||
			(this->godina == drugiDatum.godina && this->mjesec == drugiDatum.mjesec && this->dan > drugiDatum.dan)) {
			return true;
		}

		return false;
	}

	bool operator<=(const Datum& drugiDatum) const {
		if (*this == drugiDatum)
			return true;

		return !(*this >= drugiDatum);
	}
};
