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

void ins_rec(Item x, Lista *L)
{
	if(*L != NULL && (*L)->item < x)
	{
		ins_rec(x, &(*L)->prox);
	}else
	{
		*L = no(x,*L);
	}
}

int main(void) {
   Lista I = NULL;
   ins_rec(2,&I);
   ins_rec(1,&I);
   ins_rec(3,&I);
	ins_rec(3,&I);
   exibe(I);
   return 0;
}