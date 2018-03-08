//MINHEAP -> ordena 10 numeros

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;

int tree[maxn];

int sz = 0;


int getParent(int index){
	
	return(index-1)/2;
}

int getLeftChild(int index){
	
	return (index*2) + 1;
}

int getRightChild(int index){
	
	return(index*2)+2;
}

bool hasParent(int index){
	return getParent(index) >= 0;
}

bool hasLeftChild(int index){
	return getLeftChild(index) < sz;
}

bool hasRightChild(int index){
	return getRightChild(index) < sz;
}



void getMin(){
	
	if(sz == 0)
		printf("Esta vacio\n");
	else
		printf("%d\n",tree[0]);
	
}

void swap(int parent, int child){
	int temp = tree[parent];
	tree[parent]= tree[child];
	tree[child] = temp;
	
}

void insert(int value){
	int index = sz;
	tree[sz] = value;
	
	while(hasParent(index)){
		
		if(tree[getParent(index)] > tree[index]){
			swap(getParent(index),index);
			index = getParent(index);
		}else{
			break;
		}
	}
	++sz;
}

int erase(){
	int temp = tree[0], index = 0, minChild;
	tree[0] = tree[--sz];
	
	while(hasLeftChild(index)){
		minChild = getLeftChild(index);
		if(hasRightChild(index) && tree[getRightChild(index)] < tree[minChild])
			minChild = getRightChild(index);
		if(tree[minChild] < tree[index]){
				swap(index,minChild);
		} else{
		break;
		}	
		index = minChild;
	}	
	return temp;
}

int main(){
	
	int num;
	
		for(int i=0; i<10; i++){
			scanf("%d",&num);
			insert(num);
		}
		
		while(sz != 0){
			printf("%d\n",erase());
		}
	
	
	
	return 0;
}
