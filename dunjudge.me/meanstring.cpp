#include <iostream>

int main(int argc, char const *argv[])
{
	int x = 0;
	std::cin>>x;
	int avg = 0;
	int temp = 0;
	for (int i = 0; i<x; i++){
		std::cin>>temp;
		avg += temp;
	}
	std::cout<<avg/x<<std::endl;
	return 0;
}