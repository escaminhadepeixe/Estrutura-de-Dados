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

void pertence(int X, Lista L)
{
        while (L!= NULL) 
        {
            if(L->item== X)
            {
                printf("%d pertence à lista",X);
                return;
            }
             L=L->prox;
        }   
        printf("%d não pertence à lista", X);
}




int main(void) {
    int pertencente=0;
    printf("Digite o numero para a verificação \n");
    scanf("%d",&pertencente);
    Lista H = no(4,no(2, no(5, no(15, no(4,no(2, no(5, no(1,NULL))))))));
    pertence(pertencente, H);
    return 0;
}
