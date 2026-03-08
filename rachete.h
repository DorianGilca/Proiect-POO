#ifndef RACHETE_H
#define RACHETE_H

#include <string>
#include <vector>

struct Racheta {
    std::string id;
    double capacitate_transport;
    double consum_combustibil;
    double pret_combustibil;

    int misiuni_realizate = 0;
    double profit_net_total = 0;

    double getScorEficienta() const {
        if (misiuni_realizate == 0) return 0;
        return profit_net_total / misiuni_realizate;
    }
};

class Rachete {
private:
    std::vector<Racheta> lista_rachete;
public:
    void citesteDate(const std::string& fisier);
    std::vector<Racheta>& getRacheteRef();
};

#endif
