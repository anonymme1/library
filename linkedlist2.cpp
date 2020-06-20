#include <iostream>
#include <cstdlib>
#include <string.h>
#include <time.h>
typedef struct linked {
	int data;
	char ad[10];
	char soyad[10];
	linked * next;
}node;


void print(node *a) {
	int i=1;
	while(a->next != NULL) {
		std::cout<<i++<<". Kisi: "<<std::endl;
		std::cout<<"\tNumara : "<<a->data<<"\n";
		std::cout<<"\tisim   : "<<a->ad<<"\n";
		std::cout<<"\tsoyisim: "<<a->soyad<<"\n";
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

node * addTo(node *a, int no, char *name, char *surname) {
	int x;
	std::cout<<"\nHangisinden once konulsun: ";
	std::cin>>x;
	node *iter = a;
	if(iter == NULL) {
		std::cout<<"\nListe bos.\n";
		return a;
	}

	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = no;
	strcpy(temp->ad, name);
	strcpy(temp->soyad, surname);
	int flag = 0;
	node *swap = iter;
	while(swap->next != NULL) {
		if(swap->data == x) {
			flag = 1;
		}
		swap = swap->next;
	}

	if(flag == 0) {
		return a;
	}

	while(iter->next->data != x) {
		iter = iter->next;
	}

	temp->next = iter->next;
	iter->next = temp;
	return a;
}
/*
node *addSmall(node *a, int no, std::string name, std::string surname) {
	if(a==NULL) {
		a = (node*)malloc(sizeof(node));
		a->next = NULL;
		a->data = no;
		a->ad = name;
		a->soyad = surname;
		return a;
	}
	if(a->data < no) {
		node * temp = (node*)malloc(sizeof(node));
		temp->data = no;
		temp->ad = name;
		temp->soyad = surname;
		temp->next = NULL;
		return temp;
	}

	node *iter = a;
	while(iter->next != NULL && iter->next->data < no) {
		iter = iter->next;
	}
	node *temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	temp->data = no;
	temp->ad = name;
	temp->soyad = surname;
	iter->next = temp;
	return a;
}*/


void menu() {
	std::cout<<"\nNormal ekleme  : 1";
	std::cout<<"\nAraya  ekleme  : 2";
	std::cout<<"\nEleman silme   : 3";
	std::cout<<"\nListeleme      : 4";
	std::cout<<"\nSonlandirma    : 5\n";
}

node* add(node *a, int no, char *name, char *surname) {
	node *iter;
	iter = a;
	while(iter->next != NULL) {
		iter = iter->next;
	}
	iter->next = (node*)malloc(sizeof(node));
	iter->next->data = no;
	strcpy(iter->next->ad, name);
	strcpy(iter->next->soyad, surname);
	iter->next->next = NULL;
	return a;
}

int main() {
	srand(time(NULL));
	int eleman,islem;
	char isim[10]="Different";
	char soyisim[10] = "User";

	node *root;
	root = (node*)malloc(sizeof(node));
	strcpy(root->ad, isim);
	strcpy(root->soyad,soyisim);
	root->data = 1;
	root->next = NULL;
	node *iter;
	while(1) {
		menu();
		std::cout<<"\nislem sec: ";
		std::cin>>islem;
		switch(islem) {
			case 1:
				std::cout<<"\nİsim gir: ";
				std::cin>>isim;
				std::cout<<"\nSoyisim gir: ";
				std::cin>>soyisim;
				root = add(root, rand()%99+1,isim,soyisim);
				break;
			case 2:
				std::cout<<"\nİsim gir: ";
				std::cin>>isim;
				std::cout<<"\nSoyisim gir: ";
				std::cin>>soyisim;
				root = addTo(root, rand()%99+1,isim,soyisim);
				break;
			case 3:
				iter = root;
				print(root);
				std::cout<<"\nSilmek istedigin eleman: ";
				std::cin>>eleman;
				del(iter, eleman);
				break;
			case 4:
				print(root);
				break;
			case 5:
				exit(1);
				break;
			default:
				std::cout<<"\nBu islem yok.\n";
				break;
		}
	}
}

