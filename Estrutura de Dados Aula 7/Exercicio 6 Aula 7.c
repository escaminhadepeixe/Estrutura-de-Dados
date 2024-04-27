#include <stdio.h>

void exibe (int v[], int i){
	for(int j = 0; j < i; j++){
	    if(j==i-1){
	       printf("%d ", v[j]); 
	    }else{
		    printf("%d, ", v[j]);
	    }
	}
}
void preenche(int v[], int n, int s) {
    srand(s); // definida em stdlib.h
    for(int i=0; i<n; i++) v[i] = rand()%1000;
}


int main(void) 
{
    
    int v[10];
    preenche(v,10,10);
    exibe(v,10);
    return 0;
}
