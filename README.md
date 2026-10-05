# Simulador de Ondas Poroelásticas

## Introdução

Projeto em C++ para simular a propagação de ondas em meios poroelásticos — materiais sólidos porosos preenchidos por fluido, como solos, rochas e reservatórios saturados.

### Objetivo

O sistema foi concebido para calcular a resposta de um meio poroso ao longo de uma faixa de frequências. Para cada frequência, a simulação deve determinar a velocidade de fase e a atenuação dos três modos de onda previstos pela teoria de Biot:

- `P1`: onda compressional rápida;
- `P2`: onda compressional lenta;
- `T`: onda transversal ou de cisalhamento.

### Arquitetura

O código-fonte está dividido em quatro partes principais:

- **Modelo de dados (`src/modelo`)**: reúne os parâmetros da simulação, as propriedades físicas do meio poroso, as propriedades calculadas das ondas e os resultados consolidados.
- **Modelos físicos (`src/fisica`)**: contém a interface abstrata `ModeloPoroelastico` e as formulações físicas que a especializam.
- **Solução numérica (`src/numerico`)**: concentra os algoritmos destinados à resolução de sistemas e raízes complexas das equações poroelásticas.
- **Orquestração (`src/simulacao`)**: gera as frequências, executa o modelo físico selecionado e organiza os resultados.

#### Modelos físicos previstos

- `ModeloBiotNaoDissipativo`: formulação de Biot sem perdas dissipativas;
- `ModeloBiotDissipativo`: formulação com dissipação viscosa;
- `ModeloBiotJKD`: formulação JKD, que representa efeitos dinâmicos dependentes da frequência.

Todos implementam a interface `ModeloPoroelastico`, permitindo que o simulador utilize diferentes formulações sem depender de suas implementações concretas.

### Fluxo da simulação

1. O usuário informa a faixa de frequências, a quantidade de pontos e as propriedades do meio poroso.
2. `SimuladorOndasPoroelasticas` valida os parâmetros e gera uma malha linear de frequências.
3. Para cada frequência, o simulador chama `ModeloPoroelastico::calcular`.
4. O modelo físico deve usar as propriedades do meio e o solucionador numérico para calcular as ondas `P1`, `P2` e `T`.
5. As velocidades de fase e atenuações são armazenadas em `ResultadoSimulacao`.

### Estado atual

A estrutura arquitetural e o fluxo de orquestração já estão definidos. O simulador valida o intervalo informado, gera as frequências e prepara corretamente os vetores de resultados.

O arquivo `src/main.cpp` demonstra esse fluxo com o modelo não dissipativo e 20 pontos entre 10 e 1000. Entretanto, ainda não fornece propriedades físicas reais ao meio.

O projeto encontra-se em uma etapa inicial: os métodos dos três modelos físicos ainda retornam valores zerados, o solucionador numérico ainda não resolve as equações e as propriedades do meio poroso ainda não estão integradas aos cálculos. Assim, a implementação atual representa um esqueleto funcional da arquitetura, mas ainda não produz resultados científicos reais.

### Próximas etapas

- implementar as equações constitutivas dos modelos de Biot e JKD;
- integrar `PropriedadesMeioPoroso` aos modelos físicos;
- implementar a resolução dos sistemas e das raízes complexas;
- converter as soluções complexas em velocidade de fase e atenuação;
- validar os resultados com casos analíticos ou dados de referência;
- adicionar testes automatizados para os modelos e para o fluxo da simulação.

### Referências internas

- `contexto-diagrama-poroelasticidade.md`: descrição conceitual do domínio e da arquitetura;
- `diagrama-uml-quantidade-classes-reduzidas-e-nomes-representativos.jpeg`: diagrama UML das classes e de seus relacionamentos.

## Estrutura do Projeto

```text
simulador-de-ondas-poroelasticas/
├── src/
│   ├── fisica/
│   │   ├── ModeloPoroelastico.hpp
│   │   ├── ModeloBiotNaoDissipativo.hpp
│   │   ├── ModeloBiotDissipativo.hpp
│   │   └── ModeloBiotJKD.hpp
│   ├── modelo/
│   │   ├── ParametrosSimulacao.hpp
│   │   ├── PropriedadesMeioPoroso.hpp
│   │   ├── PropriedadesOnda.hpp
│   │   └── ResultadoSimulacao.hpp
│   ├── numerico/
│   │   └── SolucionadorEquacoesPoroelasticas.hpp
│   ├── simulacao/
│   │   └── SimuladorOndasPoroelasticas.hpp
│   └── main.cpp
├── contexto-diagrama-poroelasticidade.md
├── diagrama-uml-quantidade-classes-reduzidas-e-nomes-representativos.jpeg
└── README.md
```

- `src/fisica`: contratos e implementações dos modelos físicos poroelásticos.
- `src/modelo`: estruturas de entrada, propriedades físicas e resultados.
- `src/numerico`: métodos para resolução das equações poroelásticas.
- `src/simulacao`: coordenação do fluxo da simulação.
- `src/main.cpp`: ponto de entrada e exemplo de execução do programa.
