#include <stdio.h>

int resto(int m, int n)
{
    if(m<n)
    {
        return m;
    }
    else
    {
        return resto(m-n, n);
          
    }   
    
}

int main() 
{
    int m, n = 0; 
    printf("Digite o numero ");
    scanf("%d",&m);
    printf("Digite por quanto o numero será dividido ");
    scanf("%d",&n);
    m=resto(m,n);
    printf(" Resto: %d", m);
    return 0;
}
