#include <stdio.h>

int main (void)
{
    int n, f;
    printf ("numero? \n");
    scanf("%d", &n);
    f=1;
    for (int i=2; i<=n; i++)
    {
        f*=i;
    }
    printf("Fatorial %d \n", f);
    return 0;

    
}