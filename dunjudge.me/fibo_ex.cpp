#include <iostream>

long long fibo(long long n, long long m){
	if (n==1){
		return 1;
	}
	long long a = 1;
	long long b = 1;
	long long temp;
	for (long long i = 2; i<n; i++){
		temp = b;
		b = (a+b)%m;
		a = temp;
	}
	return b;
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	long long a,b;
	for (int i = 0; i<n; i++){
		std::cin>>a>>b;
		std::cout<<fibo(a,b)<<std::endl;
	}
	return 0;
}