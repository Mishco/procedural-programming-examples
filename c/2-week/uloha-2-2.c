// uloha-2-2.c -- Tyzden 2 - Uloha 2
// Michal Slovik, 29.9.2014 19:03:10

#include <stdio.h>
#include <stdlib.h>
#define MAX 30000

int **create(int riadky, int stlpce) 
{
	int **p_x,i=0;
	
	p_x = (int **) malloc(riadky*sizeof(int *));
	for(i = 0; i < riadky; i++) {
		p_x[i]= (int *) malloc(stlpce*sizeof(int));
	}
	
	return (p_x);
}


int main()
{
	int N=0,i=0,aktual=0,pomoc,vkladanie,
		x=0;		//pocet postupnosti
	int **Post;		// pole postupnosti
	int field[MAX];	//POMOCNE pole
	int min[MAX], max[MAX];
	int j;	
		
	while (scanf("%d\n",&N)  > 0 ) {
		Post = create(N,MAX);
		for(i=0; i < N ;i++) {
			scanf("%d",&field[i]);
		}	
	min[0] = N;
	max[0] = N;
	
	for (i=0; i < N ; i++) {
		pomoc = field[i];
		aktual = 0;
		vkladanie = 0;
		   	if (i==0) {
	         	Post[0][min[0]] = pomoc;
				continue;
			}
			while(vkladanie==0 ){ //sme v jednej postupnosti
				if(pomoc < Post[aktual][min[aktual]]) {
					Post[aktual][min[aktual]-1]= field[i];
					min[aktual]--;	
					vkladanie = 1;			
				}
				else  //sme v jednej postupnosti
					 if (pomoc > Post[aktual][max[aktual]]) {
						Post[aktual][max[aktual]+1]= pomoc;
						max[aktual]++;
						vkladanie = 1;
					 } 
				else { // nova postupnost
					aktual++;
					if(x < aktual) {
						max[aktual] =  N;
						min[aktual] = N;
						x++;
						Post[aktual][max[aktual]]= pomoc;
						vkladanie = 1;
					}
				}
			}
		}
	printf("%d\n",x+1);
	for (i=0; i < x+1; i++) {
		for(j = min[i] ; j <= max[i]; j++) {
			printf("%d ",Post[i][j]);
		}
		printf("\n");
	}
	i=0; j=0; pomoc=0; aktual=0;
	for(i=0; i<N; i++) {
		field[i]=0;
		min[i]=0;
		max[i]=0;
	}
	x=0;
	N=0;
}
 return 0;
}
