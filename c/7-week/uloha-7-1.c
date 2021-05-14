#include <stdio.h>

// Dynamicke programovanie pre riesenie catalanskeho cisla
unsigned long int catalanDP(unsigned int n)
{
	// vysledna tabulka
    unsigned long int catalan[n+1];
 	int i,j;
     // init hodnoty
    catalan[0] = catalan[1] = 1;
 
    // naplni ich rekurzivne
    for (i=2; i<=n; i++)
    {
        catalan[i] = 0;
        for (j=0; j<i; j++)
            catalan[i] += catalan[j] * catalan[i-j-1];
    }
 
    // n - prvok vrati
    return catalan[n];
}

int main() {
	int tmp;
	
	while(scanf("%d", &tmp) > 0) {
		printf("%d ",catalanDP(tmp));
		
	}
	return 0;
}
