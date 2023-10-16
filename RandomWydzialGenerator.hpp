#ifndef RANDOMWYDZIALGENERATOR_HPP
#define RANDOMWYDZIALGENERATOR_HPP

#include <array>
#include <random>
#include <string>
#include <sstream>

struct RandomInGenerator{
    static std::mt19937 prng;
};


std::mt19937 RandomInGenerator::prng = std::mt19937{std::random_device{}()};

std::array<std::string, 18> wydzial_names{
    "Inzynierii Materialowej",
    "Administracji i Nauk Spolecznych",
    "Chemiczny",
    "Elektryczny",
    "Mechaniczny Energetyki i Lotnictwa",
    "Mechaniczny Technologiczny",
    "Transportu",
    "Zarzadzania",
    "Inzynierii Ladowej",
    "Inzynierii Chemicznej i Procesowej",
    "Instalacji Budowlanych, Hydrotechniki i Inzynierii Srodowiska",
    "Geodezji i Kartografii",
    "Fizyki",
    "Elektroniki i Technik Informacyjnych",
    "Architektury",
    "Samochodów i Maszyn Roboczych",
    "Matematyki i Nauk Informacyjnych",
    "Mechatroniki",
};

std::array<std::string, 1> last_name{
    "PW",
};
 
std::string get_random_wydzial(){
    std::uniform_int_distribution<std::size_t> fnd{ 0, wydzial_names.size() - 1 };
    std::uniform_int_distribution<std::size_t> lnd{ 0, last_name.size() - 1 };
    std::stringstream name;
    name << wydzial_names[fnd(RandomInGenerator::prng)] << ' ' <<
        last_name[lnd(RandomInGenerator::prng)];
    return name.str();
}

#endif //RANDOMWYDZIALGENERATOR_HPP
