#pragma once

#include "../modelo/PropriedadesOnda.hpp"

class ModeloPoroelastico {
public:
    virtual ~ModeloPoroelastico() = default;
    virtual PropriedadesOnda calcular(double frequencia) const = 0;
};
