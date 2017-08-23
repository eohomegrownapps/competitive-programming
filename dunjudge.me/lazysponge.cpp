#include <iostream>

int main(int argc, char const *argv[])
{
	int n, x, temp;
	std::cin>>n>>x;
	for (int i = 1; i<n+1; i++){
		std::cin>>temp;
		if (i == x){
			std::cout<<temp<<std::endl;
		}
	}
	return 0;
}