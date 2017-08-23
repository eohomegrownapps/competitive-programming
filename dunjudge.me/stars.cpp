#include <iostream>

int main(int argc, char const *argv[])
{
	long a, b, x;
	std::cin>>a>>b;
	x = a*b;
	char c;
	long stars = 0;
	for (long i = 0; i<x; i++){
		std::cin>>c;
		if (c=='*'){
			stars += 1;
		}
	}
	std::cout<<stars<<std::endl;
	return 0;
}