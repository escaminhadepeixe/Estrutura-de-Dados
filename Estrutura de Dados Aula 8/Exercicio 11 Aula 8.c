#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
Item item;
struct no *prox;
} *Lista;

typedef int Itemp;

typedef struct pilha {
   int    max;
   int    topo;
   Itemp *item;
} *Pilha;

Pilha pilha(int m) {
   Pilha P = malloc(sizeof(struct pilha));
   P->max  = m;
   P->topo = -1;
   P->item = malloc(m*sizeof(Itemp));
   return P;
}

void empilha(Itemp x, Pilha P) {
   if( cheiap(P) ) { puts("pilha cheia!"); abort(); }
   P->topo++;
   P->item[P->topo] = x;
}

Itemp topo(Pilha P) {
   if( vaziap(P) ) { puts("pilha vazia!"); abort(); }
   return P->item[P->topo];
}



Itemp desempilha(Pilha P) {
   if( vaziap(P) ) { puts("pilha vazia!"); abort(); }
   Itemp x = P->item[P->topo];
   P->topo--;
   return x; 
}

int cheiap(Pilha P) {
   if( P->topo == P->max-1 ) return 1;
   else return 0;
}

int vaziap(Pilha P) {
   if( P->topo == -1 ) return 1;
   else return 0;
}

Lista no(Item x, Lista p) {
Lista n = malloc(sizeof(struct no));
n->item = x;
n->prox = p;
return n;
}


void exibe(Lista B) {
    while( B != NULL ) {
        printf("%d\n",B->item);
        B = B->prox;
    }
}

void inverte(int tamanho, Lista L)
{
    Pilha A = pilha(tamanho);
    Pilha B = pilha(tamanho);
    
    while (L!= NULL) 
    {
        empilha(L->item, A);
        L=L->prox;
            
    }   
    
    while (!vaziap(A)) 
    {   
        empilha(desempilha(A), B);
    } 
    
    L = NULL;
    while (!vaziap(B)) 
    {   
        L = no(desempilha(B), L);
    }  
    
   
    exibe(L);
        
}

int tamanho(Lista L) {
     int t = 0;
     while( L ) {
        t++;
        L = L->prox;
     }
     return t; 
  }
  
int main(void) {
    int size=0;
    Lista H = no(1,no(2, no(3, no(4, no(5,no(6, no(7, no(8,NULL))))))));
    size=tamanho(H);
    inverte(size, H);
    
    return 0;
}
    