#include<conio.h>
#include<stdio.h>
#define TAM 10

int aux_busca_seq = 0,aux_busca_bin = 0,aux_busca_arvb = 0,aux_busca_arv_avl = 0, vetor[TAM];

struct no *raiz, *raiz2;

struct no{
    int dado;
    struct no *esq;
    struct no *dir;
    int bal;
};
 

int busca_arv_avl(int chave){
    struct no *atual;
    atual = raiz2;
    while(atual!=NULL){
        if (atual->dado == chave){
            aux_busca_arv_avl++;
            return 1;
        }
        if (chave < atual->dado){
            aux_busca_arv_avl++;
            atual = atual->esq;
        }
        else{
            aux_busca_arv_avl++;
            atual = atual->dir;
        }
    }
    return 0;
}
 


main(){
	
	printf("haha");
	getch();
}
