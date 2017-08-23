#include <iostream>

int main(int argc, char const *argv[])
{
	int i;
	std::cin>>i;
	long sum = 0;
	long temp;
	for (int j = 0; j<i; j++){
		std::cin>>temp;
		sum += temp;
	}
	std::cout<<sum<<std::endl;
	return 0;
}