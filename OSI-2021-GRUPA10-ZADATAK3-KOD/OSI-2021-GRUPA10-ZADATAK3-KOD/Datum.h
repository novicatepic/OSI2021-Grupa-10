#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "PomocZaSefa.h"

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

	friend std::istream& operator>>(std::ifstream& ifs, Datum& d) {
		char delim = '.';
		std::string tip;
		std::string dan, mjesec, godina;
		std::getline(ifs, dan, delim);
		std::getline(ifs, mjesec, delim);
		std::getline(ifs, godina);
		ifs.ignore();
		//ifs.ignore();
		d.dan = std::stoi(dan);
		d.mjesec = std::stoi(mjesec);
		d.godina = std::stoi(godina);
		return ifs;
	}

	friend std::ostream& operator<<(std::ofstream& ofs, const Datum& d) {
		return ofs << d.dan << '.' << d.mjesec << '.' << d.godina << '.';
	}

	friend std::ostream& operator<<(std::ostream& os, const Datum& d) {
		if (d.getDan() != 0 && d.getMjesec() != 0 && d.getGodina() != 0) {
			return os << d.dan << '.' << d.mjesec << '.' << d.godina << '.' << std::endl;
		}
		else
			return os;
	}

	bool operator==(const Datum& drugiDatum) const {
		if (this->dan == drugiDatum.dan && this->mjesec == drugiDatum.mjesec && this->godina == drugiDatum.godina)
			return true;

		return false;
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
