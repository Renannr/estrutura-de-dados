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
int end_anteriores_tam = 0;

Endereco *end_futuros;
int end_futuros_tam = 0;

char end_atual[255];

void menu() {
    if(end_atual != NULL){
        printf("\n \t\t Endereco atual: %s \n", end_atual); 
    }
    printf("\n#####################################################");
    printf("\n#                      MENU                         #");
    printf("\n#                                                   #");
    printf("\n#             Digite a opcao desejada               #");
    printf("\n#                                                   #");
    printf("\n#  1. Informar um novo endereco;                    #");
    printf("\n#  2. Voltar ao endereco anterior;                  #");
    printf("\n#  3. Voltar N enderecos;                           #");
    printf("\n#  4. Mostrar enderecos que foram visitados antes;  #");
    printf("\n#  5. Avancar para o proximo endereco;              #");
    printf("\n#  6. Avancar N enderecos;                          #");
    printf("\n#  7. Mostrar enderecos que foram visitados apos;   #");
    printf("\n#  8. Sair do programa.                             #");
    printf("\n#                                                   #");
    printf("\n#                                                   #");
    printf("\n#####################################################");
    printf("\n\n");
}

// 1
void informar_endereco() {
    char endereco[255];
    Endereco *aux, *novo_end;
    int tam = 0;
    
    gets(endereco);
    
    end_futuros->proximo = NULL;
        
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

// 4
void mostrar_historico() {
    int opcao, tam = 1;
    Endereco *aux;
    
    system("cls");

    aux = end_anteriores->proximo;
    printf("\n Historico de enderecos visitados antes do atual: %s \n", end_atual);
    
    while(aux != NULL) {
        printf("\n\t\t n%d> %s", tam, aux->endereco);
        aux = aux->proximo;
        tam++;
    }
    
    menu();
}

// 7
void mostrar_futuros() {
    int opcao, tam = 1;
    Endereco *aux;
    
    system("cls");

    aux = end_futuros->proximo;
    printf("\n Historico de enderecos visitados apos o atual: %s \n", end_atual);
    
    while(aux != NULL) {
        printf("\n\t\t n%d> %s", tam, aux->endereco);
        aux = aux->proximo;
        tam++;
    }
    
    menu();
}

// 5
void avancar() {
    Endereco *aux_1, *aux_2, *end_anteriores_aux;

    if(end_futuros->proximo == NULL){
        printf("Nao existem mais enderecos futuros");
        menu();
        return;
    }

    aux_1 = malloc(sizeof (Endereco));
    strcpy(aux_1->endereco, end_atual);
    aux_1->proximo = NULL;
	
	if(end_anteriores->proximo == NULL) {
		end_anteriores->proximo = aux_1;
	}else {
		end_anteriores = end_anteriores->proximo;

        while(end_anteriores->proximo != NULL){
            end_anteriores = end_anteriores->proximo;
        }
        end_anteriores->proximo = aux_1;
	}
	
	aux_2 = end_futuros->proximo;
	
	while(aux_2->proximo != NULL) {
        aux_2 = aux_2->proximo;
    }
    
    strcpy(end_atual, aux_2->endereco);
    
    aux_2 = end_futuros->proximo;

    if(strcmpi(aux_2->endereco, end_atual) == 0){
        end_futuros->proximo = NULL;
    }else {
        while(aux_2->proximo != NULL) {
            Endereco *end;
            end = aux_2->proximo;
            if( strcmpi(end->endereco, end_atual) == 0 ){
                aux_2->proximo = NULL;
                break;
            }
            aux_2 = aux_2->proximo;
        }
    }
    end_futuros_tam--;

    printf(" Situacao: \n");        
    Endereco *print_end_ant = end_anteriores->proximo;
    Endereco *print_end_fut = end_futuros->proximo;

    printf("\n ---End. Anteriores-------- \n");
    while(print_end_ant != NULL){
        printf("%s\n",print_end_ant->endereco);
        print_end_ant = print_end_ant->proximo;
    }
    printf("\n ---End. Futuros------- \n");
    while(print_end_fut != NULL){
        printf("%s\n",print_end_fut->endereco);
        print_end_fut = print_end_fut->proximo;
    }
    printf("Atual : %s\n",end_atual);
    
    menu();
}

// 6
void avancar_n_enderecos(int num) {
	system("cls");
    printf("\n avançar %d enderecos ", num);
    menu();
}

// 2
void voltar() {
    Endereco *aux_1, *aux_2, *end_futuro_aux;

    if(end_anteriores->proximo == NULL){
        printf("Nao existem mais enderecos anteriores");
        menu();
        return;
    }

    aux_1 = malloc(sizeof (Endereco));
    strcpy(aux_1->endereco, end_atual);
    aux_1->proximo = NULL;  

    if(end_futuros->proximo == NULL) {  
        end_futuros->proximo = aux_1;
    }else {
        end_futuro_aux = end_futuros->proximo;

        while(end_futuro_aux->proximo != NULL){
            end_futuro_aux = end_futuro_aux->proximo;
        }
        end_futuro_aux->proximo = aux_1;
    }
    
    aux_2 = end_anteriores->proximo;

    while(aux_2->proximo != NULL) {
        aux_2 = aux_2->proximo;
    }

    strcpy(end_atual, aux_2->endereco);

    aux_2 = end_anteriores->proximo;

    if(strcmpi(aux_2->endereco, end_atual) == 0){
        end_anteriores->proximo = NULL;
    }else {
        while(aux_2->proximo != NULL) {
            Endereco *end;
            end = aux_2->proximo;
            if( strcmpi(end->endereco, end_atual) == 0 ){
                aux_2->proximo = NULL;
                break;
            }
            aux_2 = aux_2->proximo;
        }
    }
    end_anteriores_tam--;
    
    printf(" Situacao: \n");        
    Endereco *print_end_ant = end_anteriores->proximo;
    Endereco *print_end_fut = end_futuros->proximo;

    printf("\n ---End. Anteriores-------- \n");
    while(print_end_ant != NULL){
        printf("%s\n",print_end_ant->endereco);
        print_end_ant = print_end_ant->proximo;
    }
    printf("\n ---End. Futuros------- \n");
    while(print_end_fut != NULL){
        printf("%s\n",print_end_fut->endereco);
        print_end_fut = print_end_fut->proximo;
    }
    printf("Atual : %s\n",end_atual);
    
    
    menu();
}

// 3
void voltar_n_enderecos(int num){
   	system("cls");
    printf("\n voltar %d enderecos ", num);
    menu();
}


int main() {
    int opcao;
    int num;
    bool i;
    i = true;
    
    end_anteriores = malloc(sizeof (Endereco));
    end_anteriores->proximo = NULL;

    end_futuros = malloc(sizeof (Endereco));
    end_futuros->proximo = NULL;
    
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
                voltar();
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 3:
                system ("cls");
                printf("\n Quantos enderecos quer voltar? ");
                num = getche()-'0';
                voltar_n_enderecos(num);
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 4:
                system ("cls");
                mostrar_historico();
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 5:
                system ("cls");
                avancar();  
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 6:
                system ("cls");
                printf("\n Quantos enderecos quer avancar? ");
                num = getche()-'0';
                avancar_n_enderecos(num);       
                printf("\n\nEscolha outra opcao para continuar...\n\n");
                break;
            case 7:
                system ("cls");
                mostrar_futuros();               
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

