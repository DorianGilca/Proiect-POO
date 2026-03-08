#include "piata.h"
#include "rachete.h"
#include "asteroizi.h"
#include "misiune.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Utilizare: " << argv[0] << " <rachete.csv> <asteroizi.csv> <piata.csv>\n";
        return 1;
    }

    try {
        Rachete rachete;
        rachete.citesteDate(argv[1]);
        Asteroizi asteroizi;
        asteroizi.citesteDate(argv[2]);
        Piata piata;
        piata.citesteDate(argv[3]);

        std::vector<Misiune> istoric_misiuni;
        std::map<std::string, double> profit_per_resursa;

        for (auto& racheta : rachete.getRacheteRef()) {
            for (auto& asteroid : asteroizi.getAsteroiziRef()) {
                if (asteroid.cantitate_totala <= 0) continue;

                double extras = racheta.capacitate_transport * asteroid.randament;
                if (extras > asteroid.cantitate_totala) extras = asteroid.cantitate_totala;

                asteroid.cantitate_totala -= extras;

                // drum dus intors
                double distanta_totala = asteroid.distanta * 2.0;
                double combustibil_consumat = (distanta_totala / 1000.0) * racheta.consum_combustibil;
                double cost_combustibil = combustibil_consumat * racheta.pret_combustibil;

                Resursa& res = piata.getResursaRef(asteroid.resursa);
                double pret_curent = res.getPretCurent();

                double profit_brut = extras * pret_curent;
                double profit_net = profit_brut - cost_combustibil;

                res.cantitate_minata += extras;
                racheta.profit_net_total += profit_net;
                racheta.misiuni_realizate++;
                profit_per_resursa[res.nume] += profit_brut;

                istoric_misiuni.emplace_back(racheta.id, asteroid.id, res.nume, extras, combustibil_consumat, cost_combustibil, profit_brut, profit_net);
            }
        }

        Misiune::scrieMisiuni("raport_misiuni.csv", istoric_misiuni);

        std::cout << "\n SIMULARE FINALIZATA\n";
        std::cout << "Raportul a fost generat in fisierul 'raport_misiuni.csv'.\n\n";

        std::cout << "PROFIT BRUT PER RESURSA\n";
        for (const auto& p : profit_per_resursa) {
            std::cout << "- " << p.first << ": $" << std::fixed << std::setprecision(2) << p.second << "\n";
        }

        auto lista_rachete = rachete.getRacheteRef();
        std::sort(lista_rachete.begin(), lista_rachete.end(), [](const Racheta& a, const Racheta& b) {
            return a.getScorEficienta() > b.getScorEficienta();
        });

        std::cout << "\n CLASAMENT RACHETE (Scor Eficienta)\n";
        int loc = 1;
        for (const auto& r : lista_rachete) {
            std::cout << loc++ << ". " << r.id << " Profit Net Total: " << r.profit_net_total
                      << " | Misiuni: " << r.misiuni_realizate
                      << " | Eficienta: " << r.getScorEficienta() << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "\nEroare critica: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
