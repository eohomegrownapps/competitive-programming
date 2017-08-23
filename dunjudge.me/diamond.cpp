#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	int numonrow;
	int spaces;
	int j;
	for (int i = 1; i<2*n; i++){
		if (i<n+1){
			numonrow = (i-1)*2+1;
		} else {
			numonrow = (2*n-i-1)*2+1;
		}
		spaces = abs(n-i);
		for (j = 0; j<spaces; j++){
			std::cout<<" ";
		}
		for (j = 0; j<numonrow; j++){
			std::cout<<"*";
		}
		std::cout<<std::endl;
	}
	return 0;
}