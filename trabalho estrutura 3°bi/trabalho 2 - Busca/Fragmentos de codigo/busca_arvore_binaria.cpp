#include<conio.h>
#include<stdio.h>
#define TAM 10

int aux_busca_seq = 0,aux_busca_bin = 0,aux_busca_arvb = 0, vetor[TAM];

struct no *raiz;

struct no{
    int dado;
    struct no *esq;
    struct no *dir;
    int bal;
};
 

int busca_arv_binaria(int chave){
    struct no *atual;
    atual = raiz;
    while(atual!=NULL){
        if (atual->dado == chave){
            aux_busca_arvb++;
            return 1;
        }
        if (chave < atual->dado){
            aux_busca_arvb++;
            atual = atual->esq;
        }
        else{
            aux_busca_arvb++;
            atual = atual->dir;
        }
    }
    return 0;
}



main(){
	
	printf("haha");
	getch();
}
