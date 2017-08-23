#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	while (n!=1){
		std::cout<<n<<" ";
		if (n%2==0){
			n = n/2;
		} else {
			n = 3*n+1;
		}
	}
	std::cout<<n<<std::endl;
	return 0;
}
