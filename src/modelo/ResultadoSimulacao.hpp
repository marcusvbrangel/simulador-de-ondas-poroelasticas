#pragma once

#include <vector>

class ResultadoSimulacao {

private:

    std::vector<double> frequencias{};

    std::vector<double> velocidadeFaseP1{};

    std::vector<double> velocidadeFaseP2{};

    std::vector<double> velocidadeFaseT{};

    std::vector<double> atenuacaoP1{};

    std::vector<double> atenuacaoP2{};

    std::vector<double> atenuacaoT{};

public:

    std::vector<double> getFrequencias() {

        return frequencias;
    }

    void setFrequencias(std::vector<double> novasFrequencias) {

        frequencias = novasFrequencias;
    }

    std::vector<double> getVelocidadeFaseP1() {

        return velocidadeFaseP1;
    }

    void setVelocidadeFaseP1(std::vector<double> novaVelocidadeFaseP1) {

        velocidadeFaseP1 = novaVelocidadeFaseP1;
    }

    std::vector<double> getVelocidadeFaseP2() {

        return velocidadeFaseP2;
    }

    void setVelocidadeFaseP2(std::vector<double> novaVelocidadeFaseP2) {

        velocidadeFaseP2 = novaVelocidadeFaseP2;
    }

    std::vector<double> getVelocidadeFaseT() {

        return velocidadeFaseT;
    }

    void setVelocidadeFaseT(std::vector<double> novaVelocidadeFaseT) {

        velocidadeFaseT = novaVelocidadeFaseT;
    }

    std::vector<double> getAtenuacaoP1() {

        return atenuacaoP1;
    }

    void setAtenuacaoP1(std::vector<double> novaAtenuacaoP1) {

        atenuacaoP1 = novaAtenuacaoP1;
    }

    std::vector<double> getAtenuacaoP2() {

        return atenuacaoP2;
    }

    void setAtenuacaoP2(std::vector<double> novaAtenuacaoP2) {

        atenuacaoP2 = novaAtenuacaoP2;
    }

    std::vector<double> getAtenuacaoT() {

        return atenuacaoT;
    }

    void setAtenuacaoT(std::vector<double> novaAtenuacaoT) {

        atenuacaoT = novaAtenuacaoT;
    }
};
