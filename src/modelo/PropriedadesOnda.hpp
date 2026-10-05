#pragma once

class PropriedadesOnda {

private:

    double velocidadeFaseP1 = 0.0;

    double velocidadeFaseP2 = 0.0;

    double velocidadeFaseT = 0.0;

    double atenuacaoP1 = 0.0;

    double atenuacaoP2 = 0.0;

    double atenuacaoT = 0.0;

public:

    double getVelocidadeFaseP1() {

        return velocidadeFaseP1;
    }

    void setVelocidadeFaseP1(double novaVelocidadeFaseP1) {

        velocidadeFaseP1 = novaVelocidadeFaseP1;
    }

    double getVelocidadeFaseP2() {

        return velocidadeFaseP2;
    }

    void setVelocidadeFaseP2(double novaVelocidadeFaseP2) {

        velocidadeFaseP2 = novaVelocidadeFaseP2;
    }

    double getVelocidadeFaseT() {

        return velocidadeFaseT;
    }

    void setVelocidadeFaseT(double novaVelocidadeFaseT) {

        velocidadeFaseT = novaVelocidadeFaseT;
    }

    double getAtenuacaoP1() {

        return atenuacaoP1;
    }

    void setAtenuacaoP1(double novaAtenuacaoP1) {

        atenuacaoP1 = novaAtenuacaoP1;
    }

    double getAtenuacaoP2() {

        return atenuacaoP2;
    }

    void setAtenuacaoP2(double novaAtenuacaoP2) {

        atenuacaoP2 = novaAtenuacaoP2;
    }

    double getAtenuacaoT() {

        return atenuacaoT;
    }

    void setAtenuacaoT(double novaAtenuacaoT) {

        atenuacaoT = novaAtenuacaoT;
    }
};
