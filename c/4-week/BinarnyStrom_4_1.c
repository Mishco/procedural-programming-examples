#include <stdio.h>
#include <stdlib.h>

typedef struct BTree{
	int Data;
	struct BTree *left;
	struct BTree *right;
}BTree;

BTree *create(BTree *p, int Data) //vytvori koren
{
	p = (BTree*)malloc(sizeof(BTree));
	p->Data = Data;
	p->left = p->right = NULL;
	return p;
}


void pushInToTree(BTree *p, int Data) {
	
	BTree *temp, *prev;

 while(temp != NULL) {
	if(Data > temp->Data) {
		prev = temp;
		temp = temp->right;
	}
	else {
		prev = temp;
		temp = temp->left;
	}
	temp = (BTree*)malloc(sizeof(BTree));
	if (Data >= prev->Data) 
	{
		prev->right = temp;
	}
	else
		prev->left = temp;	
 } 
}

void vypis(BTree *head){
	printf("head == %d",head->Data);

while(head != NULL)
	{
		if  (head->left != NULL )	{ printf("\nLeft child == %d ", head->left->Data); head=head->left; }
		if  (head->right != NULL) { printf("\nRight child == %d", head->right->Data);head=head->right; }
		
	}	

}


int main()
{
	BTree *tree, *root;
	root = create(tree, 1);
	int num=0, docas =0;	

	while(scanf("%d",&num) > 0) {
		pushInToTree(root, num);
		docas++;
	if(docas == 3) break;
	}

	vypis(root);
}
