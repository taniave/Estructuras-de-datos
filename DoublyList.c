#include <stdio.h>
#include <stdlib.h>

typedef struct nodo 
{
	int num;
	struct nodo *next,*prev;
} tnodo, *ptrNodo;


typedef struct  {
	ptrNodo top, tail;
} DoublyList;


 ptrNodo crearNodo(int n){
 	ptrNodo new = (ptrNodo) malloc(sizeof(tnodo));
 	new->num=n;
 	new->next = NULL;
 	new->prev=NULL;
 	return new;
 }

 DoublyList agregarTop(DoublyList lista, int n){
 	ptrNodo new = crearNodo(n);
 	
 	if(isEmpty(lista)==1){
 		lista.top=lista.tail=new;
 	}
 	else{
 		new->prev=lista.top;
 		top->next=new;
 		top=new; 
 	}
 	return lista;
 }

 int isEmpty(DoublyList lista){
 	if(lista.top==NULL){
 		return 1;
 	}
 	else
 		return 0;
 }

 int main(){
 	int x;
 	DoublyList lista;
 	//leer numeros hasta que se ingrese 0
 	lista.top=lista.tail=NULL;
 	while(scanf("%d",&x) && x!=0){
 		
 	}


 	return 0;
 }