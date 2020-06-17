#include <stdio.h>
#include <stdlib.h>

void tersYap(char *a) {

	int len = strlen(a)-1;

	for(int i=len;i>=0;i--)
		printf("%c",a[i]);
	printf("\n");
}

void sirala(int *a) {
	int temp;
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			if(a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main() {
	char kelime1[50],kelime2[50],kelime3[50],kelime4[50];


	printf("\n1. kelime: ");
	scanf("%s",kelime1);
	printf("\n2. kelime: ");
        scanf("%s",kelime2);
	printf("\n3. kelime: ");
        scanf("%s",kelime3);
	printf("\n4. kelime: ");
        scanf("%s",kelime4);

	char dizi[4];

	dizi[0] = kelime1[0];
	dizi[1] = kelime2[0];
	dizi[2] = kelime3[0];
	dizi[3] = kelime4[0];

	int dizi2[4];
	for(int i=0;i<4;i++)
		dizi2[i] = (int)dizi[i];

	sirala(dizi2);

	for(int i=0;i<4;i++)
		dizi[i] = (char)dizi2[i];

	printf("\n\n");

	for(int i=0;i<4;i++) {
		if(dizi[i] == kelime1[0]) {
			tersYap(kelime1);
		}
		else if(dizi[i] == kelime2[0]) {
			tersYap(kelime2);
		}
		else if(dizi[i] == kelime3[0]) {
			tersYap(kelime3);
		}
		else if(dizi[i] == kelime4[0]) {
			tersYap(kelime4);
		}
	}
}

