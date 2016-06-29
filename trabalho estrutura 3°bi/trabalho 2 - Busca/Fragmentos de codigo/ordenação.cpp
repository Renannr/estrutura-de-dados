#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 5000

int vetor[TAM];

void cria_vetor() {
	int i,aux;
	
	for (i=0;i<TAM;i++)
      	vetor[i]=rand();//Cria vetor randômico
}

// 			quicksort
int partition(int p, int r) {
    int piv = vetor[p], i = (p - 1), j = (r + 1), aux = 0;
    
	while(1) {
        while(vetor[--j] > piv);
        while(vetor[++i] < piv);
        
	    if(i < j) {
	    	aux = vetor[i];
	        vetor[i] = vetor[j];
	        vetor[j] = aux;
	    } 
		else
	    	return j;
    }
 
}
void quicksort(int p, int r) {
    int q=0;
	if(p < r) {
        q = partition(p, r);
        quicksort(p, q);
        quicksort((q+1), r);
    }
}
//------------------------------------------------------------------------------
