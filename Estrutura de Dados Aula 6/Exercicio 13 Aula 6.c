#include <stdio.h>

int q(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 2*n - 1 + q(n - 1);
    }
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("O quadrado de %d é: %d\n", n, q(n));
    return 0;
}
