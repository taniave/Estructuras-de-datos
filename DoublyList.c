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
	new->next = NULL;
	new->prev=NULL;
	new->num=n;
	return new;
}

int isEmpty(DoublyList lista){
	return lista.top==NULL;
}

DoublyList agregarTop(DoublyList lista, int n){
	ptrNodo nuevo = crearNodo(n);
	if(isEMpty(lista)){
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
		printf("%d",lista.top->num);
		lista.top=lista.top->next;
	}
}

void imprimirReversa(DoublyList lista){
	while(lista.tail!=NULL){
		pritnf("%d",lista.tail->num);
		lista.tail=lista.tail->prev;
	}
}

int main(){
	int x;
	DoublyList lista;
	
	lista.top=NULL;
	lista.tail=NULL;
	//scanf("%d",&x);
	while(scanf("%d",&x) && x!=0){
		lista=insertarTop(lista, x);
	}
	
	imprimir(lista);
	imprimirReversa(lista);
	
	return 0;
}
