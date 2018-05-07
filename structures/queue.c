#include <stdio.h>
#include <stdlib.h>

// FILA (QUEUE)
typedef struct no {
	int key;
	no *next;
} no;

no *head = NULL, *aux;

void inserir(int key) // push
{
	no *novo = (no*) malloc(sizeof(no));
	novo->key = key;
	novo->next = NULL;
	if(!head) { aux = head = novo; }
	else {
		aux->next = novo;
		aux = aux->next;
	}
	
}

void deletar_primeiro_elemento() { // pop (erase)
	if(head) {
		no *temp = head->next;
		free(head);
		head = temp;
	}
}


void imprimir() {
	if(head) {
		no* temp;
		for(temp = head; temp; temp = temp->next)
			printf("%d \n", temp->key);
		printf("\n");
	} else printf("VAZIA\n\n");
}

no* eh_vazia() { // empty, is_empty
	return head;
}


int main() {
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
 	imprimir();		
	return 0;
}