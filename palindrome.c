#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nodo {
	char ch;
	struct nodo *next;
}Nodo, *ptrNodo;

ptrNodo getCadena(){
	ptrNodo top = NULL, tail, new;
	char c;
	c = getchar();

	while(c != '\n'){
		if(isalpha(c)){
			new = (ptrNodo) malloc(sizeof(Nodo));
			new -> ch = c;
			new -> next = NULL;
			if(top == NULL)
				top = new;
			else
				tail -> next = new;
			tail = new;
		}
		c = getchar();
	}
	return top;
}

ptrNodo reverse (ptrNodo lista){
	ptrNodo top = NULL, new;
	while(lista != NULL){
		new = (ptrNodo) malloc(sizeof(Nodo));
		new -> ch = lista -> ch;
		new -> next = top;
		top = new;
		lista = lista -> next;
	}	
	return top;
}

void printLista(ptrNodo top){
	while (top != NULL){
		printf("%c",top -> ch);
		top = top -> next;
	}
	printf("\n");
}

int compare(ptr Nodo lista1, ptrNodo Lista2){
	while(lista != NULL){
		if(lista1 -> ch != lista2 ->ch)
			return 0;
		lista1=lista1->next;
		lista2=lista2->next;
	}
	return 1;
}


int main(){
	ptrNodo lista1, lista2;

	lista1 = getCadena();
	lista2 = reverse(lista1);

	printLista(lista1); 
	printLista(lista2);

	(compare(lista1, lista2)) ? printf("yes\n") : printf("no\n");

return 0;
}