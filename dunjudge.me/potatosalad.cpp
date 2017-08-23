#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char const *argv[])
{
	long n,d;
	std::cin>>n>>d;
	std::vector<long> v;
	long temp;
	for (long i = 0; i<n; i++){
		std::cin>>temp;
		v.push_back(temp);
	}
	std::sort(v.begin(), v.end());
	std::reverse(v.begin(), v.end());
	long sum = 0;
	for (long j = 0; j<d; j++){
		sum += v[j];
	}
	std::cout<<sum<<std::endl;
	return 0;
}