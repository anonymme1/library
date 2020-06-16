#include <iostream>
#include <cstdlib>
#include "stack_arr.h"

int *array=NULL;
int size=2;
int top=0;

int pop() {
	if(array==NULL) {
		std::cout<<"\nArray is NULL.\n";
		return -1;
	}

	if(top<=size/4) {
		int *dizi2 = (int*)malloc(sizeof(int)*size/2);
		for(int i=0;i<size;i++)
			dizi2[i] = array[i];
		free(array);
		array = dizi2;
		size /= 2;
	}
	return array[--top];
}



void push(int a) {
	if(array==NULL) {
		array = (int*)malloc(sizeof(int)*2);
	}

	if(top>=size) {
		int *dizi2 = (int*)malloc(sizeof(int)*size*2);
		for(int i=0;i<size;i++)
			dizi2[i] = array[i];
		free(array);
		array = dizi2;
		size *= 2;
	}
	array[top++] = a;
}


void print() {
	for(int i=0;i<top;i++) {
		std::cout<<array[i]<<"  ";
	}
}
