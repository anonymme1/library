#include <iostream>

int *arr = new int[2];
arr = NULL;
int size = 2;
int _return = 0;

void push(int a) {
	if(arr == NULL) {
		arr = new int[size];
	}
	if(_return >= size) {
		int *newArr = new int[size*2];
		for(int i=0;i<size;i++)
			newArr[i] = arr[i];

		delete [] arr;
		arr = newArr;
		size *= 2;
	}

	arr[_return++] = a;
}


bool pop(int a) {
	if(arr == NULL) {
		std::cout<<"\nArray is NULL\n";
		return false;
	}

	if(_return <= size/4) {
		int *newArr = new int[size/2];
		for(int i=0;i<size;i++) {
			if(arr[i] != 0)
				newArr[i] = arr[i];
		}
		delete [] arr;
		arr = newArr;
		size /= 2;
	}
	for(int i=0;i<size;i++) {
		if(arr[i] == a)
			arr[i] = 0;
	}
	_return--;
	return true;
}


bool print() {
	if(arr==NULL) {
		std::cout<<"\nArray is NULL.\n";
		return false;
	}
	for(int i=0;i<size;i++)
		std::cout<<arr[i]<<" , ";
	std::cout<<"\n";
	return true;
}

void menu() {
	std::cout<<"\nAdding value   > 1";
	std::cout<<"\nDeleting value > 2";
	std::cout<<"\nPrint array    > 3";
	std::cout<<"\nEXIT           > 4\n";
}


int main(int argc, char *argv[]) {
	int choice,value;
	while(1) {
		menu();
		std::cout<<"\nChoice: ";
		std::cin>>choice;
		switch(choice) {
			case 1:
				std::cout<<"\nValue: ";
				std::cin>>value;
				push(value);
				break;
			case 2:
				std::cout<<"\nValue: ";
				std::cin>>value;
				pop(value);
				break;
			case 3:
				std::cout<<"\n";
				print();
				break;
			case 4:
				std::cout<<"\nGood bye. :) \n";
				exit(1);
				break;
			default:
				std::cout<<"\nChoice is corrent.\n";
				break;
		}
	}
}
