#include <stdio.h>

int par(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        if(n==0)
        {
            return 0;    
        }
        
        par(n-2);
    }
        
    
}

int main() 
{
    int n = 0; 
    printf("Digite");
    scanf("%d",&n);
    n=par(n);
    if(n==0)
    {
        printf("é par");
    }
    else
    {
        printf("é ímpar");
    }
    return 0;
}
