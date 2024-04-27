#include <stdio.h>

int h(int n) {
    if (n == 1) {
        return 1;
    } else {
        return 2 * h(n - 1) + 1;
    }
}

int main() {
    int n;
    printf("Digite o número de discos: ");
    scanf("%d", &n);
    printf("O número mínimo de movimentos é: %d\n", h(n));
    return 0;
}