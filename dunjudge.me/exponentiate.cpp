#include <iostream>
long long exponentiate (long long a, long long b, long long m){
	if (b==1){
		return a%m;
	}
	else if (b%2==0){
		long long temp = exponentiate(a,b/2,m);
		return (temp*temp)%m;
	}
	else {
		long long temp = exponentiate(a,(b-1)/2,m);
		return (((temp*temp)%m)*a)%m;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	long long a,b,m;
	for (int i = 0; i<n; i++){
		std::cin>>a>>b>>m;
		std::cout<<exponentiate(a,b,m)<<std::endl;
	}
	return 0;
}