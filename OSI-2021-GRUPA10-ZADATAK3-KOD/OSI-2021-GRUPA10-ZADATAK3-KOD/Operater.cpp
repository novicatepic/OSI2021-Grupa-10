//
// Created by sinisa on 12/30/21.
//

#include "Operater.h"
namespace fs = std::filesystem;

Operater::Operater(std::string username, std::string password)
{
    this->korisnickoIme = username;
    this->lozinka = password;
    this->radnoMjesto = "operater";

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