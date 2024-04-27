#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
   Item item;
   struct no *prox;
} *Lista;

void exibe(Lista L) {
	while( L != NULL ) {
	printf("%d\n",L->item);
	L = L->prox;
	}
}

Lista no(Item x, Lista p) {
	Lista n = malloc(sizeof(struct no));
	n->item = x;
	n->prox = p;
	return n;
}

void ins_isr(Item x, Lista *L) {
    while(*L != NULL && (*L)->item <= x )
	{
    	if((*L)->item == x){
			return;
		}
		L = &(*L)->prox;
	}
	*L = no(x,*L);
	
 }

int main(void) {
	Lista I = NULL;
  	ins_isr(1,&I);
	ins_isr(2,&I);
	ins_isr(3,&I);
	ins_isr(3,&I);
	ins_isr(3,&I);
   	exibe(I);
   return 0;
}
