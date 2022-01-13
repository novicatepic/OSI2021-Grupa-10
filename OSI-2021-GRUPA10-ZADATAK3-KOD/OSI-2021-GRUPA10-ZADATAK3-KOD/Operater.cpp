//
// Created by sinisa on 12/30/21.
//

#include "Operater.h"
#include <vector>
#include <set>
namespace fs = std::filesystem;

bool pomocZaOperatera(std::string id) {
    auto otvori = std::ifstream("./LETOVI/let_" + id + ".txt", std::ios::in);
    try {
        if (!otvori) {
            throw std::exception("Ne postoji let sa datim ID!");
        }
        else {
            Let l;
            l.ucitajLet(otvori);
            otvori.close();

            if (l.getStatus() != "spreman") {
                throw std::exception("Nemoguce odobriti rezervaciju za aktivan let ili let koji je zavrsen!");
            }

            if (l.getBr_slobodnih_mjesta() >= 1 && l.getStatus() == "spreman") { //FALI JOS USLOV AKO MIRUJE 
                l.setBr_slobodnih_mjesta(l.getBr_slobodnih_mjesta() - 1);
                auto promijeni = std::ofstream("./LETOVI/let_" + id + ".txt", std::ios::out);
                if (promijeni) {
                    promijeni << l;
                    promijeni.close();
                }

                std::set<Let> setLetova;
                auto promijeniRaspored = std::ifstream("./LETOVI/RASPORED.txt", std::ios::in);
                if (promijeniRaspored) {
                    while (promijeniRaspored.peek() != EOF) {
                        Let l2;
                        l2.ucitajLet(promijeniRaspored);
                       // if (l.getID() == std::stoi(id)) {
                            //l.setBr_slobodnih_mjesta(l.getBr_slobodnih_mjesta() - 1);
                        //}
                        if (l2.getID() == l.getID()) {
                            l2.setBr_slobodnih_mjesta(l.getBr_slobodnih_mjesta());
                        }
                        setLetova.insert(l2);
                    }
                    promijeniRaspored.close();
                    auto pisiRaspored = std::ofstream("./LETOVI/RASPORED.txt", std::ios::out);
                    std::set<Let>::iterator it = setLetova.begin();
                    while (it != setLetova.end()) {
                        pisiRaspored << *it;
                        it++;
                    }
                    pisiRaspored.close();
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
    std::string command = "dir /b /a-d rezervacije";
    std::system(command.c_str());
}

void Operater::ispisOdbijenihRezervacija()
{
    std::string command = "dir /b /a-d REZERVACIJE\\OTKAZANE_REZERVACIJE";
    std::system(command.c_str());
}

void Operater::ispisOdobrenihRezervacija()
{
    std::string command = "dir  /b /a-d REZERVACIJE\\ODOBRENE_REZERVACIJE";
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

    fajlRezervacije.open("./REZERVACIJE/" + nazivRezervacije , std::ios::in);
    fajlRezervacije >> idLeta;
    std::cout << idLeta;
    fajlRezervacije.close();


    //std::cout << idLeta << std::endl;   //provjera da li se id ucitao


    //ime rezervacije se unosi onako kako pise u ispisu!, a u folder se rucno dodaju bez ekstenzije!!!
    std::cout << "--permit za odobravanje rezervacije, --decline za odbijanje rezervacije:" << std::endl; 
    std::cin.ignore();
    std::getline(std::cin, odgovor, '\n');

        if (odgovor == "--permit")
        {
            if (pomocZaOperatera(idLeta))
            {

                fajlRezervacije.open("./REZERVACIJE/" + nazivRezervacije, std::ios::app);
                fajlRezervacije << std::endl;
                fajlRezervacije << this->getIme();
                fajlRezervacije.close();

                std::string command = "move rezervacije\\"
                    + nazivRezervacije +
                    " rezervacije\\odobrene_rezervacije";

                std::system(command.c_str());

                std::cout << "rezervacija uspjesno odobrena!" << std::endl;
            }
            else {
                //std::cout << "let ne postoji!!!" << std::endl;
            }
        }
        else if (odgovor == "--decline")
        {
            auto citajFajl = std::ifstream("./REZERVACIJE/" + nazivRezervacije, std::ios::in);
            if (citajFajl) {
                citajFajl.close();

                fajlRezervacije.open("./REZERVACIJE/" + nazivRezervacije, std::ios::_Nocreate);
                fajlRezervacije << std::endl;
                fajlRezervacije << this->getIme();
                fajlRezervacije.close();

                std::string command = "move rezervacije\\"
                    + nazivRezervacije +
                    " rezervacije\\otkazane_rezervacije";

                std::system(command.c_str());

                std::cout << "rezervacija uspjesno otkazana!" << std::endl;

            }

            else {
                std::cout << "Rezervacija ne postoji!" << std::endl;
            }

        }
        else
        {
            std::cout << "Neispravan izbor!" << std::endl;
        }

}