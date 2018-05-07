#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int key;
	no *next;
} no;

no *head = NULL, *aux;

void inserir(int key)
{
	no *novo = (no*) malloc(sizeof(no));
	novo->key = key;
	novo->next = NULL;
	if(!head) { aux = head = novo; }
	else {
		aux->next = novo;
		aux = aux->next;
	}
	novo->next = head;
}

// void imprimir()
// {
// 	if(!head) { printf("VAZIA!\n"); return; }
// 	no *temp = head;
// 	do {
// 		printf("%d ",temp->key);
// 		temp = temp->next;
// 	} while(temp != head);
// 	printf("\n");
// }

void imprimir_marcela(){
	if(!head) return;
	no *temp;
	printf("%d ", head->key); //imprimindo o primeiro elemento
	for(temp = head->next; temp!=head; temp=temp->next){ //quando chegar em HEAD, para.
		printf("%d ", temp->key);	
	}
}

int main() {
	int i;
	for(i=0; i<10; i++){
		inserir(i);
	}
	imprimir_marcela();
	return 0;
}