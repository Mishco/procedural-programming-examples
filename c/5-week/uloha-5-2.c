// uloha-5-2.c -- Tyzden 5 - Uloha 2
// Michal Slovik, 22.10.2014 10:10:24

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	char *meno;
	int   hodnota;
} tree;

tree heap[100000]; // binarna halda
int size=0;

void heapfify(int i);

// vlozi meno a hodnotu do prioritnej fronty
void vloz(char *meno, int hodnota)
{
	size++; //prvy prvok na prvej pozicii [heap[1]]
	heap[size].meno = meno;
	heap[size].hodnota = hodnota;

	tree tmp;	//pomocna struktura

	int i=size;	    //PARENT             AKTUAL
	while(i > 1 && heap[i/2].hodnota < heap[i].hodnota) {
		//vymeni prvky
      	tmp = heap[i];
		heap[i] = heap[i/2];
		heap[i/2] = tmp;

      	//posunuie prvky v cykle
      	i = i/2;
	}
}

/// vrati meno, ktore bolo doteraz vlozene s najvyssou hodnotou a odstrani ho z prioritnej fronty
char *vyber_najvyssie()
{
	char *meno;
	if (heap[size].hodnota < 1) { //ak nebolo nic vlozene nepokracuj
	  	return "chyba";
    }
	meno = heap[1].meno; //zapamata si meno

	heap[1]=heap[size];

	size--;
  	heapfify(1);

  return meno;
}

void heapfify(int i) {
	int left = 2*i;
	int right= 2*i + 1;
	int largest;

	tree tmp;

	if (left <= heap[size].hodnota && heap[left].hodnota > heap[i].hodnota) {
		largest = left;
	}
	else {
		largest = i;
	}

    if (right <= heap[size].hodnota && heap[right].hodnota > heap[largest].hodnota) {
		largest = right;
	}

    if(largest != i) {
		/*vymeni*/
		tmp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = tmp;
	//zavola rekurzivne funckiu este raz
      	heapfify(largest);
	}
}


int main()
{
	int i=0;

    vloz("Patdesiaty", 50);
    vloz("4", 40);
    vloz("3", 30);
    vloz("2", 20);


	for(i=1; i <= size ;i++) {
		printf("%d \n",heap[i].hodnota);
	}

  	printf ("%s \n",vyber_najvyssie());

  	for(i=1; i <= size ;i++) {
		printf("%d \n",heap[i].hodnota);
	}
  return 0;
}

