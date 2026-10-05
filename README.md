# Simulador de Ondas Poroelásticas

## 01 — Introdução

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

## 02 — Estrutura do Projeto

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

## 03 — Instalação e Execução do Simulador

O projeto não utiliza bibliotecas externas nem exige CMake no estado atual. Ele depende apenas de um compilador compatível com C++17 e da biblioteca padrão do C++, instalada junto com o compilador.

### Windows 11 — PowerShell

No Windows, será utilizado o GCC fornecido pelo ambiente MSYS2. Todos os comandos de compilação e execução poderão ser feitos no PowerShell.

#### 1. Verificar as ferramentas

Abra o PowerShell e verifique se o compilador já está disponível:

```powershell
g++ --version
```

Se o comando mostrar a versão do GCC, avance para a etapa de compilação. Caso o PowerShell informe que `g++` não foi encontrado, faça a instalação abaixo.

O Git é necessário apenas para baixar ou atualizar o projeto por meio do repositório remoto. Verifique-o com:

```powershell
git --version
```

#### 2. Instalar o compilador

Verifique se o gerenciador de pacotes do Windows está disponível:

```powershell
winget --version
```

Instale o MSYS2:

```powershell
winget install --exact --id MSYS2.MSYS2
```

Após a instalação, abra **MSYS2 UCRT64** pelo menu Iniciar e atualize seus pacotes:

```bash
pacman -Syu
```

Se o terminal solicitar que seja fechado, abra novamente o **MSYS2 UCRT64**, repita `pacman -Syu` e instale o GCC:

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-gcc
```

Feche e abra novamente o PowerShell. Para disponibilizar o compilador na sessão atual, execute:

```powershell
$env:Path = "C:\msys64\ucrt64\bin;$env:Path"
g++ --version
```

Esse ajuste vale apenas para a janela atual. Para torná-lo permanente, adicione `C:\msys64\ucrt64\bin` à variável de ambiente `Path` do usuário nas configurações do Windows.

Caso o Git também não esteja instalado, execute:

```powershell
winget install --exact --id Git.Git
```

#### 3. Preparar e compilar o código-fonte

No PowerShell, entre na pasta raiz do projeto e crie o diretório de compilação:

```powershell
Set-Location "C:\caminho\para\simulador-de-ondas-poroelasticas"
New-Item -ItemType Directory -Force build | Out-Null
```

Compile o programa diretamente com o GCC:

```powershell
g++ -std=c++17 -Wall -Wextra -Wpedantic src\main.cpp -o build\simulador.exe
```

Se o comando terminar sem mensagens de erro, a compilação foi concluída.

#### 4. Executar o simulador

```powershell
.\build\simulador.exe
```

Na implementação atual, a saída esperada é:

```text
Pontos de frequencia: 20
```

### Linux Ubuntu

#### 1. Verificar as ferramentas

Abra o terminal e verifique se o compilador já está instalado:

```bash
g++ --version
```

Se o comando mostrar a versão do GCC, avance para a etapa de compilação. O Git, necessário apenas para baixar ou atualizar o repositório, pode ser verificado com:

```bash
git --version
```

#### 2. Instalar o compilador e as ferramentas básicas

Atualize a lista de pacotes e instale o conjunto de desenvolvimento do Ubuntu:

```bash
sudo apt update
sudo apt install build-essential
```

O pacote `build-essential` inclui o GCC, o G++, a biblioteca padrão e outras ferramentas básicas de compilação.

Se também precisar instalar o Git:

```bash
sudo apt install git
```

Confirme a instalação:

```bash
g++ --version
```

#### 3. Preparar e compilar o código-fonte

Entre na pasta raiz do projeto, crie o diretório de compilação e compile o programa:

```bash
cd /caminho/para/simulador-de-ondas-poroelasticas
mkdir -p build
g++ -std=c++17 -Wall -Wextra -Wpedantic src/main.cpp -o build/simulador
```

Se o comando terminar sem mensagens de erro, a compilação foi concluída.

#### 4. Executar o simulador

```bash
./build/simulador
```

Na implementação atual, a saída esperada é:

```text
Pontos de frequencia: 20
```
