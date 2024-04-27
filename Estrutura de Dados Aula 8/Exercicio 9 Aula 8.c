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

void Maximo(Lista L)
{
    int maior, atual =0;
    if (L == NULL) 
    {
        printf("A lista está vazia.\n");
        return;
    }
     maior = L->item;
    while (L!= NULL) 
    {
        while (L!= NULL) 
        {
            atual=L->item;
            if(atual>maior)
            {
                maior=atual;
            }
            L= L->prox;
            
        }   
    }
    printf("O Maior número da lista é: %d\n", maior);
}



int main(void) {
    int tamanho, ult=0;
    Lista H = no(4,no(2, no(5, no(15, no(4,no(2, no(5, no(1,NULL))))))));
    Maximo(H);
    return 0;
}
