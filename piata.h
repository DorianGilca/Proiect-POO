#ifndef PIATA_H
#define PIATA_H

#include <string>
#include <map>
#include <stdexcept>

struct Resursa {
    std::string nume;
    double pret_min;
    double pret_max;
    double cantitate_minata = 0;

    double getPretCurent() const {
        double pret = pret_max - (cantitate_minata / 100.0);
        return (pret < pret_min) ? pret_min : pret;
    }
};

class Piata {
private:
    std::map<std::string, Resursa> resurse;

public:
    void citesteDate(const std::string& fisier);
    Resursa& getResursaRef(const std::string& nume);
    const std::map<std::string, Resursa>& getToateResursele() const;
};

#endif
