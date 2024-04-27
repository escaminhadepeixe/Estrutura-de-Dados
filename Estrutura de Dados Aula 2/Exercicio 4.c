#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilha.h"

// Função para verificar se um caractere é um dos delimitadores: {, }, [, ], (, ou )
bool ehDelimitador(char ch) {
    return (ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == '(' || ch == ')');
}

// Função para verificar se dois delimitadores abrem e fecham corretamente
bool correspondente(char aberto, char fechado) {
    return ((aberto == '(' && fechado == ')') ||
            (aberto == '[' && fechado == ']') ||
            (aberto == '{' && fechado == '}'));
}

// Função para verificar se a expressão está balanceada
bool expressaoBalanceada(char *expressao) {
    Pilha p = pilha(strlen(expressao)); // Cria uma pilha do tamanho da expressão

    for (int i = 0; expressao[i] != '\0'; i++) {
        char ch = expressao[i];
        if (ehDelimitador(ch)) {
            if (ch == '{' || ch == '[' || ch == '(') {
                empilha(ch, p); // Empilha delimitadores de abertura
            } else {
                if (vaziap(p)) {
                    destroip(&p);
                    return false; // Expressão desbalanceada se o delimitador de fechamento nao tiver um de abertura
                }
                char topo = desempilha(p); // Desempilha o delimitador de abertura correspondente
                if (!correspondente(topo, ch)) {
                    destroip(&p);
                    return false; // Expressão desbalanceada se os delimitadores não corresponderem
                }
            }
        }
    }

    bool balanceada = vaziap(p); // A expressão está balanceada se a pilha estiver vazia no final
    destroip(&p);
    return balanceada;
}

int main() {
    char expressao[100];
    printf("Digite uma expressao contendo apenas chaves, colchetes e parenteses: ");
    fgets(expressao, sizeof(expressao), stdin);

    // Remover o caractere de nova linha se existir
    if (expressao[strlen(expressao) - 1] == '\n') {
        expressao[strlen(expressao) - 1] = '\0';
    }

    if (expressaoBalanceada(expressao)) {
        printf("A expressao esta balanceada.\n");
    } else {
        printf("A expressao nao esta balanceada.\n");
    }

    return 0;
}
