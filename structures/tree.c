#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
	int key;
	struct no *left, *right;
}no;

void inserir(no **el, int key){
	
	if(*el){ //se ja tem algum elemento na arvore
		if((*el)->key < key) inserir(&(*el)->right, key); //se o numero que ja tem na arvore for menor que o numero que queremos inserir, insere na esquerda
		else inserir(&(*el)->left, key); //se nao, insere na direita
	} else {
		//se nÃ£o existe, aloca espaco na memoria
		*el = (no*) malloc(sizeof(no));
		(*el)->left = (*el)->right = NULL;  //e inicializa os nós
		(*el)->key = key; //coloca o valor que na arvore
	}
}

no* busca(no *el, int key){
	if(!el) return NULL;
	if(el->key == key) return el;
	if(el->key > key) return busca(el->left, key);
	else return busca(el->right, key);
}

void remover(no *el) //BOTTOM-UP 
{
	if(el){
		remover(el->left);
		remover(el->right);
		free(el);
	}
}

int main()
{
	no *head = NULL; //inicializando a arvore
	inserir(&head,5);
	inserir(&head,3);
	inserir(&head,4); 
	inserir(&head,7);
	inserir(&head,8);
	inserir(&head,11); 
	
	int key = 6;
	no* el = busca(head, key);
	if(!el) printf("NAO TEM %d NA ARVORE\n", 6);
	else printf("KEY = %d\n", el->key);
	int key2 = 4;
	el = busca(head, key2);
	if(!el) printf("NAO TEM %d NA ARVORE\n", key);
	else printf("KEY = %d\n", el->key);
	
	remover(head);
		
	return 0;
}