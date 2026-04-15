#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "requisicao.h"

Requisicao *cria_requisicao(char *nome, int inscricao, char *procedimento) {
    Requisicao *nova = (Requisicao*) malloc(sizeof(Requisicao));
    if (nova != NULL) {
        strncpy(nova->nome, nome, 40);
        nova->nome[40] = '\0'; // Garante finalização da string
        nova->inscricao = inscricao;
        strncpy(nova->procedimento, procedimento, 10);
        nova->procedimento[10] = '\0';
    }
    return nova;
}

char *get_nome(Requisicao *requisicao) {
    return requisicao->nome;
}

int get_inscricao(Requisicao *requisicao) {
    return requisicao->inscricao;
}

char *get_procedimento(Requisicao *requisicao) {
    return requisicao->procedimento;
}
void libera(Requisicao *requisicao) {
    if (requisicao != NULL) {
        free(requisicao);
    }
}