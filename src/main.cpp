#include <iostream>

#include "fisica/ModeloBiotNaoDissipativo.hpp"
#include "simulacao/SimuladorOndasPoroelasticas.hpp"

int main() {
    ModeloBiotNaoDissipativo modelo;
    SimuladorOndasPoroelasticas simulador(modelo);

    ParametrosSimulacao parametros{};
    parametros.frequenciaInicial = 10.0;
    parametros.frequenciaFinal = 1000.0;
    parametros.numeroPontos = 20;

    const auto resultado = simulador.executar(parametros);
    std::cout << "Pontos de frequencia: " << resultado.frequencias.size() << '\n';
    return 0;
}
