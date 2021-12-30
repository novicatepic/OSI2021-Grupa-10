#pragram once
#include <exception>
#include <iostream>
#include "Radnik.h"

#define FOLDERNAME_ZAVRSENI_LETOVI "LETOVI"
#define FOLDERNAME_REZERVACIJE "REZERVACIJE"

class Kontrolor :virtual public Radnik
{
private:
public:
    Kontrolor(std::string name, std::string pass) { Kontrolor(username, pass); }
    void kreiraj_let();
    void upisi_raspored_letova();
    void promjena_statusa_leta();
    void

};
#pragma once
