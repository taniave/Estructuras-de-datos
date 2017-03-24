#include <stdio.h>
#include <stdlib.h>

/*
 	TC:
 	5 7 = 4
 	6 4 = 5
 	4 2 = 1
*/

typedef struct nodo{
	int num;
	struct nodo *next;
}tnodo, *ptrNodo;

ptrNodo MakeNodo(int n){
	ptrNodo new = (ptrNodo)malloc(sizeof(tnodo));
	new->num = n;
	new->next=NULL;
	return new;
}

ptrNodo circleList (int canguros){
	ptrNodo first, new;
	int i;
	first = new = MakeNodo(1);
	for(i=2; i<=canguros; i++){
		new -> next = MakeNodo(i);
		new = new->next;
	}
	new -> next = first;
	return first;
}

ptrNodo playGame (ptrNodo first, int m,int n){
	int i,j;
	ptrNodo curr = first, temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<m-1;j++){
			temp=curr;
			curr=curr->next;
		}
			temp->next=curr->next;
			free(curr);
			curr=temp->next;
	}
	return curr;
}



int main(){
int canguros,iteraciones;
 ptrNodo first;

 printf("Ingresar numero de canguros e iteraciones: ");
 scanf("%d %d",&canguros,&iteraciones);

 first = circleList(canguros);
 first = playGame(first, iteraciones, canguros);
 printf("Ganador: %d\n",first-> num);

	return 0;
}