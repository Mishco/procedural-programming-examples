/**
* name: Najdi najblizsie cislo k novoPridanemu cislu
* author: Michal Slovik
* version: 1.0
* program:
*/

#include <stdio.h>
#include <stdlib.h>
/*global definition*/

int nevkladaj = 0;
int arr[] = {0};

/*other function*/
int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

int closestNum(int target, int size)
{
	int i;
	int p,c;
	if (arr[0] == 0 || size == 0)
	{
		return -1; //mnozina je prazdna
	}

//	if (size == 1)
//	{	
//		nevkladaj = 1;
//		return -1; //prve
//	}
	for (i = 0; i < size; i++)
	{
		if ( arr[i]==target)
		{
			p = arr[i-1];
			c = arr[i+1];
			nevkladaj = 1;
			
			if (size == 1)
				return -1;
				
			return abs(p-target) < abs(c-target) ? p : c;
		}

		if ( arr[i] > target)
		{
			p = arr[i-1];
			c = arr[i];
			return abs(p-target) < abs(c-target) ? p : c;
		}
	}
	return arr[size-1]; // posledne
}

void obsahPola(int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf(" %d ", arr[i]);
	}
	printf("\n");
}
/*main function*/
int main()
{

	int cislo;
	int size = 0;

	while(scanf("%d",&cislo) > 0)
	{
		//printf("Pred:");
		//obsahPola(size);

		printf("RESULT: ...%d\n",closestNum(cislo, size));

		if(nevkladaj == 0) 
		{
			arr[size] = cislo; //vkladanie
			qsort(arr,size+1,sizeof(int),compare);	//sort po vlozeni

			size++;
		}
		//printf("Po:");
		//obsahPola(size);
		//nevkladaj = 0;
	}
	return 0;
}
