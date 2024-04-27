#include <stdio.h>

int quoc(int m, int n)
{
    if(m<n)
    {
        return 0;
    }
    else
    {
        return 1+quoc(m-n, n);
          
    }   
    
}

int main() 
{
    int m, n = 0; 
    printf("Digite o numero");
    scanf("%d",&m);
    printf("Digite por quanto o numero será dividido");
    scanf("%d",&n);
    m=quoc(m,n);
    printf("%d", m);
    return 0;
}
