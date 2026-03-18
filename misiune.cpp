#include "misiune.h"
#include <iomanip>
#include <stdexcept>

Misiune::Misiune(std::string idR, std::string idA, std::string res, double cant, double comb, double cost, double pBrut, double pNet)
    : idRacheta(idR), idAsteroid(idA), resursa(res), cantitateExtrasa(cant), combustibilConsum(comb), costCombustibil(cost), profitBrut(pBrut), profitNet(pNet) {}

void Misiune::scrieMisiuni(const std::string& numeFisier, const std::vector<Misiune>& misiuni) {
    std::ofstream file(numeFisier);
    if (!file.is_open()) {
        throw std::runtime_error("Eroare la crearea fisierului de raport " + numeFisier);
    }

    file << "ID Racheta;ID Asteroid;Resursa;Cantitate Extrasa;Combustibil Consumat;Cost Combustibil;Profit Brut;Profit Net\n";

    for (const auto& m : misiuni) {
        file << std::fixed << std::setprecision(2)
             << m.idRacheta << ";" << m.idAsteroid << ";" << m.resursa << ";"
             << m.cantitateExtrasa << ";" << m.combustibilConsum << ";"
             << m.costCombustibil << ";" << m.profitBrut << ";" << m.profitNet << "\n";
    }
}
