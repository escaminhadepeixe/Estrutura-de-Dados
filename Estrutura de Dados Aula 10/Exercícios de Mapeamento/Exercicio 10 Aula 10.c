#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Chave[22];
typedef char Valor[22];
typedef struct map {
    Chave chave;
    Valor valor;
    struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p) {
    Map n = malloc(sizeof(struct map));
    strcpy(n->chave,c);
    strcpy(n->valor,v);
    n->prox = p;
    return n;
}

void insm(Chave c, Valor v, Map *M) {
    while(*M)
        M = &(*M)->prox;
    if( *M && strcmp(c,(*M)->chave))
        strcpy((*M)->valor,v);
    else *M = no_map(c,v,*M);
}

void exibem(Map M) {
    printf("[");
    while( M ) {
        printf("(%s,%s)",M->chave,M->valor);
        if( M->prox ) printf(",");
        M = M->prox;
    }
    printf("]\n");
}

int main(void) {
    Map I = NULL;
    insm("a","Leo",&I);
    insm("b","Ivo",&I);
    insm("c","Eva",&I);
    insm("e","Ana",&I);
    exibem(I);
    return 0;
}
