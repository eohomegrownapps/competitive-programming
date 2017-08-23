#include <iostream>
#include <cmath>

bool isPrime(long n){
	if ((n%2==0&&n!=2)||n<2){
		return false;
	}
	for (int i = 3; i<std::sqrt(n)+1; i+=2){
		if (n%i==0){
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i<4; i++){
		long n;
		std::cin>>n;
		if (!isPrime(n)){
			std::cout<<"Wrong code"<<std::endl;
			return 0;
		}
	}
	std::cout<<"Opening..."<<std::endl;
	return 0;
}