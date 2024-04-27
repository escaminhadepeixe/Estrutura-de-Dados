#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
Item item;
struct no *prox;
} *Lista;


Lista no(Item x, Lista p) {
Lista n = malloc(sizeof(struct no));
n->item = x;
n->prox = p;
return n;
}


void exibe(Lista L) {
while( L != NULL ) {
printf("%d\n",L->item);
L = L->prox;
}
}

void Ultimo(Lista L)
{
    if (L == NULL) 
    {
        printf("A lista está vazia.\n");
        return;
    }

    while (L->prox != NULL) 
    {
        L = L->prox;
    }

    printf("O último número da lista é: %d\n", L->item);
}



int main(void) {
    int tamanho, ult=0;
    Lista H = no(4,no(2,NULL));
    Ultimo(H);
return 0;
}
