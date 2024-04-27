#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Chave;
typedef int Valor;
typedef struct map {
    Chave chave;
    Valor valor;
    struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p) {
    Map n = malloc(sizeof(struct map));
    n->chave = c;
    n->valor = v;
    n->prox = p;
    return n;
}

void insm(Chave c, Valor v, Map *M) {
    while( *M && c>(*M)->chave )
        M = &(*M)->prox;
    if( *M && c==(*M)->chave ){
        v=(*M)->valor;
    }
    else *M = no_map(c,v,*M);
    
}

void exibem(Map M) {
    printf("[");
    while( M ) {
        printf("(%d,%d)",M->chave,M->valor);
        if( M->prox ) printf(",");
        M = M->prox;
    }
    printf("]\n");
}

int main(void) {
    Map I = NULL;
    insm(36,3,&I);
    insm(15,1,&I);
    insm(42,4,&I);
    insm(29,2,&I);
    exibem(I);
    return 0;
}
