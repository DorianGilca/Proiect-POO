#ifndef ASTEROIZI_H
#define ASTEROIZI_H

#include <string>
#include <vector>

struct Asteroid {
    std::string id;
    std::string resursa;
    double cantitate_totala;
    double randament;
    double distanta;
};

class Asteroizi {
private:
    std::vector<Asteroid> lista_asteroizi;
public:
    void citesteDate(const std::string& fisier);
    std::vector<Asteroid>& getAsteroiziRef();
};

#endif
