#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int valor(char *e) {
    Pilha P = pilha(256);
    for(int i=0; e[i]; i++)
        if(e[i]=='V'){
            empilha(1, P);
        }
        else if(e[i]=='F'){
            empilha(0, P);
        }
        else if(e[i]=='!'){
            int x = desempilha(P);
            empilha(!x, P);
        }
        else {
            int y = desempilha(P);
            int x = desempilha(P);
            if(e[i]=='|'){
                empilha(x||y, P);
            }
            else if(e[i]=='&'){
                empilha(x&&y,P);
            }
        }
    int z = desempilha(P);
    destroip(&P);
    return z;
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);
    for(int i=0; e[i]; i++)
        if(e[i]=='V'||e[i]=='F'){
            s[j++] = e[i];
        }
        else if(strchr("!&|",e[i])){
            empilha(e[i], P);
        }
        else if( e[i]==')' ){
            s[j++] = desempilha(P);
        } 
    s[j] = '\0';
    destroip(&P);
    return s;
}

int main(void) {
    char e[513];
    printf("Infixa? ");
    gets(e);
    printf("Posfixa: %s\n", posfixa(e));
    printf("Valor: %d\n", valor(posfixa(e)));
    return 0;
}
