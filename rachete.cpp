#include "rachete.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

void Rachete::citesteDate(const std::string& fisier) {
    std::ifstream in(fisier);
    if (!in.is_open()) {
        throw std::runtime_error("Eroare: nu se poate deschide fisierul " + fisier);
    }

    std::string linie;
    while (std::getline(in, linie)) {
        if (linie.empty() || linie.find("ID") != std::string::npos) {
            continue;
        }

        std::istringstream ss(linie);
        std::string token;
        Racheta r;

        std::getline(ss, r.id, ';');
        
        std::getline(ss, token, ';'); 
        r.capacitate_transport = std::stod(token);
        
        std::getline(ss, token, ';'); 
        r.consum_combustibil = std::stod(token);
        
        std::getline(ss, token, ';'); 
        r.pret_combustibil = std::stod(token);

        lista_rachete.push_back(r);
    }
}

std::vector<Racheta>& Rachete::getRacheteRef() {
    return lista_rachete;
}
