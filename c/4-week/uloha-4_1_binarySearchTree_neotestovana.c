/**
* name: Binary search tree
* author: Michal Slovik
* version: 1.0
* program: insert, search, no balance
*/
#include <stdio.h>
#include <stdlib.h>

#define maxV(a,b) (((a) > (b)) ? (a) : (b))
#define TRUE 1
#define FALSE 0

/*global definition*/
typedef struct tree
{
	int value;
	struct tree *left;
	struct tree *right;
} TREE;

/*other function*/
TREE *getNode()
{
	TREE *tmp = (TREE*)malloc(sizeof(TREE));
	return tmp;
}

void init(TREE *tmp)
{
	tmp->left = getNode();
	tmp->right = getNode();
	tmp->value = 0;
}

int actualDeep(TREE *vrchol)
{
	int left, right;
	if (vrchol->value==0)
		return 0;
	else
	{
		left = actualDeep(vrchol->left);
		right = actualDeep(vrchol->right);
		return 1 + maxV(left, right);
	}
}


void insert(TREE *root , int data)
{
	if (root->value == 0)
	{
		root->left=(TREE*)malloc(sizeof(TREE));
		root->right=(TREE*)malloc(sizeof(TREE));
		root->left->value = 0;
		root->right->value= 0;
		root->value = data;
	}	
	else if( data < root->value)
		insert(root->left, data);
	else if(data > root->value)
		insert(root->right, data);
}

int searchIntree(int key, TREE *root)
{
	TREE *currentNode = root;
	while(currentNode->value != 0)
	{   
		//nasiel
		if (currentNode->value== key)
			return TRUE;
		else if (key < currentNode->value)
			currentNode = currentNode->left;
		else
			currentNode = currentNode->right;
	}
	return FALSE;
}

/*main function*/
int main()
{
	TREE root;
	int cis;
	int arrDeep[100000] = {0};
	int tmp;

	init(&root);

	// najskor skontroloju strom, ci dana hodnota sa uz nevysktyu
	// ak dany uzol existuje vypis hlbku stromu
	// alebo ak pridavame novy uzol vypis

	while(scanf("%d", &cis) > 0)
	{
		if (searchIntree(cis, &root) == TRUE)
			//namiesto vypoctu bude vyberat hlbku z pomocneho pola
			printf("deep: %d\n",arrDeep[cis]);
		else {
			insert(&root, cis);
			printf("deep: %d \n",tmp = actualDeep(&root)-1);
			arrDeep[cis] = tmp;
		}
	}
}
