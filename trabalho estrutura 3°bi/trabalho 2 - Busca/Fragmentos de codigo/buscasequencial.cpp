#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 100
int aux_busca_seq = 0, vetor[TAM];


void cria_vetor() {
	int i;
	for (i=0;i<=TAM-1;i++)
      	vetor[i]=rand()%TAM;//Cria vetor randômico
}

void imprimir(){
	int i;
	for(i=0; i<=TAM-1; i++){
		printf("%d ", vetor[i]);
	}
	printf("\n\n");
}

int busca_sequencial(int chave){
	int i=0;
    /*for (i=0;i<((TAM) && (chave>vetor[i]));i++){
        aux_busca_seq++;
		if (chave == vetor[i])
            return 1;
    }
    return 0;*/
    
    while((i < TAM)){
    	aux_busca_seq++;
		if (chave == vetor[i]){
			printf("\n i = %d\n" ,i);
			return 1;
				
		}
            
        i++;
    }
    return 0;
}


main(){
	int chave;
	printf("\n\nhaha\n\n");
	
	cria_vetor();
	imprimir();
	chave = 11;
	printf("chave %d\n", chave);
	
	printf("%s", busca_sequencial(chave) ?"achei": "nao achei");
	printf("\n%d", aux_busca_seq);
	getch();
}
