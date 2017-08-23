#include <iostream>

int main(int argc, char const *argv[])
{
	long sum = 0;
	long temp;
	std::cin>>temp;
	while (temp!=-1){
		sum += temp;
		std::cin>>temp;
	}
	std::cout<<sum<<std::endl;
	return 0;
}