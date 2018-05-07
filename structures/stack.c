#include <stdio.h>
#include <stdlib.h>

// PILHA (STACK)
typedef struct no {
	int key;
	no *next;
} no;

no *head = NULL;

void inserir(int key) // push
{
	no *novo = (no*) malloc(sizeof(no));
	novo->key = key;
	novo->next = NULL;
	if(!head) { head = novo; }
	else {
		novo->next = head;
		head = novo;
	}
	
}

void imprimir(){
	if(head){ //se a pilha existe
		no *temp;
		for(temp=head; temp; temp=temp->next){
			printf("%d\n", temp->key);
		}
		printf("\n");
	}else printf("VAZIA\n");
}

void deletar_primeiro_elemento() { // pop (erase)
	if(head) {
		no *temp = head->next;
		free(head);
		head = temp;
	}
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