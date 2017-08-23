#include <iostream>

void printline(int spaces, int x){
	for (int i = 0; i<spaces; i++){
		std::cout<<" ";
	}
	for (int j = 0; j<x; j++){
		std::cout<<"x";
	}
	std::cout<<std::endl;
}

int main(int argc, char const *argv[])
{
	int side;
	std::cin>>side;
	int count = side;
	for (int i = side-1; i>-1; i--){
		printline(i,count);
		count+=2;
	}
	count-=4;
	for (int j = 1; j<side; j++){
		printline(j,count);
		count-=2;
	}
	return 0;
}