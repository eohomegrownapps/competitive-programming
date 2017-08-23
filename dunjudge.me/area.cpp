#include <iostream>

int main(int argc, char const *argv[])
{
	long properties;
	int sidea, sideb;
	long long totalarea = 0;
	std::cin>>properties;
	for (long i = 0; i<properties; i++){
		std::cin>>sidea>>sideb;
		totalarea+=sidea*sideb;
	}
	std::cout<<totalarea<<std::endl;
	return 0;
}