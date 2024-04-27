#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void ordenarPilha(Pilha A, Pilha B) {
    while (!vaziap(A))
    {
        //Salva o ultimo item desempilhado para comparação
        int compara = desempilha(A);

        // Se pilha B não estiver vazia e o seu topo for maior que o ultimo item desempilhado em A
        while (!vaziap(B) && topo(B) > compara) {
        //Desempilha o topo de B e empilha em A
            empilha(desempilha(B), A);
        }
        empilha(compara, B);
    }

    // Move os elementos de B de volta para A
    while (!vaziap(B)) {
        empilha(desempilha(B), A);
    }
}

int main() {
    int tamanho;
    printf("Digite o tamanho da sequencia: ");
    scanf("%d", &tamanho);

    //Cria pilha 
    Pilha A = pilha(tamanho);
    Pilha B = pilha(tamanho);

    printf("Digite a sequencia de numeros:\n");
    for (int i = 0; i < tamanho; i++) 
    {
        int num;
        scanf("%d", &num);
        empilha(num, A);
    }

    ordenarPilha(A, B);

    printf("Sequencia ordenada:\n");
    while (!vaziap(A)) {
        printf("%d\n", desempilha(A));
    }

    destroip(&A);
    destroip(&B);

    return 0;
}