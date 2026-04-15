# Desafio 1: Gerenciador de Fila de Atendimento de Saúde

[![Linguagem: C](https://img.shields.io/badge/Linguagem-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Status: Concluído](https://img.shields.io/badge/Status-Concluído-success.svg)]()

## 📌 Sobre o Projeto

Este projeto foi desenvolvido como requisito de avaliação da disciplina de Estruturas de Dados do curso de Análise e Desenvolvimento de Sistemas (ADS) do SENAI. 

O objetivo principal é a implementação de um **Tipo Abstrato de Dados (TAD) Opaco** para gerenciar milhares de requisições de atendimento de saúde. A estrutura de dados escolhida para a solução foi uma **Fila (Queue) baseada em Lista Encadeada**, garantindo que os pacientes sejam processados estritamente por ordem de chegada (FIFO - *First In, First Out*).

## 🚀 Funcionalidades e Requisitos Atendidos

- **Encapsulamento (TAD Opaco):** A estrutura interna da Fila está totalmente ocultada no arquivo `.c`, expondo apenas o ponteiro da estrutura no cabeçalho `.h`.
- **Desempenho Otimizado $O(1)$:** A implementação utiliza ponteiros de rastreamento para o `inicio` e o `fim` da fila. Isso garante que as operações de **inserção** e **remoção** ocorram em tempo constante, sem a necessidade de percorrer a estrutura.
- **Gerenciamento de Memória Seguro:** Utilização rigorosa de `malloc` e `free` para a alocação dinâmica de cada nó da fila, evitando *memory leaks* (vazamento de memória).
- **Contagem em Tempo Real:** A função `get_size()` retorna a quantidade de pacientes em espera de forma instantânea $O(1)$.

## 📂 Estrutura de Arquivos

* `estrutura.h` / `estrutura.c` : Definição e implementação da Fila (TAD).
* `requisicao.h` / `requisicao.c` : Definição e implementação dos dados do paciente (Nome, Inscrição, Procedimento).
* `teste.c` : Código principal (`main`) fornecido pelo professor para validação do sistema.

## ⚙️ Como Compilar e Executar

Para compilar o projeto, é necessário ter o compilador **GCC** instalado. No terminal, navegue até a pasta do projeto e execute os comandos abaixo:

1. **Gerar os arquivos objetos (`.o`):**
   ```bash
   gcc -c requisicao.c estrutura.c teste.c

2. **Gerar executável:**
   ```bash
gcc requisicao.o estrutura.o teste.o -o desafio

3. **Executar o programa:**
   ***No windows:*** .\desafio.exe
   ***No Linux/Mac:*** ./desafio