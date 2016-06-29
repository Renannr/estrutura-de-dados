#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 10

clock_t Inicio;
clock_t Fim;

int vetor[TAM], tam_heap=0; 


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

// HEAPSORT
void heapify(int i){
	int L,r,max=0,aux=0;
	L = (2*i)+1;
	r = (2*i)+2;
	
	if((L<tam_heap) && (vetor[L]>vetor[i])){
		max = L;	
	}
	else
		max = i;
	
	if((r<tam_heap) && (vetor[r]>vetor[max]))
		max = r;
		
	if(max != i){
		aux = vetor[i];
		vetor[i] = vetor[max];
		vetor[max] = aux;
		heapify(max);	
	}
		
}
void build_healp(){
	int i;
	tam_heap = TAM;
	
	for (i = ((TAM/2) - 1); i >= 0; i--)
        heapify(i);	
}

void heapsort(){
	int aux=0,k;
	
	build_healp();
	for(k=(TAM-1);k >= 1;k--){
		aux = vetor[0];
		vetor[0] = vetor[k];
		vetor[k] = aux; 
		tam_heap--;
		heapify(0);
	}
}
//------------------------------------------------------------------------------

main(){
	cria_vetor();
	imprime();
	printf("\npre teste\n");
	
	heapsort();
	printf("\npos teste\n");
	imprime();
	getch();
}
