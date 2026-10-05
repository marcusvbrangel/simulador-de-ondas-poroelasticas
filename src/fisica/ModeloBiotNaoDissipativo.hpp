#pragma once

#include <iostream>

#include "ModeloPoroelastico.hpp"

class ModeloBiotNaoDissipativo final : public ModeloPoroelastico {

public:

    PropriedadesOnda calcular(double frequencia) {

        std::cout << "Calculando as propriedades da onda com o modelo de Biot nao dissipativo em "
                  << frequencia << " Hz.\n";

        return {};
    }
};
