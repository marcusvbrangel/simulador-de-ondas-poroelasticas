# Contexto do diagrama UML: Simulação de Ondas Poroelásticas

Este diagrama representa um sistema de simulação computacional para analisar a propagação de ondas em meios poroelásticos, como solos, rochas porosas ou materiais saturados.

## Visão geral
O fluxo do sistema parte da classe `Simulacao`, responsável por coordenar toda a execução da análise. Ela recebe os parâmetros de simulação, define as frequências de estudo, chama os cálculos físicos e retorna um objeto `ResultadoSimulacao` com os dados finais.

## Estrutura conceitual

### 1) Simulação
`Simulacao`
- É a classe principal do processo.
- Recebe os parâmetros do problema.
- Gera as frequências de análise.
- Executa os procedimentos de cálculo.
- Produz o resultado consolidado.

### 2) Modelo de dados e resultados
`ResultadoSimulacao`
- Armazena os resultados da simulação.
- Contém valores como frequências, velocidades, atenuação, amplitude e outros parâmetros calculados.

`PropriedadesMeioPoroso`
- Representa as propriedades físicas do meio poroso.
- Inclui grandezas como densidade, porosidade, permeabilidade, módulo de elasticidade, viscosidade, temperatura, etc.

### 3) Modelo físico
`ModeloPoroelastico`
- É a classe base da parte física do sistema.
- Define a lógica comum para o cálculo das propriedades de onda.
- Possui o método `calcular(frequencia)` para obter as propriedades da onda em função da frequência.

Especializações:
- `ModeloBiotNaoDissipativo`: modelo de Biot sem dissipação.
- `ModeloBiotDissipativo`: modelo de Biot com dissipação.
- `ModeloBiotJKD`: modelo de Biot com abordagem JKD.

Essas subclasses representam diferentes formulações físicas para descrever a propagação de ondas em meios poroelásticos.

### 4) Solução numérica
`SolucionadorEquacoesPoroelasticas`
- Resolve as equações matemáticas que descrevem o comportamento do meio.
- Recebe os dados do modelo físico e produz as grandezas numéricas do sistema.
- Calcula valores como velocidade complexa e resposta em frequência.

## Relações principais
- `Simulacao` usa o modelo físico para calcular a resposta do sistema.
- `ResultadoSimulacao` guarda os resultados gerados pela simulação.
- `ModeloPoroelastico` depende de `PropriedadesMeioPoroso` para definir o comportamento mecânico do material.
- `SolucionadorEquacoesPoroelasticas` é a camada numérica responsável por resolver as equações associadas ao modelo.

## Interpretação funcional
O diagrama descreve um fluxo de modelagem e simulação:
1. o usuário define as condições do problema;
2. a simulação organiza os cálculos;
3. o modelo físico representa o comportamento do meio poroso;
4. a solução numérica calcula a resposta da onda;
5. os resultados são armazenados para análise.

Em resumo, o sistema é uma arquitetura para simular a propagação de ondas em materiais poroelásticos, integrando parâmetros físicos, formulações constitutivas e métodos numéricos de resolução.

# Código atual da implementação
A pasta `src` está organizada em quatro diretórios que correspondem aos pacotes do diagrama:

- `src/modelo`: contém `ParametrosSimulacao`, `PropriedadesMeioPoroso`, `PropriedadesOnda` e `ResultadoSimulacao`.
- `src/fisica`: contém a classe abstrata `ModeloPoroelastico` e suas especializações `ModeloBiotNaoDissipativo`, `ModeloBiotDissipativo` e `ModeloBiotJKD`.
- `src/numerico`: contém `SolucionadorEquacoesPoroelasticas`.
- `src/simulacao`: contém `SimuladorOndasPoroelasticas`, que gera as frequências, chama o modelo físico e organiza os resultados.

O arquivo `src/main.cpp` instancia um modelo, configura uma faixa de frequências e executa uma simulação de demonstração. A estrutura e os nomes agora refletem os pacotes e as classes do diagrama UML. Os algoritmos físicos de Biot e a resolução numérica ainda são pontos de extensão: seus métodos permanecem como esqueletos e não produzem resultados físicos reais.
