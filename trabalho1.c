#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct endereco {
    char endereco[255];
    struct Endereco *proximo;
} Endereco;

Endereco *end_anteriores;
int end_anteriores_tam;
Endereco *end_futuros;
char end_atual[255];

void menu() {
	if(end_atual != NULL){
		printf("\n \t\t Endereco atual: %s \n", end_atual);	
	}
    printf("\n###################################################");
    printf("\n#                      MENU                       #");
    printf("\n#                                                 #");
    printf("\n#             Digite a opcao desejada             #");
    printf("\n#                                                 #");
    printf("\n#  1. Informar um novo endereco;                  #");
    printf("\n#  2. Voltar ao endereco anterior;                #");
    printf("\n#  3. Voltar N enderecos;                         #");
    printf("\n#  4. Mostrar historico dos enderecos antes;      #");
    printf("\n#  5. Avancar para o proximo endereco;            #");
    printf("\n#  6. Avancar N enderecos;                        #");
    printf("\n#  7. Mostrar enderecos que foram visitados apos; #");
    printf("\n#  8. Sair do programa.                           #");
    printf("\n#                                                 #");
    printf("\n###################################################");
    printf("\n\n");
}

void informar_endereco() {
	char endereco[255];
	Endereco *aux, *novo_end;
	int tam = 0;
	
	gets(endereco);
		
	if(strcmpi(end_atual, "") == 0) {
		strcpy(end_atual, endereco);
	} 
	else {
		novo_end = malloc(sizeof (Endereco));
		novo_end->proximo = NULL;
		strcpy(novo_end->endereco, end_atual);
		
		if(end_anteriores->proximo == NULL) {
			end_anteriores->proximo = novo_end;
		}else {
			aux = end_anteriores->proximo;
		
			while(aux->proximo != NULL) {
				aux = aux->proximo;
				tam++;
			}
			
			aux->proximo = novo_end;
		}
		strcpy(end_atual, endereco);
		end_anteriores_tam++;
	}
	system("cls");
	menu();
}

void mostrar_historico() {
	int opcao, tam = 1;
	Endereco *aux;
	
	system("cls");

	aux = end_anteriores->proximo;
	printf("\n Historico de enderecos visitados: \n");
	
	while(aux != NULL) {
		printf("\n\t\t n%d> %s", tam, aux->endereco);
		aux = aux->proximo;
		tam++;
	}
	
	menu();
}

void avancar() {
	printf("avançar");
}

void avancar_n_enderecos(int num){
	printf("avançar N enderecos");
}

void voltar(){
	printf("voltar");
}

void voltar_n_enderecos(int num){
	printf("voltar N enderecos");
}

int main() {
    int opcao;
    bool i;
    i = true;
    
    end_anteriores = malloc(sizeof (Endereco));
    end_anteriores->proximo = NULL;
    
    menu();
    
    do {
        opcao = getche()-'0';
        switch(opcao) {
            case 1:
                system("cls");
                printf("\n Para qual endereco deseja ir? ");
            	informar_endereco();
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 2:
                system ("cls");
                menu();
                printf("\n Digite o valor a ser buscado ");
               
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 3:
                system ("cls");
                menu();
                printf("\nDigite o valor a ser buscado ");
               
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 4:
                system ("cls");
                mostrar_historico();
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 5:
                system ("cls");
                menu();
                printf("\nDigite o valor a ser buscado ");
               
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 6:
                system ("cls");
                menu();
                printf("\nDigite o valor a ser buscado ");
               
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 7:
                system ("cls");
                menu();
                printf("\nDigite o valor a ser buscado ");
               
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 8:
                system ("cls");
                printf("\n\n\t\tSaindo...\n\n\n\n\n\n\n\n\n\n");
                i=false;
                break;
        }
    }
    while(i == true);
	
    system("pause");
}
