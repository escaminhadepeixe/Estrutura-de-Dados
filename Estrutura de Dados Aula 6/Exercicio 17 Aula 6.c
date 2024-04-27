#include <stdio.h>
#include <string.h>

void inv(char* s, int p, int u) {
    if (p < u) {
        char temp = s[p];
        s[p] = s[u];
        s[u] = temp;
        inv(s, p + 1, u - 1);
    }
}

int main() {
    char s[100];
    printf("Digite uma string: ");
    fgets(s, sizeof(s), stdin);
    s[strlen(s) - 1] = '\0';  
    inv(s, 0, strlen(s) - 1);
    printf("A string invertida é: %s\n", s);
    return 0;
}
