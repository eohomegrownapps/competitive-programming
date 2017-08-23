#include <iostream>

long gcd(long a,long b){
	if (b==0){
		return a;
	}
	return gcd(b,a%b);
}

int main(int argc, char const *argv[])
{
	long m,n;
	std::cin>>m>>n;
	if (m<n){
		long temp = n;
		n = m;
		m = temp;
	}
	std::cout<<gcd(m,n)<<std::endl;
	return 0;
}