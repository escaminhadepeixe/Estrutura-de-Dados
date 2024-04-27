#include <stdio.h>



void empurra(int v[], int PosicaoDestino){
  int NumeroMaior, IndiceMaior;
	for(int i = 0; i<PosicaoDestino; i++){
	    if(v[i]>NumeroMaior){
	        IndiceMaior = i;
	        NumeroMaior = v[i];
	    }
	}
	
	for(int i = IndiceMaior; i<PosicaoDestino; i++){
	    v[i] = v[i+1]; 
	}
	
	v[PosicaoDestino] = NumeroMaior;

}

void troca(int v[], int i, int j) {
	int x = v[i];
	v[i] = v[j];
	v[j] = x;
}

int bsr(int v[], int n)
{
    if (n == 1)
        return;
   
  
    for (int i=0; i<n-1; i++) {
        if (v[i] > v[i+1]) {
            troca(v, i, i+1);
        }
    }
   
    bsr(v, n-1);
}


void bsort(int v[], int n) {
	for(int i=1; i<n; i++)
		for(int j=0; j<n-i; j++)
			if( v[j]>v[j+1] )
				troca(v,j,j+1);
}

void exibe (int v[], int i){
	for(int j = 0; j < i; j++){
	    if(j==i-1){
	       printf("%d ", v[j]); 
	    }else{
		    printf("%d, ", v[j]);
	    }
	}
}


int main(void) {
	int v[9] = {51,82,38,99,75,19,69,46,27};
    bsr(v,9);
    exibe(v,9);
	return 0;
}
