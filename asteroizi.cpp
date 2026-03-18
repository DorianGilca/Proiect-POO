#include "asteroizi.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

void Asteroizi::citesteDate(const std::string& fisier) {
    std::ifstream in(fisier);
    if (!in.is_open()) {
        throw std::runtime_error("Eroare la deschiderea fisierului: " + fisier);
    }

    std::string linie;
    while (std::getline(in, linie)) {
        if (linie.empty() || linie.find("ID") != std::string::npos) {
            continue;
        }

        std::istringstream ss(linie);
        std::string token;
        Asteroid a;

        std::getline(ss, a.id, ';');
        std::getline(ss, a.resursa, ';');
        
        std::getline(ss, token, ';'); 
        a.cantitate_totala = std::stod(token);
        
        std::getline(ss, token, ';'); 
        a.randament = std::stod(token);
        
        std::getline(ss, token, ';'); 
        a.distanta = std::stod(token);

        lista_asteroizi.push_back(a);
    }
}

std::vector<Asteroid>& Asteroizi::getAsteroiziRef() {
    return lista_asteroizi;
}
