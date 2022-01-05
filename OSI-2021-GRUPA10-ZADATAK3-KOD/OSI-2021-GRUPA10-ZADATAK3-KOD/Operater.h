//
// Created by sinisa on 12/30/21.
//

#ifndef OSI2021_GRUPA_10_OPERATER_H
#define OSI2021_GRUPA_10_OPERATER_H

#include "Radnik.h"
#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>



class Operater :virtual public Radnik {
private:

public:

    Operater(std::string username, std::string password);
    void ispisSvihLetova();

    void ispisNeobradjenihRezervacija();
    void ispisOdobrenihRezervacija();
    void ispisOdbijenihRezervacija();

    void obradaRezervacije();






};


#endif //OSI2021_GRUPA_10_OPERATER_H
