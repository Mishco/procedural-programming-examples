#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TRUE 1
#define FALSE 0
#define MAX 10000

char stack[MAX]; // globalny zasobnik
int top=0;

void createStack(char stack[MAX])
{
	stack[top] = 0;
}

void pushToStack(char stack[MAX],char sign)
{
	stack[top++] = sign; 
}

int IsEmpty(char stack[MAX])
{
	if (stack[top-1] == 0) { // top - 1, pretoze za kazdy znak dava \0
		//printf("Stack is empty\n");
		return TRUE;  //zasobnik je prazdny
	}
	else
		return FALSE; //zasobnik nie je prazdny
}

char popFromStack(char stack[MAX])
{
	char tmp;
	if (!IsEmpty(stack)) 
	{
		tmp = stack[top-1];
		stack[top-1] = 0; // vymaz zo zasobnika 
		top--;
		return tmp; // top - 1, pretoze za kazdy znak dava \0
	}
	else{ 
		//	printf("Error");
		return FALSE;
	}
}

char topOfStack(char stack[MAX])
{
	return stack[top-1];
}

//funkcia na zistovanie priority operatorov
int prior(char znak) { 
	switch(znak) {
	case '(' : return 0; // nízka priorita
	case '+' :
	case '-' : return 1;
	case '*' :
	case '/' : return 2; // najvyssia priorita			
	default  : return -1; //nemalo by nikdy nastat
	}
}

int main()
{
	char pole[MAX];
	char tmpChar;
	int i=0;
	int lengthOfPole;

	while(scanf("%s",&pole) > 0)
	{
		createStack(stack);

		lengthOfPole = strlen(pole);
		i=0;
		while(i < lengthOfPole)
		{
			if (isalpha(pole[i]))
				printf("%c",pole[i]);
			else
			{
				if (pole[i]=='(')
				{
					pushToStack(stack,pole[i]);
				}
				else
				{
					//osetrenie zatvoriek aby vypisal vsetky znaky co su medzi nimi
					if(pole[i] == ')') 
					{
						while((tmpChar = popFromStack(stack)) != '(')
						{
							printf("%c",tmpChar);
						}
					}
					//samotne operatory +-*/ podla priority
					else
					{
						while(prior(pole[i]) <= prior(topOfStack(stack)) && IsEmpty(stack) != 1) 
						{
							tmpChar = popFromStack(stack);
							printf("%c", tmpChar);
						}
						//a vloz do zasobnika
						pushToStack(stack,pole[i]);
					}
				}
			}
			i++;
		} //koniec jedneho vyrazu

		//ked nacital cely vyraz vypis zasobnik
		while(IsEmpty(stack) != 1) {
			tmpChar = popFromStack(stack);
			printf("%c",tmpChar);
		}
		printf("\n");
	}//koniec celeho cyklu


	printf("\n");
	return 0;
}
