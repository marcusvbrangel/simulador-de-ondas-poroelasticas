#pragma once

#include <iostream>

#include "ModeloPoroelastico.hpp"

class ModeloBiotJKD final : public ModeloPoroelastico {

public:

    PropriedadesOnda calcular(double frequencia) {

        std::cout << "Calculando as propriedades da onda com o modelo de Biot JKD em "
                  << frequencia << " Hz.\n";

        return {};
    }
};
