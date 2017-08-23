#include <iostream>

int main(int argc, char const *argv[])
{
	int h,w,n;
	std::cin>>h>>w>>n;
	int counter = 0;
	for (int i = 0; i<h; i++){
		for (int j = 0; j<w; j++){
			if (counter<n){
				std::cout<<'X';
				counter++;
			} else {
				std::cout<<'O';
			}
		}
		std::cout<<std::endl;
	}
	return 0;
}