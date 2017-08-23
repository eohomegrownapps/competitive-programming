#include <iostream>

int main(int argc, char const *argv[])
{
	int x;
	std::cin>>x;
	int i;
	for (i = 1; i<x; i++){
		std::cout<<i*i<<" ";
	}
	std::cout<<i*i<<std::endl;
	return 0;
}