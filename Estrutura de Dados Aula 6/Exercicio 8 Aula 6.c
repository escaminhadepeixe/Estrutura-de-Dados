#include <stdio.h>

void hanoi(int n, char origem, char auxiliar, char destino) {
    if (n == 1) {
        printf("Mova o disco 1 da torre %c para a torre %c.\n", origem, destino);
        return;
    }
    hanoi(n-1, origem, destino, auxiliar);
    printf("Mova o disco %d da torre %c para a torre %c.\n", n, origem, destino);
    hanoi(n-1, auxiliar, origem, destino);
}

int main() {
    int n = 3; 
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
