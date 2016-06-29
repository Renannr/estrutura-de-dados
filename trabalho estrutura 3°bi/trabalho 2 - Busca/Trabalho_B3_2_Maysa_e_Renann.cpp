//Trabalho de Estrutura de dados Terceiro Bimestre Parte 2
//Academicos Maysa Lovatto Lopes RA: 13015123
//           Renann R. da Silva  RA: 13106523
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 1000

int vetor[TAM];
float aux_busca_seq = 0,aux_busca_bin = 0,aux_busca_arvb = 0,aux_busca_arv_avl = 0;
struct no *raiz2=NULL, *raiz;

struct no {
  int dado;
  struct no *esq;
  struct no *dir;
  int bal;
};

void cria_vetor() {
  int i;
  for (i=0;i<=TAM-1;i++)
    vetor[i]=rand()%TAM;//Cria vetor randômico
}

void imprimir() {
  int i;
  for(i=0; i<=TAM-1; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n\n");
}

//      quicksort
int partition(int p, int r) {
  int piv = vetor[p], i = (p - 1), j = (r + 1), aux = 0;

  while(1) {
    while(vetor[--j] > piv);
    while(vetor[++i] < piv);

    if(i < j) {
      aux = vetor[i];
      vetor[i] = vetor[j];
      vetor[j] = aux;
    }
    else
      return j;
  }

}
void quicksort(int p, int r) {
  int q=0;
  if(p < r) {
    q = partition(p, r);
    quicksort(p, q);
    quicksort((q+1), r);
  }
}
//------------------------------------------------------------------------------

//        inserção arvore AVL
void esquerda(struct no *p) {

  no *q, *hold;

  q = p->dir;
  hold = q->esq;
  q->esq = p;
  p->dir = hold;
}

void direita(struct no *p) {

  no *q, *hold;

  q = p->esq;
  hold = q->dir;
  q->dir = p;
  p->esq = hold;
}

struct no *cria_no(int valor) {
  no *aux = new (struct no);
  aux->dado = valor;
  aux->dir = NULL;
  aux->esq = NULL;
  aux->bal = 0;
  return aux;
};

void insere_bal(int chave) {

  no *pp=NULL, *p=raiz2, *pajovem=NULL, *ajovem=raiz2, *q, *filho;
  int imbal;

  if(p == NULL) {             // Arvore vazia
    raiz2 = cria_no(chave);  // Funcao para criacao de um novo no
    return;
 }

// Insere chave e descobre ancestral mais jovem a ser desbalanceado
  while(p != NULL) {
    if(chave < p->dado)
      q = p->esq;
    else q = p->dir;
      if (q != NULL)
        if (q->bal != 0) {
          pajovem=p;
          ajovem=q;
        }
    pp = p;
    p = q;
  }

  q = cria_no(chave);

  if(chave < pp->dado)
    pp->esq = q;
  else pp->dir = q;

// Balanceamento de todos os nós entre ajovem e q devem ser ajustados
  if(chave < ajovem->dado)
    filho = ajovem->esq;
  else filho = ajovem->dir;

  p = filho;

  while(p != q) {
    if(chave < p->dado) {
      p->bal = 1;
      p = p->esq;
    } else {
      p->bal = -1;
      p = p->dir;
    }
  }

  if(chave < ajovem->dado)
    imbal = 1;
  else imbal = -1;

  if(ajovem->bal == 0) {      //Não houve desbalanceamento
    ajovem->bal = imbal;
    return;
  }


  if(ajovem->bal != imbal) {   //Não houve desbalanceamento
    ajovem->bal = 0;
    return;
  }


  if(filho->bal == imbal) {
    p = filho;
    if(imbal == 1)        //Faz rotação simples
      direita(ajovem);
    else esquerda(ajovem);
      ajovem->bal=0;
    filho->bal=0;
    }
    else {
      if(imbal == 1) {   //Faz rotação dupla
        p=filho->dir;
        esquerda(filho);
        ajovem->esq=p;
        direita(ajovem);
      } else {
        p=filho->esq;
        direita(filho);
        ajovem->dir=p;
        esquerda(ajovem);
      }
      if(p->bal == 0) {
        ajovem->bal = 0;
        filho->bal = 0;
      } else {
        if(p->bal == imbal) {
          ajovem->bal = - imbal;
          filho->bal = 0;
        } else {
          ajovem->bal = 0;
          filho->bal = imbal;
        }
      }
      p->bal = 0;
    }

  if(pajovem == NULL)  // Ajusta ponteiro do pai
    raiz2 = p;
  else if(ajovem == pajovem->dir)
    pajovem->dir = p;
  else
    pajovem->esq = p;

  return;
}
//------------------------------------------------------------------------------

// inserção arvore Binaria
void insere(int valor) {
  no *aux;
  no *atual;

  aux = new(struct no);
  aux->esq = NULL;
  aux->dir = NULL;
  aux->dado = valor;

  if(raiz == NULL){
    raiz=aux;
    return;
  }

  atual = raiz;

  while(1) {
    if(valor < atual->dado) {
      if(atual->esq == NULL) {
        atual->esq = aux;
        return;
      }
      else
        atual = atual->esq;
    }
    else {
      if(atual->dir == NULL) {
        atual->dir = aux;
        return;
      }
      else
        atual = atual->dir;
    }
  }
}
//------------------------------------------------------------------------------

// inserir na arvore binaria
void insere_arvb() {
  int i;
  for(i=0; i<TAM; i++)
    insere(vetor[i]);
}
//------------------------------------------------------------------------------

// insere arvore avl
void insere_arvavl() {
  int i;
  for(i=0; i<TAM; i++)
    insere_bal(vetor[i]);
}
//------------------------------------------------------------------------------

// gerador de chave de busca
int gerador_chave() {
  int valor=0;
  valor = rand()%TAM;
  return valor;
}
//------------------------------------------------------------------------------

// busca sequencial = corrigir
int busca_sequencial(int chave) {
  int i=0;
  for(i=0; i<TAM && vetor[i]<=chave; i++) {
    aux_busca_seq++;
    if(vetor[i] == chave)
      return 1;
  }
  return 0;
}
//------------------------------------------------------------------------------

// busca binaria
int busca_binaria(int chave) {
  int esq=0, dir=(TAM-1), meio=0;
  while(esq <= dir) {
    meio = (esq+dir)/2;
    aux_busca_bin++;
    if(chave == vetor[meio]) {
      return 1;
    }
    if(chave < vetor[meio]) {
      dir = meio-1;
    }
    else {
      esq = meio+1;
    }
  }
  return 0;
}
//------------------------------------------------------------------------------

// busca arvore binaria
int busca_arv_binaria(int chave) {
  struct no *atual;
  atual = raiz;
  while(atual != NULL) {
    aux_busca_arvb++;
    if(atual->dado == chave) {
      return 1;
    }
    if(chave < atual->dado) {
      atual = atual->esq;
    }
    else {
      atual = atual->dir;
    }
  }
  return 0;
}
//------------------------------------------------------------------------------

//busca arvore avl
int busca_arv_avl(int chave) {
  struct no *atual;
  atual = raiz2;
  while(atual != NULL) {
    aux_busca_arv_avl++;
    if(atual->dado == chave) {
      return 1;
    }
    if(chave < atual->dado) {
      atual = atual->esq;
    }
    else {
      atual = atual->dir;
    }
  }
  return 0;
}
//------------------------------------------------------------------------------

//           função que verifica se o vetor esta em ordem
int verifica_ordem() {
  int i;
  for(i=0; i<TAM-1; i++) {
    if(vetor[i] > vetor[i+1]) {
      return 0;
    }
  }
  return 1;
}
//------------------------------------------------------------------------------

main() {

  int chave=0,i;
  printf(" - Criando vetor...\n");
  cria_vetor();
  printf(" - Inserindo em Arvore Binaria...\n");
  insere_arvb();
  printf(" - Inserindo em Arvore AVL...\n");
  insere_arvavl();
  printf(" - Ordenando vetor... ");
  quicksort(0,TAM-1);
  printf("%s\n", verifica_ordem() ? "Vetor ordenado!\n" : "Vetor desordenado!\n"); //Operador ternario

  for(i=0; i<10; i++) {
    chave = gerador_chave()%TAM-i;

    busca_sequencial(chave);
    busca_binaria(chave);
    busca_arv_binaria(chave);
    busca_arv_avl(chave);
  }

//media de tempo de 10 buscas
  printf("\n- Tamanho do Vetor = %d/numero de buscas feitas = %d \n\n", TAM, i);
  printf("- Busca Sequencial     - media de: %.1f comparacoes\n",aux_busca_seq/10);
  printf("- Busca Binaria        - media de: %.1f comparacoes\n",aux_busca_bin/10);
  printf("- Busca Arvore Binaria - media de: %.1f comparacoes\n",aux_busca_arvb/10);
  printf("- Busca Arvore AVL     - media de: %.1f comparacoes\n",aux_busca_arv_avl/10);

  getch();
}