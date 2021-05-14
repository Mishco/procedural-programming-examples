// uloha-3-2.c -- Tyzden 3 - Uloha 2
// Michal Slovik, 5.10.2015 07:53:20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_TO_INDEX(c) ((int)c-(int)'A')

typedef struct TrieNode {
	char value;
	int count;
	int prefix;
	struct TrieNode * children[27];
}TrieNode;

int count;
int maxDe;
struct TrieNode *maxNode;
int max = -1;
int min = 10000;


TrieNode* trieCreate() 
{
	TrieNode *pNode = NULL;
	pNode = (TrieNode *)malloc(sizeof(TrieNode));
	count = 0;
	if (pNode)
	{
		pNode->value = '\0';
		pNode->count = 0;
		pNode->prefix = 0;

		memset(pNode->children, 0, sizeof(pNode->children));
	}
	return pNode;
}



/** Inserts a word into the trie. */
void insert(TrieNode *root, char* word) 
{	
  	int index=0, i =0;
	TrieNode *pCrawl = root;
	//(*count)++;
	//check if the word is not empty 
	if(word)
	{
		index=0, i =0;
		//check if the root is not empty
		maxDe = 0;
		while( word[i] != '\0'){
			index = CHAR_TO_INDEX(word[i]);

            if(!pCrawl->children[index])
			{
				pCrawl->children[index] = trieCreate();
				pCrawl->children[index]->value = word[i];
				pCrawl = pCrawl->children[index];
			}
			else {
				pCrawl = pCrawl->children[index];
				maxDe++;
			}
			
			i++;
		}
		// GLOBALNA PREMENNA
		if (maxDe > max) {
			max = maxDe;
		}
		//Count !=0 tell us that this is the last node
		pCrawl->count = count;
	}
}

void trieFree(TrieNode* root) 
{
	int i;
	if(root)
	{
		for(i = 0; i <=26; i ++)
		{
			trieFree(root->children[i]);
		}
		free(root);
	}
}

/*
SLON
MALO
SILONKY
MAPA
MASKA
*/
int main()
{
	//char **keys = (char**)malloc(sizeof(char*)*21);
	char *a=(char*)malloc(sizeof(char)*21);
	int count = 0;	
	TrieNode *node = trieCreate();	

	while(scanf("%s", a) > 0 )
	{
		
        //keys[count] = (char*)malloc(sizeof(char)*21);
		//strcpy(keys[count], a);
		insert(node,a); // pri inserte zistuje dlzku slov
		count++;
		//printf("max %d \n", max);

	}
	printf("%d\n",max);
	trieFree(node);
	
	
	return 0;
}
