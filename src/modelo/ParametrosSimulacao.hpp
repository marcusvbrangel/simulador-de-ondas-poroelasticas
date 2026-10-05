#pragma once

#include "PropriedadesMeioPoroso.hpp"

class ParametrosSimulacao {

private:

    double frequenciaInicial = 0.0;

    double frequenciaFinal = 0.0;

    int numeroPontos = 0;

    PropriedadesMeioPoroso propriedadesMeioPoroso{};

public:

    double getFrequenciaInicial() {

        return frequenciaInicial;
    }

    void setFrequenciaInicial(double novaFrequenciaInicial) {

        frequenciaInicial = novaFrequenciaInicial;
    }

    double getFrequenciaFinal() {

        return frequenciaFinal;
    }

    void setFrequenciaFinal(double novaFrequenciaFinal) {

        frequenciaFinal = novaFrequenciaFinal;
    }

    int getNumeroPontos() {

        return numeroPontos;
    }

    void setNumeroPontos(int novoNumeroPontos) {

        numeroPontos = novoNumeroPontos;
    }

    PropriedadesMeioPoroso getPropriedadesMeioPoroso() {

        return propriedadesMeioPoroso;
    }

    void setPropriedadesMeioPoroso(PropriedadesMeioPoroso novasPropriedadesMeioPoroso) {

        propriedadesMeioPoroso = novasPropriedadesMeioPoroso;
    }
};
