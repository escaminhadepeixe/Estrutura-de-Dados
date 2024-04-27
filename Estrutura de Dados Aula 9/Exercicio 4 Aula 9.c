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

void ins_rsr(Item x, Lista *L)
{
	if(*L != NULL && (*L)->item <= x)
	{
		if((*L)->item == x)
		{
			return;
		}
		ins_rsr(x, &(*L)->prox);
	}else
	{
		*L = no(x,*L);
	}
}

int main(void) {
   Lista I = NULL;
   ins_rsr(2,&I);
   ins_rsr(1,&I);
   ins_rsr(3,&I);
	ins_rsr(3,&I);
   exibe(I);
   return 0;
}