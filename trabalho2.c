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
    //
}

//2
void buscar_aluno() {
    //
}

//3
void remover_aluno() {
    //
}

//4
void listar_alunos() {
    //
}

int main() {
    int opcao;
    bool i;
    i = true;
    
    raiz = malloc(sizeof (Aluno));
    raiz->dir = NULL;
    raiz->esq = NULL;
    
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
