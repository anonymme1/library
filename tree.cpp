#include <iostream>
#include <cstdlib>

typedef struct n {
	int data;
	n * left;
	n * right;
}node;

node *push(node *a, int x) {
	static int sayac = 0;
	if(a == NULL) {
		node *r;
		r = (node*)malloc(sizeof(node));
		r->data = x;
		r->left = NULL;
		r->right = NULL;
		return r;
	}
	if(a->data < x) {
		a->right = push(a->right, x);
		sayac++;
		return a;
	}
	a->left = push(a->left, x);
	sayac++;
	//std::cout<<"\nEkleme: "<<sayac<<"\n\n";
	return a;
}


void print(node *a) {
	static int sayac=0;
	if(a == NULL) {
		return;
	}
	print(a->left);
	sayac++;
	std::cout<<a->data<<"  ";
	print(a->right);
	sayac++;
	//std::cout<<"\nBastirma: "<<sayac<<"\n\n";
}

int search(node *a, int x) {
	if(a == NULL)
		return -1;
	if(a->data == x)
		return 1;
	if(search(a->right,x) == 1)
		return 1;
	if(search(a->left,x) == 1)
		return 1;
	return -1;
}

void max(node *a) {
	while(a->right != NULL)
		a = a->right;
	std::cout<<"\nMax value: "<<a->data<<"\n";
}

void min(node *a) {
	while(a->left != NULL)
		a = a->left;
	std::cout<<"\nMin value: "<<a->data<<"\n";
}



int main() {
	srand(time(NULL));
	node *tree;
	tree = NULL;

	for(int i=0;i<10;i++) {
		tree = push(tree, rand()%99+1);
	}

	print(tree);
	std::cout<<"\n";
	std::cout<<search(tree, 25)<<"\n";
	max(tree);
	min(tree);
	return 0;

}
