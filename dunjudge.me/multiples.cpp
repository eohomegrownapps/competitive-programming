#include <iostream>

int main(int argc, char const *argv[])
{
	long n,m;
	std::cin>>n>>m;
	for (long i = 1; i<m+1; i++){
		std::cout<<n*i<<std::endl;
	}
	return 0;
}