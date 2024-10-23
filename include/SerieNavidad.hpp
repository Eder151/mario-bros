#include <iostream>
#include <Foco.hpp>
#include <list>
using namespace std;

class SerieNavidad
{
private:
    std::list<Foco> focos;

public:
    SerieNavidad(int noFocos)
    {
        for (size_t i = 0; i < noFocos; i++)
        {
            Foco foco1;
            this->focos.emplace_back(foco1);
            /* code */
        }

        Foco foco;
        Foco foco1;
        Foco foco2;
        Foco foco3;

        focos.emplace_back(foco1);
        focos.emplace_back(foco2);
        focos.emplace_back(foco3);
    }
    ~SerieNavidad() {}
    void Encender()
    {
        for (auto &&f : focos)
        {
            f.Encender();
        }
    }
    void Imprimir()
    {

        for (auto &&focoActual : focos)
        {
            std::cout
                << focoActual.Imprimir()
                << "-";
        }
        std::cout << std::endl;
    }
};