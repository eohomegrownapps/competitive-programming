#include <iostream>
#include <cmath>
int main(int argc, char const *argv[])
{
	float a, b;
	std::cin>>a>>b;
	if (b>a){
		std::cout<<2<<std::endl;
	} else {
		std::cout<<int(std::ceil(2*a/b))<<std::endl;
	}
	return 0;
}