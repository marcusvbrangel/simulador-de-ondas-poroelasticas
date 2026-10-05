#pragma once

#include <cmath>
#include <stdexcept>
#include <vector>

#include "../fisica/ModeloPoroelastico.hpp"
#include "../modelo/ParametrosSimulacao.hpp"
#include "../modelo/ResultadoSimulacao.hpp"

class SimuladorOndasPoroelasticas {
public:
    explicit SimuladorOndasPoroelasticas(const ModeloPoroelastico& modelo)
        : modelo(modelo) {}

    ResultadoSimulacao executar(const ParametrosSimulacao& parametros) const {
        validar(parametros);

        ResultadoSimulacao resultado;
        resultado.frequencias = gerarFrequencias(parametros);
        reservarResultados(resultado, resultado.frequencias.size());

        for (std::size_t i = 0; i < resultado.frequencias.size(); ++i) {
            const auto propriedades = modelo.calcular(resultado.frequencias[i]);
            resultado.velocidadeFaseP1[i] = propriedades.velocidadeFaseP1;
            resultado.velocidadeFaseP2[i] = propriedades.velocidadeFaseP2;
            resultado.velocidadeFaseT[i] = propriedades.velocidadeFaseT;
            resultado.atenuacaoP1[i] = propriedades.atenuacaoP1;
            resultado.atenuacaoP2[i] = propriedades.atenuacaoP2;
            resultado.atenuacaoT[i] = propriedades.atenuacaoT;
        }

        return resultado;
    }

    std::vector<double> gerarFrequencias(const ParametrosSimulacao& parametros) const {
        validar(parametros);
        std::vector<double> frequencias;
        frequencias.reserve(static_cast<std::size_t>(parametros.numeroPontos));

        if (parametros.numeroPontos == 1) {
            frequencias.push_back(parametros.frequenciaInicial);
            return frequencias;
        }

        const double passo =
            (parametros.frequenciaFinal - parametros.frequenciaInicial) /
            static_cast<double>(parametros.numeroPontos - 1);
        for (int i = 0; i < parametros.numeroPontos; ++i) {
            frequencias.push_back(parametros.frequenciaInicial + i * passo);
        }
        return frequencias;
    }

    void calcularDispersao() const {}
    void calcularAtenuacao() const {}

private:
    const ModeloPoroelastico& modelo;

    static void validar(const ParametrosSimulacao& parametros) {
        if (parametros.numeroPontos <= 0) {
            throw std::invalid_argument("numeroPontos deve ser maior que zero");
        }
        if (!std::isfinite(parametros.frequenciaInicial) ||
            !std::isfinite(parametros.frequenciaFinal) ||
            parametros.frequenciaInicial > parametros.frequenciaFinal) {
            throw std::invalid_argument("intervalo de frequencia invalido");
        }
    }

    static void reservarResultados(ResultadoSimulacao& resultado, std::size_t tamanho) {
        resultado.velocidadeFaseP1.resize(tamanho);
        resultado.velocidadeFaseP2.resize(tamanho);
        resultado.velocidadeFaseT.resize(tamanho);
        resultado.atenuacaoP1.resize(tamanho);
        resultado.atenuacaoP2.resize(tamanho);
        resultado.atenuacaoT.resize(tamanho);
    }
};
