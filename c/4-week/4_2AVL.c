#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*global definition*/
/*AVL Strom value*/
typedef struct node {
	int value;
	struct node *left;
	struct node *right;
	int height; 
} node;

int najblizsiaHodnota = -1;

/*other function*/
int maxValue (int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

node *newNode (int value) {
	node *tmp = (node*) malloc(sizeof(node));
	tmp->value=value;
	tmp->left= NULL;
	tmp->right=NULL;
	tmp->height=1;
	return tmp;
}

//AVL values
int height (node *N) {
	if (N == NULL)
		return 0;
	else
		return N->height;
}


// values
int getBalance(node *N) {
	if (N == NULL)
		return 0;
	else
		return (height(N->left) - height(N->right));
}

// values
node *rightRotate(node *y) {
	node  *x = y->left;
	node *tmp= x->right;

	x->right = y;
	y->left  = tmp;

	y->height = maxValue(height(x->left), height(y->right)) + 1;
	x->height = maxValue(height(x->left), height(x->right)) + 1;

	return x;
}

// values
node* leftRotate (node *x) {
	node *y = x->right;
	node *tmp = y->left;

	y->left = x;
	x->right =tmp;

	x->height = maxValue(height(x->left), height(x->right)) + 1;
	y->height = maxValue(height(y->left), height(y->right)) + 1;

	return y;
}

int minValueNode (node *root) {
	node *act = root;
	/* od vstupneho rootu
	prechadza az do laveho podlistu kde je najmensia hodnota*/
	while (act->left != NULL) {
		act = act->left;
	}
	return act->value;
}


// vkladanie values
node* insert(node *root, int value) {
	int balance = 0;

	if (root == NULL) {
		return (newNode(value));
	}
	// (key < node->key)
	if (value < root->value)
		root->left = insert(root->left, value);
	if (value > root->value)
		root->right = insert(root->right, value);
	if (value == root->value) {
		//nepridavaj ale vrat najblizsiu hodnotu
		if (root->left)
			if (root->height - root->left->height < 0)
				najblizsiaHodnota = root->left->value;
			else {
				if ( najblizsiaHodnota > 0 )
					return;
					//najblizsiaHodnota;
			//pozri sa nad seba
		}
	}


	/*UPRAVI VYSKU PREDCHODCU*/
	root->height = maxValue(height(root->left), height(root->right)) + 1;

	balance = getBalance(root);

	/*LEFT LEFT ROTATION*/
	// if (balance > 1 && key < node->left->key)
	if (balance > 1 && value < root->left->value )
		return rightRotate(root);

	/*RIGHT RIGHT ROTATION*/
	// if (balance < -1 && key > node->right->key)
	if (balance < -1 &&  value >  root->right->value)
		return leftRotate(root);

	/*LEFT RIGHT ROTATION*/
	//if (balance > 1 && key > node->left->key) {
	if (balance > 1 &&  value > root->left->value) {
		root->left = leftRotate(root->left);
		najblizsiaHodnota = root->left->left->value;
		return rightRotate(root);
	}

	/*RIGHT LEFT ROTATION*/
	//if (balance < -1 && key < node->right->key) {
	if (balance < -1 &&  value < root->right->value) {
		root->right = rightRotate(root->right);
		najblizsiaHodnota = root->right->right->value;
		return leftRotate(root);
	}
	
	if (root->left&&root->right) {
		// este zisti a najdi najblizsiu hodnotu
		if (value < root->value) {
			if (root->value < najblizsiaHodnota)
				najblizsiaHodnota = root->value;
			return;
		}
		if (value < root->right->value) {
			if (root->right->value < najblizsiaHodnota)
				najblizsiaHodnota = root->right->value;
			return;
		}
		if (value < root->left->value) {
			if (root->left->value < najblizsiaHodnota)
				najblizsiaHodnota = root->left->value;
			return;
		}
	}
	

	return root;
}


/**VYPIS values*/
void preOrder (node *root) {
	if (root != NULL) {
		printf("%d ", root->value);
		preOrder(root->left);
		preOrder(root->right);
	}
}


/*main function*/
int main()
{
	int num;
	node *root = (node*)malloc(sizeof(node));
	root->height = 0;
	root->left = NULL;
	root->right = NULL;


	//root->value = 10000;
/*	5
	3
	2
	1
	3*/
	root = insert(root, 5);
	//preOrder(root);
	printf("%d \n",najblizsiaHodnota);
	root = insert(root, 3);
	//preOrder(root);
	printf("%d \n",najblizsiaHodnota);
	root = insert(root, 2);
	//preOrder(root);
	printf("%d \n",najblizsiaHodnota);

	root = insert(root, 1);
	printf("%d \n",najblizsiaHodnota);

	root = insert(root, 3);
	//preOrder(root);
	printf("%d \n",najblizsiaHodnota);
	


	/*
	root = insert(root,5);
	printf("%d \n",najblizsiaHodnota);
	root = insert(root, 5);
	printf("%d \n",najblizsiaHodnota);
	root = insert(root, 5);
	printf("%d \n",najblizsiaHodnota);
	*/

/*
	while (scanf("%d",&num) > 0) {
		root=insert(root,num);
		printf("%d \n",najblizsiaHodnota);
	}
*/
	return 0;
}

