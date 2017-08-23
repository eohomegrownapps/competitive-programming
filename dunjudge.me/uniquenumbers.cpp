#include <iostream>
#include <algorithm>
#include <vector>

long duplicates(std::vector<long> nums){
	std::sort(nums.begin(), nums.end());
	nums.resize(std::distance(nums.begin(),std::unique(nums.begin(), nums.end())));
	return nums.size();
}

int main(int argc, char const *argv[])
{
	long n;
	std::vector<long> v;
	std::cin>>n;
	long t;
	for (long i = 0; i<n; i++){
		std::cin>>t;
		v.push_back(t);
	}
	std::cout<<duplicates(v)<<std::endl;
	return 0;
}