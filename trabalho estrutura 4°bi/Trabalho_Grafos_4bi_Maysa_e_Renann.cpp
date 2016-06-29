//Trabalho de Estrutura de dados Quarto Bimestre
//Grafos usando lista de adjacencias com alocação dinamica
//Academicos: Maysa Lovatto Lopes RA: 13015123
//            Renann R. da Silva  RA: 13106523
#include<conio.h>
#include<stdio.h>
#define TAM 10

int vertices[TAM],cont=0;

struct no {
  int destino;
  no *prox;
};

no *arestas[TAM];

void inicia_arestas() {
  for(int i=0; i< TAM; i++) {
    arestas[i] = NULL;
    vertices[i] = 0;
  }
}

//funçao para inserir arestas
void insere_aresta(int orig, int dest) {
  int i=0,j=0;
  no *atual, *anterior, *aux;

  while(i < cont && vertices[i] != orig)
    i++;

  if(i == cont) {
    printf("\n\tERRO: Vertice origem [%d] nao encontrado", orig);
    return;
  }

  while(j < cont && vertices[j] != dest)
    j++;

  if(j == cont) {
    printf("\n\tERRO: Vertice destino[%d] nao encontrado", dest);
    return;
  }

  anterior = NULL;
  atual = arestas[i];

  while(atual != NULL){
    if(atual->destino == dest) {
      printf("\n\tERRO: Aresta repetida");
      return;
    }
    anterior = atual;
    atual = atual->prox;
  }

  aux = new(struct no);

  aux->destino = dest;
  aux->prox = NULL;

  if(anterior  == NULL) {
    arestas[i] = aux;
  }else
    anterior->prox = aux;


  printf("\nAresta inserida com sucesso [%d->%d]", orig, dest);
}
//função para inserir vertices
void insere_vertice(int valor) {
  if(cont >= TAM){
    printf("\n\tERRO: vertice nao inserido:");
    printf("\n\tExcedido o numero de vertices");
    return;
  }

  vertices[cont] = valor;
  cont++;
  printf("\nVertice inserido [%d]", valor);
}

//função de remoção
void remove_aresta(int orig, int dest) {
  int i=0,j=0;
  no *anterior, *atual;

  while(i < cont && vertices[i] != orig)
    i++;

  if(i == cont) {
    printf("\n\tERRO: Vertice origem [%d] nao encontrado", orig);
    return;
  }

  while(j < cont && vertices[j] != dest)
    j++;

  if(j == cont) {
    printf("\n\tERRO: Vertice destino [%d] nao encontrado", dest);
    return;
  }

  atual = arestas[i];
  anterior = NULL;


  while(atual != NULL){
    if(atual->destino == dest){
      if(atual->prox == NULL && anterior == NULL){//caso tenha apenas 1 elemento da lista de adjacencias
        arestas[i] = NULL;
        delete(atual);
        printf("\nAresta removida com sucesso!");
        return;
      }
      if(atual->prox != NULL && anterior == NULL){//caso seja o elemento do meio da lista
        arestas[i] = atual->prox;
        delete(atual);
        printf("\nAresta removida com sucesso!!");
        return;
      }
      else{
        anterior->prox = atual->prox;     //caso seja o ultimo elemento da lista
        delete(atual);
        printf("\nAresta removida com sucesso!!!");
        return;
      }
    }
    anterior = atual;
    atual = atual->prox;
  }
  printf("\n\tERRO: Aresta nao existente [%d]->[%d]",orig,dest);
}

//função de impressão
void imprime() {
  int i;
  no *aux;
  for(i=0; i<TAM && vertices[i] != NULL; i++) {
    printf("\n%d ->", vertices[i]);
    aux = arestas[i];
    while(aux != NULL) {
      printf("%d, ", aux->destino);
      aux = aux->prox;
    }
  }

}

main() {

  insere_vertice(1);
  insere_vertice(10);
  insere_vertice(100);
  insere_vertice(1000);
  insere_vertice(10000);
  insere_vertice(2);

  printf("\n\n");
  insere_aresta(1, 10);
  insere_aresta(1, 100);
  insere_aresta(1,1000);
  insere_aresta(1,10000);
  insere_aresta(10,10);
  insere_aresta(10,100);
  insere_aresta(10,1000);
  insere_aresta(100,10000);
  insere_aresta(10000,1);
  insere_aresta(1000,1);

  printf("\n\n");
  remove_aresta(1000,1);
  remove_aresta(1,10);
  remove_aresta(10,1000);
  remove_aresta(1,2);

  printf("\n\n");
  imprime();
  getch();
}
