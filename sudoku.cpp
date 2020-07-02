#include <iostream>
#include <cstdlib>
#include <ctime>


const int row=9;
const int column=9;
int board[row][column]={0};

void ilk() {
	int x=10;
	while(x--) {
		board[rand()%8+0][rand()%8+0] = rand()%9+1;
	}
}

void point() {
	int x,y;
	std::cout<<"\nSatir ve sutun sec: ";
	std::cin>>x>>y;

	int number;
	std::cout<<"\nSayi sec: ";
	std::cin>>number;
	board[x-1][y-1] = number;
}

void print() {
	std::cout<<"\n";
	for(int i=0;i<row;i++) {
		for(int j=0;j<column;j++) {
			std::cout<<board[i][j]<<"   ";
		}
		std::cout<<"\n\n";
	}
	std::cout<<"\n";
}

void ctrlColumn() {
	int y=0;
        int x=1;
        int z=0;
        while(z != 9) {
                while(x != 9) {
                        for(int i=0;i<row;i++) {
                                if(board[i][z] == x) {
                                        y++;
                                        if(y>1) {
                                                std::cout<<"\nhatali.\n";
                                        }
                                }
                        }
                        y=0;
                        x++;
                }
                z++;
                x=1;
        }
}


void ctrlRow() {
	int y=0;
	int x=1;
	int z=0;
	while(z != 9) {
		while(x != 9) {
			for(int i=0;i<row;i++) {
				if(board[z][i] == x) {
					y++;
					if(y>1) {
						std::cout<<"\nhatali.\n";
					}
				}
			}
			y=0;
			x++;
		}
		z++;
		x=1;
	}
}

int main() {
	srand(time(NULL));
	ilk();

	while(1) {
		print();
		point();
		//system("clear");
		ctrlRow();
		ctrlColumn();
	}
}

