#include <stdio.h>
#include <stdlib.h>
#include "estrutura.h"

/* * 1. Nó da Fila
 * Estrutura interna que segura a requisição e aponta para a próxima.
 * O teste.c não faz ideia que isto existe (Encapsulamento).
 */
typedef struct no {
    Requisicao *requisicao;
    struct no *prox;
} No;

/* * 2. Definição real do TAD Opaco
 * É aqui que a "Estrutura" (struct fila) ganha forma.
 */
struct fila {
    No *inicio;
    No *fim;
    int tamanho; // Mantém a contagem O(1) para o get_size
};

// Inicializa a fila
Estrutura *create() {
    Estrutura *f = (Estrutura*) malloc(sizeof(Estrutura));
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}

// Inserção otimizada O(1) - Insere sempre no FIM
void inserir(Estrutura *estrutura, Requisicao *requisicao) {
    if (estrutura == NULL || requisicao == NULL) return;

    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return; // Falha na alocação de memória

    novo->requisicao = requisicao;
    novo->prox = NULL;

    // Se a fila estiver vazia, o novo nó é o início e o fim ao mesmo tempo
    if (estrutura->inicio == NULL) {
        estrutura->inicio = novo;
    } else {
        // Se não, o último nó atual passa a apontar para este novo
        estrutura->fim->prox = novo;
    }
    
    // O novo nó torna-se oficialmente o fim da fila
    estrutura->fim = novo;
    estrutura->tamanho++;
}

// Remoção otimizada O(1) - Remove sempre do INÍCIO (FIFO)
Requisicao *remover(Estrutura *estrutura) {
    if (estrutura == NULL || estrutura->inicio == NULL) return NULL;

    No *no_removido = estrutura->inicio;
    Requisicao *req = no_removido->requisicao; // Salvaguarda a requisição

    // O início avança para o próximo nó
    estrutura->inicio = estrutura->inicio->prox;

    // Se o início ficou nulo após a remoção, a fila esvaziou. O fim deve ser nulo também.
    if (estrutura->inicio == NULL) {
        estrutura->fim = NULL;
    }

    free(no_removido); // Liberta a memória do nó (evita memory leaks)
    estrutura->tamanho--;

    return req; // Devolve a requisição para a aplicação poder usá-la
}

// Retorna a quantidade em O(1)
int get_size(Estrutura *estrutura) {
    if (estrutura == NULL) return 0;
    return estrutura->tamanho;
}

// Limpeza total de memória (Critério rigoroso de avaliação)
void libera_estrutura(Estrutura *estrutura) {
    if (estrutura != NULL) {
        No *atual = estrutura->inicio;
        while (atual != NULL) {
            No *prox = atual->prox;
            // Se a requisição ainda estiver lá dentro, liberta-a também
            if (atual->requisicao != NULL) {
                free(atual->requisicao);
            }
            free(atual); // Liberta o nó da fila
            atual = prox;
        }
        free(estrutura); // Liberta a estrutura principal
    }
}