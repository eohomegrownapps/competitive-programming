#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	char c;
	int b;
	std::cin>>n;
	for (int i = 0; i<n; i++){
		std::cin>>c;
		b = c;
		std::cout<<b<<std::endl;
	}
	return 0;
}