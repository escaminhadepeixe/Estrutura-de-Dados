#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

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
  return 0;
}