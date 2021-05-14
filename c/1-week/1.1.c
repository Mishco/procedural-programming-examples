// uloha-1-1.c -- Tyzden 1 - Uloha 1
// Michal Slovik, 21.9.2015 09:13:45

#include <stdio.h>

int findBigger(int FirstNum, int SecondNum)
{
	int temp = SecondNum;
	
	while(SecondNum != 0)
	{
		temp = SecondNum;
		SecondNum = FirstNum % temp;
		FirstNum = temp;
	}
	return FirstNum;
}


int main()
{

  int num_a, num_b;

  while(scanf("%d%d",&num_a,&num_b) > 0) {
  	  printf("%d\n",findBigger(num_a,num_b));
  }

  return 0;
}

