#pragma once

#include "PropriedadesMeioPoroso.hpp"

struct ParametrosSimulacao {
    double frequenciaInicial{};
    double frequenciaFinal{};
    int numeroPontos{};
    PropriedadesMeioPoroso propriedadesMeioPoroso{};
};
