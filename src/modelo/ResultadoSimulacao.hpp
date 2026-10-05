#pragma once

#include <vector>

struct ResultadoSimulacao {
    std::vector<double> frequencias;
    std::vector<double> velocidadeFaseP1;
    std::vector<double> velocidadeFaseP2;
    std::vector<double> velocidadeFaseT;
    std::vector<double> atenuacaoP1;
    std::vector<double> atenuacaoP2;
    std::vector<double> atenuacaoT;
};
