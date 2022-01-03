#pragma once
#include <iostream>

class Radnik {
protected:
	std::string korisnickoIme;
	std::string lozinka;
	std::string radnoMjesto;
	bool suspendovan = false;
public:

	Radnik(std::string korisnickoIme = "", std::string lozinka = "", std::string radnoMjesto = "");

	std::string getIme() const;
	std::string getLozinka() const;
	std::string getradnoMjesto() const;
	bool getSuspendovan() const;
	void setSuspendovan(bool suspenzija);

	//bool operator==(const Radnik& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Radnik& r);

};
