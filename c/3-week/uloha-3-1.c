// uloha-3-1.c -- Tyzden 3 - Uloha 1
// Michal Slovik, 7.10.2014 13:14:44

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
	int dist;	//distance 
  	int target; //vrchol
	 struct tree* next;
}TREE;

TREE *creat(int target, int dist)
{
	TREE *a=(TREE*)malloc(sizeof(TREE)); 
	a->target=target;
	a->dist=dist;
	a->next=NULL;
	return a;
}
void insert(TREE **pred, TREE **po, int from, int target, int distance) 
{
	TREE *a;  

	if(po[from]==NULL)
	{
		pred[from]=creat(target,distance);
		po[from]=pred[from];
	}
	else
	{
      	a=creat(target,distance);// pomocná premenna
		po[from]->next = a;
		po[from] = a;
	}
}

int getDistance(TREE **pred, int posledny, int akt, int target)
{
	if(akt == target) return 0; // ak sa zistovani rovna prvemu vrat nula, pretoze neexistuje hrana
  	
	TREE *pomoc=pred[akt];

	while(pomoc != NULL)
	{
		if((pomoc->target) != posledny)
		{
			int docas=getDistance(pred, akt, pomoc->target, target); //rekurzivna funkcia
			if(docas >= 0) return (docas+pomoc->dist); // vrati celkovy sucet vsetkych hran ,ktore su na ceste medzi A a B
		}
		pomoc = pomoc->next; // posuvaj sa v zozname az kym sa nerovna NULL
	}
	return -1; //ak nie je nieco v poriadku
}

int main()
{
	int N=0,	  // pocet vrcholov stromu 
		M=0,	  //pocet hran stromu
		from=0,	  //z ktoreho 
		target=0; //do ktoreho zisti vzdialenost
	int i=0;

  	scanf("%d %d %d %d", &N, &M, &from, &target);

	TREE **pred =malloc(N*sizeof(TREE*)); //pole pointerov
	TREE **po   =malloc(N*sizeof(TREE*)); // ukladame do dvoch poli, pretoze hrany su neorientovane
		
  for(i=0; i < N; i++) // vynulovanie prvkov pola pointrov 
  {
    pred[i]=NULL;
  		po[i]=NULL;
  }
  for(i=0; i < M; i++) {
     int peak1=0, peak2=0, dis=0;
      scanf("%d %d %d",&peak1,&peak2,&dis); 
		insert(pred, po, (peak1-1), (peak2-1), dis);  // pole uklada od nultej pozicie teda vsetky vrcholy -1
		insert(pred, po, (peak2-1), (peak1-1), dis); // dvakrat pretoze hrany su neorientovane
  }
	/*pred = pole z ktoreho hladame, 
	 -1 = zatial 
	vzdialenost pocitame od from do target	
	*/
	printf("%d\n",getDistance(pred, -1 , (from-1), (target-1)));
	return 0;
}
