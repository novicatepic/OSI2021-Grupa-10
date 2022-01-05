//
// Created by sinisa on 12/30/21.
//

#include "Operater.h"
namespace fs = std::filesystem;

Operater::Operater(std::string username, std::string password)
{
    this->korisnickoIme = username;
    this->lozinka = password;
    this->radnoMjesto = "Operater";

}

void Operater::ispisSvihLetova()
{
    /*namespace fs = std::filesystem;
    std::string path = "\\LETOVI";
    for (const auto& entry : fs::directory_iterator(path)) {

        std::string string = entry.path();
        string.erase(0, 9);
        string.erase(string.length() - 4);

        std::cout << string << std::endl;
    }*/

    fs::path path = std::filesystem::current_path();

    for (auto const& entry : fs::directory_iterator(path / "LETOVI"))
        std::cout << entry.path().filename() << std::endl;

}

void Operater::ispisNeobradjenihRezervacija()
{
    std::string command = "dir *.txt /b /a-d rezervacije";
    std::system(command.c_str());
}

void Operater::ispisOdbijenihRezervacija()
{
    std::string command = "dir *.txt /b /a-d rezervacije/odbijene_rezervacije";
    std::system(command.c_str());
}

void Operater::ispisOdobrenihRezervacija()
{
    std::string command = "dir *.txt /b /a-d rezervacije/odobrene_rezervacije";
    std::system(command.c_str());
}

void Operater::obradaRezervacije()
{
    //stavio sam ovdje ispis zbog lakseg unosa 
    ispisNeobradjenihRezervacija();


    std::string nazivRezervacije;
    std::string odgovor;
    std::fstream fajlRezervacije;
    std::string  idLeta;

    std::cout << "Unesite rezervaciju za obradu: "; std::cin >> nazivRezervacije;

    fajlRezervacije.open("./REZERVACIJE/" + nazivRezervacije + ".txt", std::ios::in);
    fajlRezervacije >> idLeta;
    fajlRezervacije.close();

    std::cout << idLeta << std::endl;


    //ime rezervacije se unosi onako kako pise u ispisu!, a u folder se rucno dodaju bez ekstenzije!!!
    std::cout << "odobri/odbij/ostavi :"; std::cin >> odgovor;
    if (odgovor == "odobri")
    {
        fajlRezervacije.open("./REZERVACIJE/" + nazivRezervacije + ".txt", std::ios::app);
        fajlRezervacije << this->getIme();
        fajlRezervacije.close();

        std::string command = "move rezervacije\\"
            + nazivRezervacije +
            " rezervacije\\odobrene_rezervacije";

        std::system(command.c_str());

        std::cout << "rezervacija uspjesno odobrena!" << std::endl;

    }
    else if (odgovor == "odbij")
    {
        fajlRezervacije.open("./REZERVACIJE/" + nazivRezervacije + ".txt", std::ios::app);
        fajlRezervacije << this->getIme();
        fajlRezervacije.close();

        std::string command = "move rezervacije\\"
            + nazivRezervacije +
            " rezervacije\\otkazane_rezervacije";

        std::system(command.c_str());

        std::cout << "rezervacija uspjesno otkazana!" << std::endl;
    }
    else
    {
        std::cout << "obrada rezervacije odlozena!" << std::endl;
    }
}
