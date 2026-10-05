#include <iostream>

#include "fisica/ModeloBiotNaoDissipativo.hpp"
#include "simulacao/SimuladorOndasPoroelasticas.hpp"

int main() {

    ModeloBiotNaoDissipativo modelo;

    SimuladorOndasPoroelasticas simulador(modelo);

    ParametrosSimulacao parametros{};

    parametros.setFrequenciaInicial(10.0);

    parametros.setFrequenciaFinal(1000.0);

    parametros.setNumeroPontos(20);

    auto resultado = simulador.executar(parametros);

    std::cout << "Pontos de frequencia: " << resultado.getFrequencias().size() << '\n';

    return 0;
}
