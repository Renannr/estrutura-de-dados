//Trabalho de Estrutura de dados Quarto Bimestre Parte 1 - 02
//Tabelas de espalhamento com encadeamento externo
//Academicos: Maysa Lovatto Lopes RA: 13015123
//            Renann R. da Silva  RA: 13106523
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define TAM 10

struct no {
  int valor;
  no *prox;
};

no *hash[TAM];


int espalha(int valor){
  return(valor%TAM);
}

void inicia() {
  int i;
  for(i=0; i<TAM; i++)
    hash[i] = NULL;
}

void insere(int valor) {
  int pos;
  no *atual, *anterior = NULL, *aux;

  pos = espalha(valor);
  atual = hash[pos];

  while(atual != NULL) {
    anterior = atual;
    atual = atual->prox;
  }

  aux = new(struct no);

  aux->valor = valor;
  aux->prox  = NULL;//importante
  if(anterior == NULL) {//posição vazia
    hash[pos] = aux;
  }
  else
    anterior->prox = aux;
}

void busca(int valor) {
  int pos, cont = 1;
  no *atual;

  pos = espalha(valor);
  atual = hash[pos];

  if(atual != NULL && atual->valor == valor){
    printf("\n\nValor encontrado! %d\247 elemento na posi\207\706o %d",cont, pos);
    return;
  }
  else {
    while(atual != NULL) {
      if(atual->valor == valor) {
        printf("\n\nValor encontrado! %d\247 elemento na posi\207\706o %d",cont, pos);
        return;
      }
      atual = atual->prox;
      cont++;

    }
  }
  printf("\n\nValor nao encontrado \a");
}

void menu(){
  printf("\n##############################################");
  printf("\n#                  MENU                      #");
  printf("\n#                                            #");
  printf("\n# Digite a op\207\706o desejada              #");
  printf("\n#                                            #");
  printf("\n#  1 = Inserir elemento                #");
  printf("\n#  2 = Buscar  elemento                #");
  printf("\n#  5 = Sair                            #");
  printf("\n#                                            #");
  printf("\n##############################################");
  printf("\n\n");
}


int main() {

  int opcao,valor;
  bool i=true;
  inicia();
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
        printf("\n\nEscolha outra op\207\706o para continuar...\n\n");
        break;
      case 2:
        system ("cls");
        menu();
        printf("\nDigite o valor a ser buscado ");
        scanf("%d", &valor);
        busca(valor);
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
