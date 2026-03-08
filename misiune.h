#ifndef MISIUNE_H
#define MISIUNE_H

#include <string>
#include <fstream>
#include <vector>

class Misiune {
public:
    std::string idRacheta;
    std::string idAsteroid;
    std::string resursa;
    double cantitateExtrasa;
    double combustibilConsum;
    double costCombustibil;
    double profitBrut;
    double profitNet;

    Misiune(std::string idR, std::string idA, std::string res, double cant, double comb, double cost, double pBrut, double pNet);
    static void scrieMisiuni(const std::string& numeFisier, const std::vector<Misiune>& misiuni);
};

#endif
