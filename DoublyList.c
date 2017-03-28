#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *next,*prev;
}tnodo, *ptrNodo;

typedef struct{
	ptrNodo top,tail;
}DoublyList;

ptrNodo crearNodo(int n){
	ptrNodo new = (ptrNodo) malloc(sizeof(tnodo));
	new->num=n;
	new->next = NULL;
	new->prev=NULL;
	
	return new;
}

int isEmpty(DoublyList lista){
	return lista.top==NULL;
}

DoublyList insertTop(DoublyList lista, int n){
	ptrNodo nuevo = crearNodo(n);
	if(isEmpty(lista)){
		lista.top=nuevo;
		lista.tail=nuevo;
	}
	else{
		nuevo->prev=lista.top;
		lista.top->next=nuevo;
		lista.top=nuevo;
	}
	return lista;
}

void imprimir(DoublyList lista){
	while(lista.top!=NULL){
		printf("%d\t",lista.top->num);
		lista.top=lista.top->next;
	}
}

void imprimirReversa(DoublyList lista){
	while(lista.tail!=NULL){
		printf("%d\t",lista.tail->num);
		lista.tail=lista.tail->prev;
	}
}

int main(){
	int x;
	DoublyList lista;
	
	lista.top=NULL;
	lista.tail=NULL;

	while(scanf("%d",&x) && x!=0){
		lista=insertTop(lista, x);
	}
	
	imprimir(lista);
	imprimirReversa(lista);
	
	return 0;
}
