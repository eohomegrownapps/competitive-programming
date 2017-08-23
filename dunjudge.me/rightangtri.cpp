#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	for (int i = 1; i<n+1; i++){
		for (int j = 1; j<i+1; j++){
			std::cout<<"*";
		}
		std::cout<<std::endl;
	}
	return 0;
}