#include <stdio.h>

int prod(int m, int n)
{
    if(n==0)
    {
        return 0;
    }
    else
    {
        return m+prod(m, n-1);
          
    }   
    
}

int main() 
{
    int m, n = 0; 
    printf("Digite o numero");
    scanf("%d",&m);
    printf("Digite quantas vezes o numero será multiplicado");
    scanf("%d",&n);
    m=prod(m,n);
    printf("%d", m);
    return 0;
}
