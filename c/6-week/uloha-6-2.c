// uloha-6-2.c -- Tyzden 6 - Uloha 2
// Michal Slovik, 26.10.2015 11:03:37


#include <stdio.h>
#include <string.h>

unsigned long long hash(char *s, int hash_size){
  unsigned long long h=0;
  int i;
  for(i=0 ; i < strlen(s); i++) { // HASH FUNCTION
      h= h*31 + (s[i]-'a');
  // PO ZNAKOCH
  }
  return h;
}

// spracuje cisla OP: vrati pocet najdenych duplikatov.
int vyhadzovac(char *a[], int n)
{
  int i=0;
  int zhoda=0;
  unsigned long long hash_val;	
  int hash_size = 2*n+1;
  char arrayOfRes[hash_size][20];
  
  /*VYPRAZDNI HASH TABULKU*/
  for(i=0;i<hash_size;i++) {
  	arrayOfRes[i][0]='x';
  }

  for(i=0; i < n ;i++) 
  {
  		  
	hash_val = hash(a[i], hash_size); 
  	if (hash_val > (2*n+1) )
    	hash_val %= (2*n+1);
    	
    	
  	if (arrayOfRes[hash_val][0] == 'x')
	{
      strcpy(arrayOfRes[hash_val],(a)[i]);
    } else if (strcmp(arrayOfRes[hash_val],a[i]) == 0)
        	zhoda++;
      else 
	  {
        while(1) 
		{
          zhoda++;
          
		  if (hash_val > (2*n+1)) 
    	    hash_val = 0;
          if (arrayOfRes[hash_val][0] == 'x')
		  {
            	strcpy(arrayOfRes[hash_val],(a)[i]);
            	break;
          }
          else if (strcmp(arrayOfRes[hash_val],a[i]) == 0){
                   zhoda++;
                   break;
          }
        }
    }  	
  }	
  return zhoda;
}



int main(){
 // int i;
 // char* names[]={"name","address","phone","k101","k110"};
 // char* descs[]={"Sourav","Sinagor","26300788","Value1","Value2"};


  char *a[] = {"AA123456", "BA987689", "AA123123", "AA312312", "BB345345", "AA123123"};
    printf("Pocet duplikatov: %d\n", vyhadzovac(a, 6));

  return 0;
}


/*
// ukazkovy test
int main(void)
{
  char *a[] = {"AA123456", "BA987689", "AA123123", "AA312312", "BB345345", "AA123123"};
  printf("Pocet duplikatov: %d\n", vyhadzovac(a, 6));
  return 0;
}
*/
