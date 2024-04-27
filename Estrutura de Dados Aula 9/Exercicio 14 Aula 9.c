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

  void ins(Item x, Lista *L) {
     while(*L != NULL) 
        L = &(*L)->prox;
     *L = no(x,*L);
  }

void exibe(Lista L) {
	while( L != NULL ) {
	printf("%d\n",L->item);
	L = L->prox;
	}
}

int oed(Lista L){
    while( L != NULL ){
        int x = L->item;
        int y = L->prox;
        if(x<=y){
            return(0);
        }
        L=L->prox;
    }
    return(1);
}

int main(void) {
   Lista I = NULL;
   ins(5,&I);
   ins(5,&I);
   ins(4,&I);
   ins(3,&I);
   ins(2,&I);
   ins(1,&I);
   exibe(I);
   printf("%d", oed(I));
   return 0;
}
