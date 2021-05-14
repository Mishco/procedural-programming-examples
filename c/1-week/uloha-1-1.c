#include <stdio.h>

#define max 1300000
int main()
{
	int i=0,k=1,j=0,n=1;                // n je nastavene 1 aby bol zoznam spravne ulozeny 

	int  poleCisel[100050];
	char polePRVOciselnosti[max];       // je prvocislo 1, nie je 0

	for(i=1; i < max; i++) {			//zaplni pole jednotkami, 
	   polePRVOciselnosti[i]='1';
	} 

	for(i=2; i < max ; i++) {
		if (polePRVOciselnosti[i]=='1') {  // zisti ci uz nie je prvocislo, 
				poleCisel[n]=i;			   // toto prvocislo vloz do zoznamu prvocisel
          		n++;
          for (j=2*i; j<max; j+=i)	
         		polePRVOciselnosti[j] = '0'; // ak nie je prvocislo zaplni jeho miestom 0
		}
	}

  	while (scanf("%d", &k) > 0) {
  		printf("%d\n",poleCisel[k]);
    }
 	return 0;
}
