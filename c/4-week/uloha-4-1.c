// uloha-4-1.c -- Tyzden 4 - Uloha 1
// Michal Slovik, 9.10.2014 17:01:05

#include <stdio.h>
#include <stdlib.h>

typedef struct btnode {
	int value;
	struct btnode *left, *right;
}BTNODE;


/*global declarations */
int i = 0;
int currentDeep=-1, depth=0;

int Finddepth(BTNODE **n, int num)
{
	if (*n != NULL) 
	{
		currentDeep++;

		//zapise celkovu hlbku, ked sa dostava stale hlbsie
		if (currentDeep > depth && num == (*n)->value )
		{
			depth = currentDeep;
		}

		//rekurzivne prechadza cez cely strom
		Finddepth(&(*n)->left, num);
		Finddepth(&(*n)->right, num);

		// traversuje hore po strome
		currentDeep--; 
	}
	return depth;
}


/* inserting nodes of a tree */
void insert(BTNODE **tree, int num)
{
	BTNODE *tmp = NULL;

	if (!(*tree))
	{
		tmp = (BTNODE*)malloc(sizeof(BTNODE));
		tmp->left = tmp->right = NULL;
		tmp->value = num;
		*tree = tmp;
		return;
	}

	if (num < (*tree)->value)
	{
		insert(&(*tree)->left, num);
	}
	else if (num > (*tree)->value)
	{
		insert(&(*tree)->right, num);
	}
}

int main()
{
	int num = 1;
	BTNODE* root = NULL;

	while ((scanf("%d", &num) > 0))
	{
		insert(&root, num);
			
		printf("%d\n",Finddepth(&root , num));

		depth = 0;
	}

	return 0;
}
