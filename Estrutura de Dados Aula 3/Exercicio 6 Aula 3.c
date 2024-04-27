#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

int valpre(char *expressaoPrefixa) {
    Pilha PilhaB = pilha(256);
    for(int i = strlen(expressaoPrefixa+1); i>=0; i--)
        if( isdigit(expressaoPrefixa[i]) ) empilha(expressaoPrefixa[i]-'0',PilhaB);
        else {
            int y = desempilha(PilhaB);
            int x = desempilha(PilhaB);
            switch( expressaoPrefixa[i] ) {
                case '+': empilha(x+y,PilhaB); break;
                case '-': empilha(x-y,PilhaB); break;
                case '*': empilha(x*y,PilhaB); break;
                case '/': empilha(y/x,PilhaB); break;
            }
        }
    int resultado = desempilha(PilhaB);
    destroip(&PilhaB);
    return resultado;
}

char *prefixa(char *expressaoInfixa) {
  int j = 0;
  static char expressaoPrefixa[256];
  Pilha PilhaA = pilha(256);
  for(int i = strlen(expressaoInfixa); i>=0; i--){
    if( isdigit(expressaoInfixa[i]) ) {
      expressaoPrefixa[j++] = expressaoInfixa[i];
    } else if( strchr("+*-/",expressaoInfixa[i]) ) {
      empilha(expressaoInfixa[i], PilhaA);
    } else if( expressaoInfixa[i]=='(' ) {
      expressaoPrefixa[j++] = desempilha(PilhaA);
    }
  }
  _strrev(expressaoPrefixa);
  expressaoPrefixa[j] = '\0';
  destroip(&PilhaA);
  return expressaoPrefixa;
}

int main(void) {
  char expressaoInfixa[513];
  printf("Infixa? ");
  gets(expressaoInfixa);
  printf("Prefixa: %s\n", prefixa(expressaoInfixa));
  printf("Resultado: %i", valpre(prefixa(expressaoInfixa)));
  return 0;
}

