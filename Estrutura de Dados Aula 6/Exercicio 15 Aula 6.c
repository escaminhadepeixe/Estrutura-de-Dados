#include <stdio.h>

int qd(int n) {
    if (n == 0) {
        return 1;
    } 
    else
    {
        if(n==1)
        {
            return 1;
        }
        else {
       return 1+qd(n/2);
       
        }
    }
    }


int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("%d em binário possui: %d dígitos \n", n, qd(n));
    return 0;
}
