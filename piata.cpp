#include "piata.h"
#include <fstream>
#include <sstream>

void Piata::citesteDate(const std::string& fisier) {
    std::ifstream in(fisier);
    if (!in.is_open()) {
        throw std::runtime_error("Eroare la deschiderea fisierului de piata: " + fisier);
    }

    std::string linie;
    while (std::getline(in, linie)) {
        if (linie.empty() || linie.find("Resursa") != std::string::npos) {
            continue;
        }

        std::istringstream ss(linie);
        std::string token;
        Resursa res;

        std::getline(ss, res.nume, ';');
        
        std::getline(ss, token, ';'); 
        res.pret_min = std::stod(token);
        
        std::getline(ss, token, ';'); 
        res.pret_max = std::stod(token);

        resurse[res.nume] = res;
    }
}

Resursa& Piata::getResursaRef(const std::string& nume) {
    auto it = resurse.find(nume);
    if (it != resurse.end()) {
        return it->second;
    }
    throw std::runtime_error("Eroare: Resursa " + nume + " nu a fost gasita!");
}

const std::map<std::string, Resursa>& Piata::getToateResursele() const {
    return resurse;
}
