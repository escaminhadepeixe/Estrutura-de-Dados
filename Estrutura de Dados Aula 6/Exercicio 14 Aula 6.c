#include <stdio.h>

int sd(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n % 10 + sd(n / 10);
    }
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    printf("A soma dos dígitos de %d é: %d\n", n, sd(n));
    return 0;
}
