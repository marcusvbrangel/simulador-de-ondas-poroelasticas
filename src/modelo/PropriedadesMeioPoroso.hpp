#pragma once

class PropriedadesMeioPoroso {

private:

    double densidadeRocha = 0.0;

    double porosidade = 0.0;

    double permeabilidade = 0.0;

    double tortuosidade = 0.0;

    double expoenteCimentacao = 0.0;

    double densidadeFluido = 0.0;

    double viscosidade = 0.0;

    double coeficienteTermico = 0.0;

    double condutividadeTermica = 0.0;

    double calorEspecifico = 0.0;

    double temperaturaReferencia = 0.0;

    double tempoRelaxacao = 0.0;

public:

    double getDensidadeRocha() {

        return densidadeRocha;
    }

    void setDensidadeRocha(double novaDensidadeRocha) {

        densidadeRocha = novaDensidadeRocha;
    }

    double getPorosidade() {

        return porosidade;
    }

    void setPorosidade(double novaPorosidade) {

        porosidade = novaPorosidade;
    }

    double getPermeabilidade() {

        return permeabilidade;
    }

    void setPermeabilidade(double novaPermeabilidade) {

        permeabilidade = novaPermeabilidade;
    }

    double getTortuosidade() {

        return tortuosidade;
    }

    void setTortuosidade(double novaTortuosidade) {

        tortuosidade = novaTortuosidade;
    }

    double getExpoenteCimentacao() {

        return expoenteCimentacao;
    }

    void setExpoenteCimentacao(double novoExpoenteCimentacao) {

        expoenteCimentacao = novoExpoenteCimentacao;
    }

    double getDensidadeFluido() {

        return densidadeFluido;
    }

    void setDensidadeFluido(double novaDensidadeFluido) {

        densidadeFluido = novaDensidadeFluido;
    }

    double getViscosidade() {

        return viscosidade;
    }

    void setViscosidade(double novaViscosidade) {

        viscosidade = novaViscosidade;
    }

    double getCoeficienteTermico() {

        return coeficienteTermico;
    }

    void setCoeficienteTermico(double novoCoeficienteTermico) {

        coeficienteTermico = novoCoeficienteTermico;
    }

    double getCondutividadeTermica() {

        return condutividadeTermica;
    }

    void setCondutividadeTermica(double novaCondutividadeTermica) {

        condutividadeTermica = novaCondutividadeTermica;
    }

    double getCalorEspecifico() {

        return calorEspecifico;
    }

    void setCalorEspecifico(double novoCalorEspecifico) {

        calorEspecifico = novoCalorEspecifico;
    }

    double getTemperaturaReferencia() {

        return temperaturaReferencia;
    }

    void setTemperaturaReferencia(double novaTemperaturaReferencia) {

        temperaturaReferencia = novaTemperaturaReferencia;
    }

    double getTempoRelaxacao() {

        return tempoRelaxacao;
    }

    void setTempoRelaxacao(double novoTempoRelaxacao) {

        tempoRelaxacao = novoTempoRelaxacao;
    }
};
