#include <conio.h>
#include <stdio.h>

struct no{
	int dado;
	struct no *dir;
	struct no *esq;
};

struct no *raiz;

void insere(int valor){
	struct no *aux;
	struct no *atual;
	
	aux = new(struct no);
	aux->esq = NULL;
	aux->dir = NULL;
	aux->dado = valor;
	
	if(raiz == NULL){
		raiz=aux;
		return;
	}
	
	atual = raiz;
	
	while(1){
		if(valor<atual->dado){
			if(atual->esq == NULL){
				atual->esq = aux;
				return;
			}
			else
				atual=atual->esq;	
		}
		
		if(valor>atual->dado){
			if(atual->dir == NULL){
				atual->dir = aux;
				return;
			}
			else
				atual=atual->dir;
		}	
	}
}

main(){
	printf("hue");
}
