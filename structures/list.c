#include <stdio.h>
#include <stdlib.h>
//Lista simples
typedef struct no {
	int key;
	no *next;
} no;

no *head = NULL, *aux; //variaveis globais

void inserir(int key)
{
	no *novo = (no*) malloc(sizeof(no)); //malloc == alocar memoria
	novo->key = key;
	novo->next = NULL;
	if(!head) { aux = head = novo; }
	else {
		aux->next = novo;
		aux = aux->next;
		/*
		no* temp;
		for(temp = head; temp->next; temp = temp->next);
		temp->next = novo;
		*/
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

void deletar() {
	while(head) {
		no *temp = head->next;
		free(head);
		head = temp;
	}
}

no* busca(int key) {
	if(!head) return NULL;
	 no* temp;
	for(temp = head; temp; temp = temp->next) {
		if(temp->key == key) return temp;
	}
	return NULL;
}

void remover_no_meio(int key) {
	if(!head) return;
	if(head->key == key) {
		no *temp = head;
		head = head->next;
		free(temp);
	} else {
		no *temp;
		for(temp = head; temp->next; temp = temp->next) {
			if(temp->next->key == key) {
				no *temp2 = temp->next;
				temp->next = temp->next->next;
				free(temp2);
			}
		}
	}
	
}

int main() {
	// imprimir();
	inserir(1);
	// imprimir();
	inserir(2);
	// imprimir();
	inserir(3);
	// imprimir();
	inserir(4);
	// imprimir();

	printf("%p\n", busca(2));


	// deletar();
	return 0;
}