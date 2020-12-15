#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct aluno {
    int ra;
    char nome[255];
    char curso[255];
    struct Aluno *dir;
    struct Aluno *esq;
} Aluno;

Aluno *arv_raiz = NULL;

void menu() {
    printf("\n\t#####################################################");
    printf("\n\t#                      MENU                         #");
    printf("\n\t#                                                   #");
    printf("\n\t#             Digite a opcao desejada               #");
    printf("\n\t#                                                   #");
    printf("\n\t#  1. Inserir aluno;                                #");
    printf("\n\t#  2. Buscar aluno;                                 #");
    printf("\n\t#  3. Remover aluno;                                #");
    printf("\n\t#  4. Listar alunos;                                #");
    printf("\n\t#  8. Sair do programa.                             #");
    printf("\n\t#                                                   #");
    printf("\n\t#                                                   #");
    printf("\n\t#                                                   #");
    printf("\n\t#####################################################");
    printf("\n");
}

//1
void inserir_aluno() {
    char aluno_nome[255], aluno_curso[255];
    int aluno_ra;
    
    Aluno *novo = NULL;
    
    printf("\n Qual o RA do aluno? ");
    scanf("%d", &aluno_ra);
    
    printf("\n Qual o Nome do aluno? ");
    scanf("%s", &aluno_nome);
    
    printf("\n Qual o Curso do aluno? ");
    scanf("%s", &aluno_curso);
    
	novo = malloc(sizeof (Aluno));
	novo->esq=NULL;
	novo->dir=NULL;
	novo->ra=aluno_ra;
	strcpy(novo->nome, aluno_nome);
	strcpy(novo->curso, aluno_curso);
    
    if(arv_raiz == NULL) {
		arv_raiz = novo;
	}
	else{
		Aluno *aux_atual 	= arv_raiz;
		Aluno *aux_anterior = NULL;
		
		while(1) {
			if(aluno_ra == aux_atual->ra) {
				printf("\n\nAluno ja cadastrado!\n\n");
				break;
			}
			if(aluno_ra < aux_atual->ra) {
				if(aux_atual->esq != NULL) {
					aux_anterior = aux_atual;
					aux_atual = aux_atual->esq;
				}
				else {
					aux_atual->esq = novo;
					printf("\n Aluno inserido com sucesso! \n\n");
					break;
				}	
			}
			else {
				if(aux_atual->dir != NULL) {
					aux_anterior = aux_atual;
					aux_atual = aux_atual->dir;
				}
				else {
					aux_atual->dir = novo;
					printf("\n Aluno inserido com sucesso! \n\n");
					break;
				}	
			}
		}	
	}
	
	menu();
}

//2
void buscar_aluno() {
    int aluno_ra;
    printf("\n Qual o RA deseja buscar? ");
    scanf("%d", &aluno_ra);
    
    if(arv_raiz == NULL){
    	printf("Nao existem alunos cadastrados ainda");
    	menu();
    	return;
	}
    
    Aluno *aux = arv_raiz;
    
    while(aux != NULL) {
    	if(aux->ra == aluno_ra){
    		printf("\nAluno encontrado:");
    		printf("\nRA: %d", aux->ra);
    		printf("\nNome: %s", aux->nome);
    		printf("\nCurso: %s", aux->curso);
    		break;
		}
		if(aluno_ra < aux->ra) {
			aux = aux->esq;
		}
		else {
			aux = aux->dir;
		}
	}
    menu();
}

//3
void remover_aluno() {
    //
}

//4
void listar_alunos() {
    exibirEmOrdem(arv_raiz);
    printf("\n");
    menu();
}

void exibirEmOrdem(Aluno *raiz){
    if(raiz != NULL){
        exibirEmOrdem(raiz->esq);
        printf("\n RA: %d Nome: [%s] Curso: [%s]", raiz->ra, raiz->nome, raiz->curso);
        exibirEmOrdem(raiz->dir);
    }
}

int main() {
    int opcao;
    bool i;
    i = true;
    
    menu();
    do {
        opcao = getche()-'0';
        switch(opcao) {
            case 1:
                system("cls");
                inserir_aluno();
                printf("\n Escolha outra opcao para continuar...\n");
                break;
            case 2:
                system ("cls");
                buscar_aluno();
                printf("\n Escolha outra opcao para continuar...\n");
                break;
            case 3:
                system ("cls");
                remover_aluno();
                printf("\n Escolha outra opcao para continuar...\n");
                break;
            case 4:
                system ("cls");
                listar_alunos();
                printf("\n Escolha outra opcao para continuar...\n");
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
