#include <iostream>
#include <vector>
#include <cmath>

bool isPrime(long n){
	if (n<2){
		return false;
	}
	long pointer = 2;
	long val = std::ceil(std::sqrt(n));
	for (int i = 2; i<val+1; i++){
		if (n%i==0 && n!=i){
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	long n;
	std::cin>>n;
	if (isPrime(n)==true){
		std::cout<<"Prime"<<std::endl;
	} else {
		std::cout<<"Not Prime"<<std::endl;
	}
	/* code */
	return 0;
}