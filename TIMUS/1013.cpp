#include <iostream>

unsigned long long kbased(unsigned long long n, unsigned long long k){
	if (n==0){
		return 1;
	}
	unsigned long long arr[n][2];
	arr[0][0] = 0;
	arr[0][1] = k-1;
	std::cout<<"start";
	for (unsigned long long i = 1; i<n; i++){
		arr[i][0] = arr[i-1][1];
		arr[i][1] = (arr[i-1][0]+arr[i-1][1])*(k-1);
	}
	return arr[n-1][0]+arr[n-1][1];
}

int main(int argc, char const *argv[])
{
	unsigned long long n, k, m;
	std::cin>>n>>k>>m;
	unsigned long long div = n%m;
	std::cout<<kbased(div,k)<<std::endl;
	return 0;
}