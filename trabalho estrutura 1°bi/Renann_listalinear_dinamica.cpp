 //Fila Com Alocação Dinamica
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

struct no *inicio = NULL;
struct no *fim_fila = NULL;

int tamanho=0;

struct no{
	int dado;
	struct no *prox;
};

void insere(int valor) {
	struct no *aux;
	aux = new(struct no);
	aux->dado = valor;

	if(tamanho==0) { //caso seja o primeiro elemento faz com que os ponteiros inicio e fim apontem para ele
		inicio = aux;
		fim_fila = aux;
	}

	fim_fila->prox = aux; // faz com que o ponteiro prox que fim aponta aponte para aux
	fim_fila = aux; //fim recebe aux
	aux->prox = NULL; //ponteiro prox de aux recebe null(ou seja fim da fila)

	tamanho++;//conta quantos elementos tem na fila
	printf("\n\n\nElemento inserido com sucesso");
}

void exibir_fila() {
	struct no *aux;

	if(inicio==NULL) {
		printf("\tERRO: Fila vazia");
		return;
	}

	aux=inicio;

	while(aux!=NULL) {
		printf(" %d |", aux -> dado);
		aux = aux->prox;
	}
}

void remover() {
	struct no *aux;

	if(inicio==NULL) {
		printf("\tERRO: Fila vazia");
		return;
	}
	aux = inicio;
	inicio = inicio->prox; //inicio recebe o proximo elemento da fila
	delete(aux);
	tamanho--;
	printf("\n\nElemento removido com sucesso\n");
}

void menu() {
	printf("ACADEMICO: RENANN R. DA SILVA - RA:13106523\n");
	printf("\n##############################################");
	printf("\n#               MENU - FILA                  #");
	printf("\n#                                            #");
	printf("\n#	  Digite a op\207\706o desejada            #");
	printf("\n#                                            #");
	printf("\n#	 1 = Inserir elemento                #");
	printf("\n#	 2 = Remover elemento                #");
	printf("\n#	 3 = Exibir fila                     #");
	printf("\n#	 4 = Mostrar primeiro elemento       #");
	printf("\n#	 5 = Sair                            #");
	printf("\n#                                            #");
	printf("\n##############################################");
	printf("\n\n");
}

void mostrar_primeiro() {
	if(inicio==NULL) {
		printf("\tERRO: Fila vazia");
		return;
	}
	printf("\nO primeiro elemento da fila = %d", inicio->dado);
}

main() {

	int opcao,valor;
	bool i=true;

	menu();

	do {
		opcao = getche()-'0';

		switch(opcao) {
			case 1:
				system ("cls");
				menu();
				printf("\nDigite o valor a ser inserido ");
				scanf("%d", &valor);
				insere(valor);
				printf("\n\n\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 2:
				system ("cls");
				menu();
				remover();
				printf("\n\n\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 3:
				system ("cls");
				menu();
				exibir_fila();
				printf("\n\n\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 4:
				system ("cls");
				menu();
				mostrar_primeiro();
				printf("\n\n\n\nEscolha outra op\207\706o para continuar...\n\n");
				break;
			case 5:
				system ("cls");
				printf("\n\n\t\tAt\202 logo !!\n\n\n\n\n\n\n\n\n\n");
				i=false;
				break;
		}
	}
	while(i==true);

	system ("pause");
}
