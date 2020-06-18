#include <iostream>
#include <cstdlib>
#include "nodeplus.h"


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
