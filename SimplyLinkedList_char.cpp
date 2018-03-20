#include <bits/stdc++.h>

typedef struct nodo{
	char letra;
	struct nodo *sig=NULL;
}tnodo,*ptrNodo;

ptrNodo create(char dato){
	ptrNodo nuevo = (ptrNodo) malloc(sizeof(tnodo));
	
	nuevo->letra=dato;
	nuevo->sig=NULL;
	
	return nuevo;
}

ptrNodo insert(ptrNodo raiz, char dato){
  ptrNodo nuevo,last;
	
	if(raiz == NULL){
		nuevo = create(dato);
		raiz = nuevo;
		raiz -> letra = dato;
		raiz -> sig = NULL;
		last = raiz;	
	}
	else{
		nuevo = create(dato);
		nuevo -> letra = dato;
		last -> sig = nuevo;
		nuevo -> sig = NULL;
		last = nuevo;
	}
	return raiz;
	}

void printList(ptrNodo raiz){
	while(raiz != NULL){
		printf("%c",raiz -> letra);
		raiz = raiz->sig;
	}
	
}

/*char deleteNode(ptrNodo raiz){
	
	ptrNodo remueve;
	char dato;
	if(raiz != NULL){
		
		remueve = raiz;
		raiz = raiz -> sig; //raiz= remueve->sig;
		dato = remueve -> letra;
		free(remueve);
		return dato;
	}
}*/

/*void deleteNode(ptrNodo raiz){
	ptrNodo del;
	del = raiz;
	raiz = del -> sig;
	printf("DATO ELIMINADO: %c\n",del->letra);
	free(del);
}*/

int main(){
	ptrNodo raiz = NULL;
	
	char dato,i;
	
	while(scanf("%c",&dato) && dato != '0'){
		raiz=insert(raiz,dato);
	}
	
	printList(raiz);
	printf("\n");
	//i=deleteNode(raiz);
	//printList(raiz);
	
	return 0;
}



/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	char letra;
	struct nodo *sig;	
}*raiz = NULL, *last = NULL;

nodo insert(struct nodo *raiz,char dato){
  struct nodo *nuevo;
	
	if(raiz == NULL){
		nuevo = (struct nodo*) malloc(sizeof(struct nodo));
		raiz = nuevo;
		raiz -> letra = dato;
		raiz -> sig = NULL;
		last = raiz;	
	}
	else{
		nuevo = (struct nodo*) malloc(sizeof(struct nodo));
		nuevo -> letra = dato;
		last -> sig = nuevo;
		nuevo -> sig = NULL;
		last = nuevo;
	}
	return raiz;
}

void deleteNode(){
	struct nodo *del;
	del = raiz;
	raiz = del -> sig;
	printf("DATO ELIMINADO: %c\n",del->letra);
	free(del);
}

void printList(struct nodo *raiz){
	struct nodo *aux;
	aux = raiz;
	
	printf("CARACTERES: \n");	
	while(aux != NULL){
		printf("%c\n",aux->letra);
		aux = aux->sig;
	}
	
}

int main(){
	char car;
	//struct nodo *raiz = NULL;
	
	while(scanf("%c",&car) && car != '0'){
		insert(raiz,car);
	}
	
	//deleteNode();
	printList(raiz);
	
	
	return 0;
}*/
