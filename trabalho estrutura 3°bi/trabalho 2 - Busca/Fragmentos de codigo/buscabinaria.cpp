#include<conio.h>
#include<stdio.h>
#define TAM 10

int aux_busca_seq = 0,aux_busca_bin = 0, vetor[TAM];

int busca_binaria(int chave){
    int esq=0, dir=(TAM-1), meio=0;
    while (esq<=dir){
        meio = (esq+dir)/2;
        if (chave == vetor[meio]){
            aux_busca_bin++;
            return 1;
        }
        if (chave<vetor[meio]){
            dir = meio-1;
            aux_busca_bin++;
        }
        else{
            esq = meio+1;
            aux_busca_bin++;
        }
    }
    return 0;
}


main(){
	
	printf("haha");
	getch();
}
