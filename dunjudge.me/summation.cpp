#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	long temp;
	long total = 0;
	for (int i = 0; i<n; i++){
		std::cin>>temp;
		total += std::abs(temp);
	}
	std::cout<<total<<std::endl;
	return 0;
}