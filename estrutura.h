#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include "requisicao.h"

/* Ocultamento de informação: o teste.c só enxerga o ponteiro */
typedef struct fila Estrutura;

/* Funções obrigatórias para o teste.c rodar */
Estrutura *create();
void inserir(Estrutura *estrutura, Requisicao *requisicao);
Requisicao *remover(Estrutura *estrutura);
int get_size(Estrutura *estrutura);
void libera_estrutura(Estrutura *estrutura);
// Libera a memória alocada para uma requisição
void libera(Requisicao *requisicao);

#endif