#pragma once
#include <exception>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <filesystem>

#include "Let.h"
#include "Datum.h"
#include "Radnik.h"

class Let;
namespace fs = std::filesystem;
#define LETOVI_FILEPATH "./LETOVI/RASPORED.txt"
#define REZERVACIJE_FILEPATH "./REZERVACIJE/"


class Kontrolor :virtual public Radnik
{
private:
public:
    Kontrolor(std::string name, std::string pass) : Radnik(name, pass, "Kontrolor") {}
    void kreiraj_let();
    bool promjenaStatusa(std::string );
    void sortiranjeRasporeda();
    void pregledInformacijaOLetovima() const;
    void otkazivanjeLeta();
    

};
