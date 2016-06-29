//Trabalho de Estrutura de dados Quarto Bimestre Parte 1 - 01
//Tabelas de espalhamento
//Academicos: Maysa Lovatto Lopes RA: 13015123
//            Renann R. da Silva  RA: 13106523
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define TAM 10

int Vetor[TAM];

void iniciar() {
  int i;
  for (i = 0; i < TAM; i++)
    Vetor[i] = -1;
}

int hash(int valor) {
  return (valor%TAM);
}

int reHash(int valor_chave) {
  return (valor_chave + 1) % TAM;
}

void inserir(int valor) {
  int pos = hash(valor), cont = 0;

  if(Vetor[pos] != -1) {
    while(Vetor[pos  = reHash(pos)] != -1 && cont++ < TAM);

    if(cont == TAM - 1) {
      printf("Erro! Tabela hash estourou \a");
      return;
    }
    Vetor[pos] = valor;
  } else
    Vetor[pos] = valor;

}

void buscar(int valor) {
  int pos, cont = 0;
  pos = hash(valor);


  if(Vetor[pos] != valor) {
    while(Vetor[pos  = reHash(pos)] != valor && cont++ < TAM);
    if(cont == TAM-1 || Vetor[pos] != valor) {
      printf("\nValor nao encontrado \a");
      return;
    }
    printf("\nValor encontrado na posicao %d",pos);
  } else
    printf("\nValor encontrado na posicao %d",pos);
}

void menu() {
  printf("\n##############################################");
  printf("\n#                  MENU                      #");
  printf("\n#                                            #");
  printf("\n# Digite a op\207\706o desejada              #");
  printf("\n#                                            #");
  printf("\n#  1 = Inserir elemento                #");
  printf("\n#  2 = Buscar elemento                 #");
  printf("\n#  5 = Sair                            #");
  printf("\n#                                            #");
  printf("\n##############################################");
  printf("\n\n");
}


int main() {

  int opcao,valor;
  bool i=true;
  iniciar();
  menu();
  do {
    opcao = getche()-'0';

    switch(opcao) {
      case 1:
        system ("cls");
        menu();
        printf("\nDigite o valor a ser inserido ");
        scanf("%d", &valor);
        inserir(valor);
        printf("\n\nEscolha outra op\207\706o para continuar...\n\n");
        break;
      case 2:
        system ("cls");
        menu();
        printf("\nDigite o valor a ser buscado ");
        scanf("%d", &valor);
        buscar(valor);
        printf("\n\nEscolha outra op\207\706o para continuar...\n\n");
        break;
      case 5:
        system ("cls");
        printf("\n\n\t\tAt\202 logo !!\n\n\n\n\n\n\n\n\n\n");
        i=false;
        break;
    }
  }
  while(i == true);

  system ("pause");
}
