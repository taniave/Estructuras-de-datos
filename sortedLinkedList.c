//sorted linked list

//Programa que ordena con selection sort numeros en una lista ligada simple


#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int num;
	struct nodo *next;
}tnodo, *ptrNodo;

ptrNodo MakeNodo(int);
ptrNodo insert(ptrNodo,int);
void printList(ptrNodo);

ptrNodo MakeNodo (int n){// crea nodo
	ptrNodo new = (ptrNodo) malloc(sizeof(tnodo));
	new -> num = n;
	new -> next = NULL;
	return new;
}
 
ptrNodo insert (ptrNodo top, int n){//inserta dato en la lista
	ptrNodo temp, curr, new;
	new = MakeNodo(n);
	curr = top;
	temp = NULL;
	while(curr != NULL && new -> num > curr ->num){
		temp = curr;
		curr = curr -> next;
	}

	if(temp == NULL){
		new -> next = top;
		return new;
	}
	else{
		temp -> next = new;
		new -> next = curr;
		return top;
	}
}

void printList (ptrNodo top){ // recorre la lista e imprime
	while(top!=NULL){
		printf("%d\n",top-> num );
		top = top -> next;
	}
}

int main(){
	ptrNodo top = NULL;
	int numero;

	while(scanf("%d",&numero) && numero !=0){
		top = insert(top,numero);
	}
	printList(top);
	return 0;
}