#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 10

clock_t Inicio;
clock_t Fim;

int vetor[TAM],scratch[TAM]; 


void cria_vetor() {
   int i;
   for (i=0;i<TAM;i++)
      	vetor[i]=rand()%50;//Cria vetor randômico
}

void imprime(){ //imprime o vetor
	int i;
	for(i=0;i<TAM;i++){
		printf(" %d", vetor[i]);
		if(i == 50)
			printf("\n");
	}
}

//     mergesort

void mergesort(int baixo, int alto){
	int mid = 0, l = 0, h = 0, k = 0;
	
	if(baixo < alto){
		mid = (baixo + alto)/2;
		
		mergesort(baixo,mid);
		mergesort((mid + 1),alto);
	
		l = baixo;
		h = mid+1;
	
		for(k = baixo;k <= alto; k++){
			if((l <= mid) && ((h > alto) || (vetor[l] < vetor[h])))
				scratch[k] = vetor[l++];
			else
				scratch[k] = vetor[h++];
		}
			
		for(k = baixo; k <= alto; k++)
			vetor[k] = scratch[k];
	}
}
//------------------------------------------------------------------------------









main(){
	
	cria_vetor();
	imprime();
	printf("\nTeste\n");
	mergesort(0,TAM-1);
	imprime();
	getch();
}

