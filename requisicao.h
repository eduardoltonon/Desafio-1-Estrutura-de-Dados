#ifndef REQUISICAO_H
#define REQUISICAO_H

// Definição da estrutura baseada nos dados do PDF
typedef struct requisicao {
    char nome[41]; // 40 caracteres + \0
    int inscricao;
    char procedimento[11]; // 10 caracteres + \0
} Requisicao;

// Funções que o teste.c exige
Requisicao *cria_requisicao(char *nome, int inscricao, char *procedimento);
char *get_nome(Requisicao *requisicao);
int get_inscricao(Requisicao *requisicao);
char *get_procedimento(Requisicao *requisicao);

#endif