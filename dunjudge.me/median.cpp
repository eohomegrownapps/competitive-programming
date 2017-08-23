#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	int median = (n+1)/2;
	int temp;
	for (int i = 0; i<median; i++){
		std::cin>>temp;
	}
	std::cout<<temp<<std::endl;
	return 0;
}