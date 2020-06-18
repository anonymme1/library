#ifndef nodeplus
#define nodeplus

typedef struct linked {
	int data;
	linked * next;
}node;

void print(node*);
void addEnd(node*,int);
node *del(node*,int);
node *addSmall(node*,int);
node *addBig(node*,int);


#endif
