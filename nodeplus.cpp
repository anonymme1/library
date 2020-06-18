#include <iostream>
#include <cstdlib>
#include "nodeplus.h"
/*
typedef struct linked {
	int data;
	linked * next;
}node;
*/

void print(node *a) {
	int i=1;
	while(a != NULL) {
		std::cout<<i++<<". deger: "<<a->data<<std::endl;
		a = a->next;
	}
}

node *del(node *a, int b) {
        node *temp;
        node *iter = a;
        while(iter->next != NULL && iter->next->data != b) {
                iter = iter->next;
        }

        if(iter->next==NULL) {
                return a;
        }

        temp = iter->next;
        iter->next = iter->next->next;
        free(temp);
        return a;
}


void addEnd(node *a,int n) {
	if(a == NULL) {
		a = (node*)malloc(sizeof(node));
		a->next = NULL;
		a->data = n;
	}
	while(a->next != NULL) {
		a = a->next;
	}
	a->next = (node*)malloc(sizeof(node));
	a->next->data = n;
	a->next->next = NULL;
}

node *addSmall(node *a, int n) {
	if(a==NULL) {
		a = (node*)malloc(sizeof(node));
		a->next = NULL;
		a->data = n;
		return a;
	}
	if(a->data > n) {
		node * temp = (node*)malloc(sizeof(node));
		temp->data = n;
		temp->next = a;
		return temp;
	}
	node *iter = a;
	while(iter->next != NULL && iter->next->data < n) {
		iter = iter->next;
	}
	node *temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	temp->data = n;
	iter->next = temp;
	return a;
}

node *addBig(node *a, int n) {
        if(a==NULL) {
                a = (node*)malloc(sizeof(node));
                a->next = NULL;
                a->data = n;
                return a;
        }
        if(a->data < n) {
                node * temp = (node*)malloc(sizeof(node));
                temp->data = n;
                temp->next = a;
                return temp;
        }
        node *iter = a;
        while(iter->next != NULL && iter->next->data > n) {
                iter = iter->next;
        }
        node *temp = (node*)malloc(sizeof(node));
        temp->next = iter->next;
        temp->data = n;
        iter->next = temp;
        return a;
}


void menu() {
	std::cout<<"\nNormal ekleme  : 1";
	std::cout<<"\nKucukten ekleme: 2";
	std::cout<<"\nBuyukten ekleme: 3";
	std::cout<<"\nEleman silme   : 4";
	std::cout<<"\nListeleme      : 5";
	std::cout<<"\nSonlandirma    : 6\n";
}
/*
int main() {
	srand(time(NULL));
	node *root;
	root = NULL;
	node *iter;
	iter = root;

	int islem;
	int bitch;
	while(1) {
		menu();
		std::cout<<"\n\nİslem sec: ";
		std::cin>>islem;
		switch(islem) {
			case 1:
				iter = root;
				std::cout<<"\nSayi: ";
				std::cin>>bitch;
				addEnd(iter,bitch);
				break;
			case 2:
				std::cout<<"\nSayi: ";
				std::cin>>bitch;
				root = addSmall(root, bitch);
				break;
			case 3:
				std::cout<<"\nSayi: ";
				std::cin>>bitch;
				root = addBig(root,bitch);
				break;
			case 4:
				iter = root;
				std::cout<<"\nSayi: ";
				std::cin>>bitch;
				del(iter, bitch);
				break;
			case 5:
				print(root);
				break;
			case 6:
				exit(1);
				break;
			default:
				std::cout<<"\nHatali islem.\n";
		}
	}
}
*/
