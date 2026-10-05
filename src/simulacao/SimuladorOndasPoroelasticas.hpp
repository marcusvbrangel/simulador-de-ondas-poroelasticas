#pragma once

#include <cstddef>
#include <iostream>
#include <vector>

#include "../fisica/ModeloPoroelastico.hpp"
#include "../modelo/ParametrosSimulacao.hpp"
#include "../modelo/ResultadoSimulacao.hpp"

class SimuladorOndasPoroelasticas {

private:

    ModeloPoroelastico& modelo;

    static void validar(ParametrosSimulacao& parametros) {

        std::cout << "Validando o intervalo de " << parametros.getFrequenciaInicial()
                  << " Hz a " << parametros.getFrequenciaFinal() << " Hz e a quantidade de "
                  << parametros.getNumeroPontos() << " pontos.\n";
    }

    static void reservarResultados(ResultadoSimulacao& resultado, std::size_t tamanho) {

        std::cout << "Reservando espaco para " << tamanho
                  << " resultados; existem atualmente "
                  << resultado.getFrequencias().size() << " frequencias armazenadas.\n";
    }

public:

    explicit SimuladorOndasPoroelasticas(ModeloPoroelastico& modelo)
        : modelo(modelo) {

        std::cout << "Inicializando o simulador de ondas poroelasticas.\n";
    }

    ResultadoSimulacao executar(ParametrosSimulacao& parametros) {

        std::cout << "Executando a simulacao de ondas poroelasticas entre "
                  << parametros.getFrequenciaInicial() << " Hz e "
                  << parametros.getFrequenciaFinal() << " Hz, com "
                  << parametros.getNumeroPontos() << " pontos.\n";

        return {};
    }

    std::vector<double> gerarFrequencias(ParametrosSimulacao& parametros) {

        std::cout << "Gerando " << parametros.getNumeroPontos()
                  << " frequencias de " << parametros.getFrequenciaInicial()
                  << " Hz ate " << parametros.getFrequenciaFinal() << " Hz.\n";

        return {};
    }

    void calcularDispersao() {

        std::cout << "Calculando a dispersao das ondas poroelasticas.\n";
    }

    void calcularAtenuacao() {

        std::cout << "Calculando a atenuacao das ondas poroelasticas.\n";
    }
};
