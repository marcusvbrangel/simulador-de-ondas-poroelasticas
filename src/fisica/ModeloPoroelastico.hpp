#pragma once

#include <iostream>

#include "../modelo/PropriedadesOnda.hpp"

class ModeloPoroelastico {

public:

    virtual ~ModeloPoroelastico() {

        std::cout << "Finalizando o modelo poroelastico.\n";
    }

    virtual PropriedadesOnda calcular(double frequencia) = 0;
};

inline PropriedadesOnda ModeloPoroelastico::calcular(double frequencia) {

    std::cout << "Calculando as propriedades da onda com o modelo poroelastico base em "
              << frequencia << " Hz.\n";

    return {};
}
