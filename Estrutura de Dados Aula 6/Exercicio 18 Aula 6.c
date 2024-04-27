#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char* s, int p, int u) {
    
    while (s[p] == ' ') p++;
    while (s[u] == ' ') u--;

   
    if (p >= u) {
        return 1;
    }
        else if (s[p] == s[u]) {
        return is_palindrome(s, p + 1, u - 1);
    }
    else {
        return 0;
    }
}

int main() {
    char s[100];
    printf("Digite uma string: ");
    fgets(s, sizeof(s), stdin);
    for(int i=0; s[i];i++)
    {
        s[i]=toupper(s[i]);
    }
    s[strlen(s) - 1] = '\0'; 
    if (is_palindrome(s, 0, strlen(s) - 1)) {
        printf("palíndromo.\n");
    } else {
        printf("não é um palíndromo.\n");
    }
    return 0;
}
