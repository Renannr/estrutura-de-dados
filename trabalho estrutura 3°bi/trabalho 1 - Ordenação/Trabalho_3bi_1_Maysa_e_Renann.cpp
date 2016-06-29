//Trabalho de Estrutura de dados Terceiro Bimestre Parte 1
//Academicos Maysa Lovatto Lopes RA: 13015123
//           Renann R. da Silva  RA: 13106523

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TAM 40000

int vetor[TAM], tam_heap=0, scratch[TAM];

void cria_vetor() {
	int i,aux;

	for (i=0;i<TAM;i++)
      	vetor[i]=rand();//Cria vetor randômico
}

void imprime(){ //imprime o vetor
	int i;
	for(i=0;i<TAM;i++) {
		printf(" %d", vetor[i]);
	}
}


// 			A	 	bubble_sort = ok
void bubble_sort() {
    int pass = 1, i,aux;
    bool sorted = false;

    while((!sorted) && (pass < TAM)) {
    	sorted = true;
    	for(i=0; i <= (TAM-pass-1); i++) {
    		if(vetor[i] > vetor[i+1]) {
    			aux = vetor[i];
    			vetor[i] = vetor[i+1];
    			vetor[i+1] = aux;
				sorted = false;
    		}
    	}
    	pass++;
    }
}
//------------------------------------------------------------------------------


//          B       Insertion sort (inserção simples) = ok
void insertion_sort() {
	int k,i,x,aux;
	bool found;

	for(k=1; k<=TAM-1; k++) {
		x = vetor[k];
		i = k-1;
		found = false;
		while((!found) && (i >=0)){
			if(vetor[i] > x) {
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				i--;
			}
			else
				found = true;
		}
	}
}
//------------------------------------------------------------------------------


// 			C 		selection sort = ok
void selection_sort() {
	int i, j, atual, aux;
	for (i = 0; i < (TAM-1); i++) {
		atual = i;
    	for (j = (i+1); j < TAM; j++) {
    		if(vetor[j] < vetor[atual]) {
        		atual = j;
    		}
    	}
    	if (i != atual) {
    		aux = vetor[i];
    		vetor[i] = vetor[atual];
    		vetor[atual] = aux;
    	}
   }
}
//------------------------------------------------------------------------------


//          D        HEAPSORT = ok
void heapify(int i) {
	int L,r,max=0,aux=0;
	L = (2*i)+1;
	r = (2*i)+2;

	if((L<tam_heap) && (vetor[L]>vetor[i])) {
		max = L;
	}
	else
		max = i;

	if((r<tam_heap) && (vetor[r]>vetor[max]))
		max = r;

	if(max != i) {
		aux = vetor[i];
		vetor[i] = vetor[max];
		vetor[max] = aux;
		heapify(max);
	}
}

void build_healp() {
	int i;
	tam_heap = TAM;

	for(i=((TAM/2) - 1); i>=0; i--)
    heapify(i);
}

void heapsort() {
	int aux=0,k;

	build_healp();
	for(k=(TAM-1);k >= 1;k--) {
		aux = vetor[0];
		vetor[0] = vetor[k];
		vetor[k] = aux;
		tam_heap--;
		heapify(0);
	}
}
//------------------------------------------------------------------------------


//          E         mergesort = ok

void mergesort(int baixo, int alto) {
	int mid = 0, l = 0, h = 0, k = 0;

	if(baixo < alto) {
		mid = (baixo + alto)/2;

		mergesort(baixo,mid);
		mergesort((mid + 1),alto);

		l = baixo;
		h = mid+1;

		for(k = baixo;k <= alto; k++) {
			if((l <= mid) && ((h > alto) || (vetor[l] < vetor[h])))
				scratch[k] = vetor[l++];
			else
				scratch[k] = vetor[h++];
		}

		for(k = baixo; k <= alto; k++)
			vetor[k] = scratch[k];
	}
}
//------------------------------------------------------------------------------

// 			F  		quicksort = ok
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

    clock_t tempo1;

	//Contagem de tempo do BubbleSort
	cria_vetor();
	tempo1 = clock();
  bubble_sort();
	tempo1 = clock() - tempo1;
  printf("\nBubbleSorte: %.4f seg \n",(float)tempo1/CLOCKS_PER_SEC);
  printf("Vetor ordenado? %s\n\n", verifica_ordem() ? "Sim" : "Nao"); //Operador ternario
	//--------------------------------------------------------------------------

    //Contagem de tempo do InsertionSort
  cria_vetor();
  tempo1 = clock();
  insertion_sort();
	tempo1 = clock() - tempo1;
  printf("InsertionSort: %.4f seg\n",(float)tempo1/CLOCKS_PER_SEC);
  printf("Vetor ordenado? %s\n\n",  verifica_ordem() ? "Sim" : "Nao"); //Operador ternario
	//--------------------------------------------------------------------------

    //Contagem de tempo do SelectionSort
  cria_vetor();
  tempo1 = clock();
  selection_sort();
	tempo1 = clock() - tempo1;
  printf("SelectionSort: %.4f seg \n",(float)tempo1/CLOCKS_PER_SEC);
  printf("Vetor ordenado? %s\n\n",  verifica_ordem() ? "Sim" : "Nao"); //Operador ternario
	//--------------------------------------------------------------------------

    //Contagem de tempo do Heapsort
  cria_vetor();
  tempo1 = clock();
  heapsort();
	tempo1 = clock() - tempo1;
  printf("HeapSort: %.4f seg \n",(float)tempo1/CLOCKS_PER_SEC);
  printf("Vetor ordenado? %s\n\n",  verifica_ordem() ? "Sim" : "Nao"); //Operador ternario
	//--------------------------------------------------------------------------

    //Contagem de tempo do MergeSort
  cria_vetor();
	tempo1 = clock();
  mergesort(0, TAM - 1);
	tempo1 = clock() - tempo1;
  printf("mergeSort: %.4f seg \n",(float)tempo1/CLOCKS_PER_SEC);
  printf("Vetor ordenado? %s\n\n",  verifica_ordem() ? "Sim" : "Nao"); //Operador ternario
	//--------------------------------------------------------------------------

    //Contagem de tempo do QuickSort
  cria_vetor();
	tempo1 = clock();
  quicksort(0, TAM - 1);
	tempo1 = clock() - tempo1;
  printf("QuickSort: %.4f seg \n",(float)tempo1/CLOCKS_PER_SEC);
  printf("Vetor ordenado? %s\n\n",  verifica_ordem() ? "Sim" : "Nao"); //Operador ternario
	//--------------------------------------------------------------------------

	getch();
}
