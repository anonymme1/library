#include <iostream>

int main() {
	int sayi;
	int hex[8];
	int i=0;
	char hexValue[17] = "0123456789ABCDEF";

	std::cout<<"\nSayi gir: ";
	std::cin>>sayi;

	while(sayi>15) {
		hex[i++] = sayi%16;
		sayi /= 16;
	}

	hex[i] = sayi;

	std::cout<<"\nHexdecimal sayi : ";
	while(i>=0) {
		std::cout<<hexValue[hex[i--]];
	}

	std::cout<<"\n";

	std::cout<<sizeof(hexValue);
}
