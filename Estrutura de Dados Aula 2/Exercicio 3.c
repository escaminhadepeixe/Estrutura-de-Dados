#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

// Função para inverter a ordem das letras em uma palavra
void inverterPalavra(char *palavra) {
    int tamanho = strlen(palavra);
    Pilha p = pilha(tamanho); // Cria uma pilha do tamanho da palavra

    // Empilha cada letra da palavra na pilha
    for (int i = 0; i < tamanho; i++) {
        empilha(palavra[i], p);
    }

    // Desempilha as letras da pilha para reverter a ordem
    for (int i = 0; i < tamanho; i++) {
        palavra[i] = desempilha(p);
    }

    destroip(&p); // Libera a memória da pilha
}

// Função para inverter as palavras em uma frase
void inverterFrase(char *frase) {
    char *palavra = strtok(frase, " "); // Divide a frase em palavras, separação por espaços
    while (palavra != NULL) {
        inverterPalavra(palavra); // Inverte a palavra
        printf("%s ", palavra); // Exibe a palavra invertida
        palavra = strtok(NULL, " "); // Pega a próxima palavra
    }
}

int main() {
    char frase[100];
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Frase com palavras invertidas:\n");
    inverterFrase(frase);
    printf("\n");

    return 0;
}