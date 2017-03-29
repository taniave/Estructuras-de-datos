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

int isFull(DoublyList lista){
	return lista.tail==NULL;
}

DoublyList insertTop(DoublyList lista, int n){
	
	ptrNodo new = crearNodo(n);
	if(isEmpty(lista)){
		lista.top=new;
		lista.tail=new;
	}
	else{
		new->next=lista.top;
		lista.top->prev=new;
		lista.top=new;
	}
	return lista;
}

DoublyList insertTail(DoublyList lista, int n){
	
	ptrNodo new = crearNodo(n);
	if(isFull(lista)){
		lista.top=NULL;
		lista.tail=new;
	}
	else{
		new->next=lista.tail;
		lista.tail->prev=new;
		lista.tail=new;
	}
	return lista;
}

void imprimirReversa(DoublyList lista){
	printf("LISTA A LA INVERSA:\n");
	while(lista.top!=NULL){
		printf(" %d ",lista.top->num);
		lista.top=lista.top->next;
	}
	printf("\n");
}

void imprimir(DoublyList lista){
	printf("LISTA COMO FUE INGRESADA:\n");
	while(lista.tail!=NULL){
		printf(" %d ",lista.tail->num);
		lista.tail=lista.tail->prev;
	}printf("\n");
}

int main(){
	int x;
	DoublyList lista;
	
	lista.top=NULL;
	lista.tail=NULL;

	while(scanf("%d",&x) && x!=0){
		//lista=insertTail(lista,x);
			if(lista.top == NULL){
				lista=insertTop(lista, x);
			}
			else
				lista=insertTail(lista,x);
				
	}
	
	imprimir(lista);
	imprimirReversa(lista);
	
	return 0;
}
