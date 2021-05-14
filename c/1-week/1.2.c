// uloha-1-2.c -- Tyzden 1 - Uloha 2
// Michal Slovik, 21.9.2015 09:25:48

#include <stdio.h>
#define MAX 1400000

char arrayOfFirstNumber[MAX];
int arrayOfResult[MAX];

void erastenes()
{
	int i,j;
	int count=1;
	for (i = 2; i < MAX; i++)
	{
		if(arrayOfFirstNumber[i]=='1')
		{
			arrayOfResult[count++]=i;	
		}
		for(j=2*i; j < MAX; j+=i)
		{
			arrayOfFirstNumber[j] = '0';
		}
	}
	
}


int main()
{
   int idx;
   int k = 1;

   for(idx = 1; idx < MAX; idx++)
    	arrayOfFirstNumber[idx]= '1';
  
  erastenes();
  
  while(scanf("%d",&k) > 0) {
  	printf("%d\n",arrayOfResult[k]);
  }
  
  return 0;
}

