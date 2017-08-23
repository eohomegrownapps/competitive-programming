#include <iostream>

long kbased(long n, long k){
	long arr[n][2];
	arr[0][0] = 0;
	arr[0][1] = k-1;
	for (int i = 1; i<n; i++){
		arr[i][0] = arr[i-1][1];
		arr[i][1] = (arr[i-1][0]+arr[i-1][1])*(k-1);
	}
	return arr[n-1][0]+arr[n-1][1];
}

int main(int argc, char const *argv[])
{
	long n, k;
	std::cin>>n>>k;
	std::cout<<kbased(n,k)<<std::endl;
	return 0;
}