#pragma once

#include "ModeloPoroelastico.hpp"

class ModeloBiotDissipativo final : public ModeloPoroelastico {
public:
    PropriedadesOnda calcular(double frequencia) const override {
        (void)frequencia;
        return {};
    }
};
