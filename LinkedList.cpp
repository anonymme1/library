#include <iostream>
#include <cstdlib>

typedef struct linked {
	int data;
	std::string ad;
	std::string soyad;
	linked * next;
}node;


void print(node *a) {
	int i=1;
	while(a != NULL) {
		std::cout<<i++<<". Kisi: "<<std::endl;
		std::cout<<"\tisim   : "<<a->ad<<"\n";
		std::cout<<"\tSoyisim: "<<a->soyad<<"\n";
		std::cout<<"\tNumara : "<<a->data<<"\n";
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

bool addTo(node *a, int no, std::string name, std::string surname) {
	int x;
	std::cout<<"\nHangisinden once konulsun: ";
	std::cin>>x;
	node *iter = a;
	if(iter == NULL) {
		std::cout<<"\nListe bos.\n";
		return false;
	}

	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = no;
	temp->ad = name;
	temp->soyad = surname;

	while(iter->next->data != x) {
		iter = iter->next;
	}

	temp->next = iter->next;
	iter->next = temp;
	return true;
}

node *addSmall(node *a, int no, std::string name, std::string surname) {
	if(a==NULL) {
		a = (node*)malloc(sizeof(node));
		a->next = NULL;
		a->data = no;
		a->ad = name;
		a->soyad = surname;
		return a;
	}
	if(a->data > no) {
		node * temp = (node*)malloc(sizeof(node));
		temp->data = no;
		temp->ad = name;
		temp->soyad = surname;
		temp->next = a;
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
}


void menu() {
	std::cout<<"\nNormal ekleme  : 1";
	std::cout<<"\nAraya  ekleme  : 2";
	std::cout<<"\nEleman silme   : 3";
	std::cout<<"\nListeleme      : 4";
	std::cout<<"\nSonlandirma    : 5\n";
}

int main() {
	srand(time(NULL));
	int eleman,islem;
	node *root;
	root = NULL;
	node *iter;
	while(1) {
		menu();
		std::cout<<"\nislem sec: ";
		std::cin>>islem;
		switch(islem) {
			case 1:
				root = addSmall(root, rand()%99+1, "jdjdj", "jdjjd");
				break;
			case 2:
				iter = root;
				addTo(iter, rand()%99+1,"jdjdj","jdjdj");
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

